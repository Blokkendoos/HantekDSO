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
#include <qlabel.h>
#include <qslider.h>
#include <qscrollbar.h>
#include <math.h>
#include "hantekdsowidget.h"
#include "glbox.h"

HantekDSOWidget::HantekDSOWidget(QWidget* parent, const char* name, WFlags fl)
        : HantekDSOWidgetBase(parent,name,fl), dsoModel(DSO_2150), timeBase(TIME_1ms),
          selectedChannel(SELECT_CH1CH2), ch1Active(1), ch2Active(1),
          ch1Voltage(VOLTAGE_5V), ch2Voltage(VOLTAGE_5V),
          ch1Coupling(COUPLING_DC), ch2Coupling(COUPLING_DC),
          ch1Offset(0), ch2Offset(0), triggerOffset(0),
          ch1Filter(0), ch2Filter(0), triggerFilter(0),
          triggerSource(0), triggerSlope(SLOPE_POSITIVE),
          triggerPosition(0x78A60), triggerMode(TRIGGERMODE_AUTO),
          calData(0)
{
    gLBox1->setAThread(&dsoAThread);
    connect(&refreshTimer, SIGNAL(timeout()), this, SLOT(refreshView()));
    startDSO();
}

HantekDSOWidget::~HantekDSOWidget()
{
    refreshTimer.stop();
    dsoAThread.terminate();
}

/*$SPECIALIZATION$*/

void HantekDSOWidget::polish(void)
{
}


/*!
    \fn HantekDSOWidget::startDSO()
 */
int HantekDSOWidget::startDSO()
{
    if (dsoAThread.dsoIO.initDSO(dsoModel) == 0)
    {
        textInfo->setText("DSO found");

        if (dsoAThread.dsoIO.dsoGetChannelLevel(&chLevels) < 0)
        {
            qDebug("Error running GetChannelLevel command");
        }
/*
        for(int i=0; i<2; i++)
            for(int j=0; j<9; j++)
                for(int k=0; k<2; k++)
                    qDebug("%04X", chLevels[i][j][k]);
*/
        if (dsoAThread.dsoIO.dsoGetCalData(&calData) < 0)
        {
            qDebug("Error running GetCalData command");
        }
        qDebug("CalData=%i", calData);
        gLBox1->setCalData((double)calData/2);

        if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel, triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
        {
            qDebug("Error running SetTriggerAndSampleRate command");
        }

        if (dsoAThread.dsoIO.dsoSetFilter(ch1Filter, ch2Filter, triggerFilter) < 0)
        {
            qDebug("Error running SetFilter command");
        }

        if (dsoAThread.dsoIO.dsoSetVoltageAndCoupling(ch1Voltage, ch2Voltage,
            ch1Coupling, ch2Coupling, triggerSource) < 0)
        {
            qDebug("Error running SetVoltageAndCoupling command");
        }
        if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel,
            triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
        {
            qDebug("Error running SetTriggerAndSampleRate command");
        }

        sliderCh1_valueChanged(sliderCh1->value());
        sliderCh2_valueChanged(sliderCh2->value());
        sliderTrigger_valueChanged(sliderTrigger->value());
        dsoAThread.start();

        refreshTimer.start(25, FALSE);
    }
    else
    {
        textInfo->setText("DSO NOT found");
    }

    return 0;
}


void HantekDSOWidget::buttonStart_clicked()
{
    qDebug("START");
    if (dsoAThread.dsoIO.dsoForceTrigger() < 0)
    {
        qDebug("Error running TriggerEnabled command");
    }
}

void HantekDSOWidget::buttonStop_clicked()
{
    qDebug("STOP");
}


/*!
    \fn HantekDSOWidget::setActiveChannel()
 */
void HantekDSOWidget::setActiveChannel()
{
    int prevSelectedChannel = selectedChannel;

    if (ch1Active & ch2Active)
    {
        selectedChannel = SELECT_CH1CH2;
    }
    else
    {
        if (ch1Active)
        {
            selectedChannel = SELECT_CH1;
        }
        if (ch2Active)
        {
            selectedChannel = SELECT_CH2;
        }
    }

    if (selectedChannel != prevSelectedChannel)
    {
        if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel,
            triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
        {
            qDebug("Error running SetTriggerAndSampleRate command");
        }
    }
}

void HantekDSOWidget::comboVoltage1_activated(int voltage)
{
    qDebug("Voltage1=%i", voltage);
    ch1Voltage = voltage;
    if (dsoAThread.dsoIO.dsoSetVoltageAndCoupling(ch1Voltage, ch2Voltage,
        ch1Coupling, ch2Coupling,  triggerSource) < 0)
    {
        qDebug("Error running SetVoltageAndCoupling command");
    }
    sliderCh1_valueChanged(sliderCh1->value());
}

void HantekDSOWidget::comboCoupling1_activated(int coupling)
{
    if (coupling != COUPLING_OFF)
    {
        ch1Active = CHANNEL_ACTIVE;
        ch1Coupling = coupling;
        if (dsoAThread.dsoIO.dsoSetVoltageAndCoupling(ch1Voltage, ch2Voltage,
            ch1Coupling, ch2Coupling,  triggerSource) < 0)
        {
            qDebug("Error running SetVoltageAndCoupling command");
        }
    }
    else
    {
        ch1Active = CHANNEL_OFF;
    }

    setActiveChannel();
}

void HantekDSOWidget::comboVoltage2_activated(int voltage)
{
    qDebug("Voltage1=%i", voltage);
    ch2Voltage = voltage;
    if (dsoAThread.dsoIO.dsoSetVoltageAndCoupling(ch1Voltage, ch2Voltage,
        ch1Coupling, ch2Coupling,  triggerSource) < 0)
    {
        qDebug("Error running SetVoltageAndCoupling command");
    }
    sliderCh2_valueChanged(sliderCh2->value());
}

void HantekDSOWidget::comboCoupling2_activated(int coupling)
{
    if (coupling != COUPLING_OFF)
    {
        ch2Active = CHANNEL_ACTIVE;
        ch2Coupling = coupling;
        if (dsoAThread.dsoIO.dsoSetVoltageAndCoupling(ch1Voltage, ch2Voltage,
            ch1Coupling, ch2Coupling, triggerSource) < 0)
        {
            qDebug("Error running SetVoltageAndCoupling command");
        }
    }
    else
    {
        ch2Active = CHANNEL_OFF;
    }

    setActiveChannel();
}

void HantekDSOWidget::comboTimeBase_activated(int timeBase)
{
    qDebug("TimeBase=%i", timeBase);
    this->timeBase = timeBase;
    if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel,
        triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
    {
        qDebug("Error running SetTriggerAndSampleRate command");
    }
}

void HantekDSOWidget::sliderCh1_valueChanged(int value)
{
    unsigned offsetStart = chLevels[SELECT_CH1][VOLTAGE_10mV-ch1Voltage][OFFSET_START];
    unsigned offsetEnd = chLevels[SELECT_CH1][VOLTAGE_10mV-ch1Voltage][OFFSET_END];
    unsigned offsetRange = offsetEnd - offsetStart;

    unsigned sliderStart = sliderCh1->minValue();
    unsigned sliderEnd = sliderCh1->maxValue();
    unsigned sliderRange = sliderEnd - sliderStart;

    ch1Offset = (sliderEnd - value)*offsetRange/sliderRange + offsetStart;
    ch1Offset >>= 8;

    if (dsoAThread.dsoIO.dsoSetOffset(ch1Offset, ch2Offset, triggerOffset) < 0)
    {
        qDebug("Error running SetOffset command");
    }
}

void HantekDSOWidget::sliderCh2_valueChanged(int value)
{
    unsigned offsetStart = chLevels[SELECT_CH2][VOLTAGE_10mV-ch2Voltage][OFFSET_START];
    unsigned offsetEnd = chLevels[SELECT_CH2][VOLTAGE_10mV-ch2Voltage][OFFSET_END];
    unsigned offsetRange = offsetEnd - offsetStart;

    unsigned sliderStart = sliderCh2->minValue();
    unsigned sliderEnd = sliderCh2->maxValue(); 
    unsigned sliderRange = sliderEnd - sliderStart;

    ch2Offset = (sliderEnd - value)*offsetRange/sliderRange + offsetStart;
    ch2Offset >>= 8;

    if (dsoAThread.dsoIO.dsoSetOffset(ch1Offset, ch2Offset, triggerOffset) < 0)
    {
        qDebug("Error running SetOffset command");
    }
}

void HantekDSOWidget::sliderTrigger_valueChanged(int value)
{
    unsigned offsetStart = 0x00;
    unsigned offsetEnd = 0xFE;
    unsigned offsetRange = offsetEnd - offsetStart;

    unsigned sliderStart = sliderTrigger->minValue();
    unsigned sliderEnd = sliderTrigger->maxValue(); 
    unsigned sliderRange = sliderEnd - sliderStart;

    triggerOffset = (sliderEnd - value)*offsetRange/sliderRange + offsetStart;

    if (dsoAThread.dsoIO.dsoSetOffset(ch1Offset, ch2Offset, triggerOffset) < 0)
    {
        qDebug("Error running SetOffset command");
    }
}


/*!
    \fn HantekDSOWidget::refreshView()
 */
void HantekDSOWidget::refreshView()
{
    gLBox1->updateGL();
}

void HantekDSOWidget::comboDisplayInterpolation_activated(int state)
{
    qDebug("Interpolation=%i", state);
    gLBox1->setInterpolation(state);
}

void HantekDSOWidget::checkDigitalPhosphor_stateChanged(int state)
{
    qDebug("DigitalPhosphor=%i", state);
    gLBox1->setDigitalPhosphor(state);
}

void HantekDSOWidget::checkDSound_stateChanged(int state)
{
    qDebug("DigitalSound=%i", state);
}

void HantekDSOWidget::comboViewMode_activated(int mode)
{
    qDebug("ViewMode=%i", mode);
    gLBox1->setViewMode(mode);
}

void HantekDSOWidget::comboMathType_activated(int type)
{
    qDebug("MathType=%i", type);
    gLBox1->setMathType(type);
}

void HantekDSOWidget::sliderTriggerPos_valueChanged(int value)
{
    triggerPosition = 0x77660 + value;
    if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel,
        triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
    {
        qDebug("Error running SetTriggerAndSampleRate command");
    }
}

void HantekDSOWidget::comboTriggerSource_activated(int source)
{
    qDebug("Trigger source=%i", source);
    triggerSource = source;
    if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel,
        triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
    {
        qDebug("Error running SetTriggerAndSampleRate command");
    }
}

void HantekDSOWidget::comboTriggerSlope_activated(int slope)
{
    qDebug("Trigger slope=%i", slope);
    triggerSlope = slope;
    if (dsoAThread.dsoIO.dsoSetTriggerAndSampleRate(timeBase, selectedChannel,
        triggerSource, triggerSlope, triggerPosition, dsoAThread.bufferSize) < 0)
    {
        qDebug("Error running SetTriggerAndSampleRate command");
    }
}

void HantekDSOWidget::comboTriggerMode_activated(int mode)
{
    qDebug("Trigger mode=%i", mode);
}

void HantekDSOWidget::timeDiv_activated(int div)
{
    qDebug("div=%i", div);
    double timeDiv = 1 << (div % 3);
    timeDiv *= pow(10, div / 3);
    qDebug("TimeDiv=%f", timeDiv);
    gLBox1->setTimeDiv(timeDiv);

}

void HantekDSOWidget::scrollShift_valueChanged(int time)
{
    double timeShift = (double)time/scrollShift->maxValue();
    qDebug("ShiftTime=%f", timeShift);
    gLBox1->setTimeShift(timeShift);
}

void HantekDSOWidget::checkCh1Filter_stateChanged(int filter)
{
    ch1Filter = filter?1:0;
    qDebug("Channel1 filter=%i", ch1Filter);
    if (dsoAThread.dsoIO.dsoSetFilter(ch1Filter, ch2Filter, triggerFilter) < 0)
    {
        qDebug("Error running SetFilter command");
    }
}

void HantekDSOWidget::checkCh2Filter_stateChanged(int filter)
{
    ch2Filter = filter?1:0;
    qDebug("Channel2 filter=%i", ch2Filter);
    if (dsoAThread.dsoIO.dsoSetFilter(ch1Filter, ch2Filter, triggerFilter) < 0)
    {
        qDebug("Error running SetFilter command");
    }
}

void HantekDSOWidget::checkTrigFilter_stateChanged(int filter)
{
    triggerFilter = filter?1:0;
    qDebug("Trigger filter=%i", triggerFilter);
    if (dsoAThread.dsoIO.dsoSetFilter(ch1Filter, ch2Filter, triggerFilter) < 0)
    {
        qDebug("Error running SetFilter command");
    }
}

#include "hantekdsowidget.moc"

