/***************************************************************************
 *   Copyright (C) 2008 by Oleg Khudyakov                                  *
 *   prcoder@gmail.com                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "hantekdsoathread.h"
#include <math.h>

HantekDSOAThread::HantekDSOAThread()
 : QThread(), bufferSize(BUFFER_SMALL/*BUFFER_LARGE*/), calData(0),
    triggerPoint(0), triggerMode(TRIGGER_MODE_AUTO), forceRestartCount(0), forceRestartCountMax(3),
    terminateFlag(false)
{
    setBufferSize(bufferSize);
    memset(buffer, 0, sizeof(buffer));
}

HantekDSOAThread::~HantekDSOAThread()
{
}

/*!
    \fn HantekDSOAThread::run()
 */
void HantekDSOAThread::run()
{
    while(!terminateFlag)
    {
        unsigned trPoint = 0;
        int captureState = dsoIO.dsoGetCaptureState(&trPoint);
        if (captureState < 0)
        {
            qDebug("Error in command GetCaptureState");
        }
//        qDebug("TriggerPoint=%06X, CaptureState=%i", trPoint, captureState);

        unsigned timeBase = dsoIO.dsoGetTimeBase();
        switch(captureState)
        {
            case CAPTURE_VALUE0:    // Buffer is empty
                if (forceRestartCount++ >= forceRestartCountMax)
                {
                    forceRestartCount = 0;
                    if (dsoIO.dsoCaptureStart() < 0)
                    {
                        qDebug("Error running CaptureStart command");
                    }
                    if (dsoIO.dsoTriggerEnabled() < 0)
                    {
                        qDebug("Error running TriggerEnabled command");
                    }
                    if (triggerMode == TRIGGER_MODE_AUTO)
                    {
                        if (dsoIO.dsoForceTrigger() < 0)
                        {
                            qDebug("Error running TriggerEnabled command");
                        }
                        qDebug("Trigger forced");
                    }
                }
                msleep(timeBase);
                break;

            case CAPTURE_VALUE1:    // Buffer is half-filled
                msleep(timeBase);
                break;

            case CAPTURE_SUCCESS:   // Buffer is filled
            case CAPTURE_VALUE7:    // Buffer is filled (DSO-5200X)
                bufferMutex.lock();
                triggerPoint = trPoint;
                if (dsoIO.dsoGetChannelData(buffer, bufferSize) < 0)
                {
                    bufferMutex.unlock();
                    qDebug("Error in command GetChannelData");
                }
                bufferMutex.unlock();

                if (dsoIO.dsoCaptureStart() < 0)
                {
                    qDebug("Error running CaptureStart command");
                }
                if (dsoIO.dsoTriggerEnabled() < 0)
                {
                    qDebug("Error running TriggerEnabled command");
                }

                if (triggerMode == TRIGGER_MODE_AUTO)
                {
                        if (dsoIO.dsoForceTrigger() < 0)
                        {
                            qDebug("Error running TriggerEnabled command");
                        }
                }
                break;

            default:
                qDebug("Unknown CaptureState=%i", captureState);
        }

        if (captureState != CAPTURE_VALUE0)
        {
            forceRestartCount = 0;
        }
    }
}

/*!
    \fn HantekDSOAThread::stop()
 */
void HantekDSOAThread::stop()
{
    terminateFlag = true;
}


/*!
    \fn HantekDSOAThread::setBufferSize(int bufferSize)
 */
void HantekDSOAThread::setBufferSize(unsigned bufferSize)
{
    this->bufferSize = bufferSize;
    transformSize = 1;
    while(bufferSize > 0)
    {
        bufferSize >>= 1;
        transformSize <<= 1;
    }
    transformSize >>= 1;

    // Calculate Hann window coefficients
    for(unsigned i = 0; i < transformSize; i++)
    {
        // Hann window
        windowCoeff[i] = 0.5 * (1.0 -
            cos( (2.0 * M_PI * (double)i) / (double)transformSize));
    }
}

/*!
    \fn HantekDSOAThread::setTriggerMode(int triggerMode)
 */
void HantekDSOAThread::setTriggerMode(int triggerMode)
{
    this->triggerMode = triggerMode;
}

/*!
    \fn HantekDSOAThread::getTriggerMode()
 */
int HantekDSOAThread::getTriggerMode()
{
    return triggerMode;
}

/*!
    \fn HantekDSOAThread::getCalData()
 */
void HantekDSOAThread::getCalData()
{
        if (dsoIO.dsoGetCalData(&calData) < 0)
        {
            qDebug("Error running GetCalData command");
        }
}

/*!
    \fn HantekDSOAThread::transform()
 */
void HantekDSOAThread::transform()
{
    for (int t=0; t < MAX_CHANNELS; t++)
    {
        // Apply Hann window
        for(unsigned i = 0; i < transformSize; i++)
        {
            fhtBuffer[t][i] *= windowCoeff[i];
        }
        fht.transform(fhtBuffer[t], transformSize, 1);
    }

    for (int t = 0; t < MAX_CHANNELS; t++)
    {
        double maxPower = 0;
        unsigned halfSize = transformSize/2;
        for (unsigned i = 0; i < halfSize; i++)
        {
            double power = sqrt(
                (fhtBuffer[t][transformSize-1-i]+fhtBuffer[t][i])*
                (fhtBuffer[t][transformSize-1-i]+fhtBuffer[t][i])+
                (fhtBuffer[t][transformSize-1-i]-fhtBuffer[t][i])*
                (fhtBuffer[t][transformSize-1-i]-fhtBuffer[t][i]));
            fhtBuffer[t][i] = power;
            if (power > maxPower)
            {
                maxPower = power;
            }
        }

        for (unsigned i = 0; i < halfSize; i++)
        {
//            fhtBuffer[t][i] = -10*log(fhtBuffer[t][i]/maxPower)/256;
            fhtBuffer[t][i] = 2*fhtBuffer[t][i]/maxPower;
        }
    }
}
