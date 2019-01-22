/***************************************************************************
 *   Copyright (C) 2008 by Oleg Khudyakov                                  *
 *   prcoder@potrebitel.ru                                                 *
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
 : QThread(), bufferSize(BUFFER_SMALL), triggerPoint(0)
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
    for(;;)
    {
        unsigned trPoint = 0;
        int rv = dsoIO.dsoGetCaptureState(&trPoint);
        if (rv < 0)
        {
            qDebug("Error in command GetCaptureState");
        }
//        qDebug("TriggerPoint=%06X, rv=%i", trPoint, rv);

        if (rv == CAPTURE_SUCCESS)
        {
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
/*
                if (dsoIO.dsoForceTrigger() < 0)
                {
                    qDebug("Error running TriggerEnabled command");
                }
*/
        }
        else if (rv == CAPTURE_VALUE1)
        {
        }
        else if (rv == CAPTURE_VALUE0)
        {
            if (dsoIO.dsoCaptureStart() < 0)
            {
                qDebug("Error running CaptureStart command");
            }

            if (dsoIO.dsoTriggerEnabled() < 0)
            {
                qDebug("Error running TriggerEnabled command");
            }
/*
            if (dsoIO.dsoForceTrigger() < 0)
            {
                qDebug("Error running TriggerEnabled command");
            }
*/
        }

        msleep(100);
    }
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

    for(unsigned i = 0; i < transformSize; i++)
    {
        // Hann window
        windowCoeff[i] = 0.5 * (1.0 -
            cos( (2.0 * M_PI * (double)i) / (double)transformSize));
    }
}


/*!
    \fn HantekDSOAThread::transform()
 */
void HantekDSOAThread::transform()
{
    for (int t=0; t < MAX_CHANNELS; t++)
    {
        for(unsigned i = 0; i < transformSize; i++)
        {
            fhtBuffer[t][i] *= windowCoeff[i];
        }
        fht.transform(fhtBuffer[t], transformSize, 1);
    }

    double totalPower[MAX_CHANNELS] = { 0, 0 };
    for (int t = 0; t < MAX_CHANNELS; t++)
    {
        for (unsigned i = 0; i < transformSize/2; i++)
        {
            double power = sqrt(
                (fhtBuffer[t][transformSize-1-i]+fhtBuffer[t][i])*
                (fhtBuffer[t][transformSize-1-i]+fhtBuffer[t][i])+
                (fhtBuffer[t][transformSize-1-i]-fhtBuffer[t][i])*
                (fhtBuffer[t][transformSize-1-i]-fhtBuffer[t][i]));
            fhtBuffer[t][i] = power;
            totalPower[t] += power;
        }
    }

    for (int t = 0; t < MAX_CHANNELS; t++)
    {
        for (unsigned i = 0; i < transformSize/2; i++)
        {
            fhtBuffer[t][i] = 160 + 10 * log(fhtBuffer[t][i]/totalPower[t]);
        }
    }
}
