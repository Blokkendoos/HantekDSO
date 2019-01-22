/***************************************************************************
 *   Copyright (C) 2008 by Oleg Khudyakov   *
 *   prcoder@gmail.com   *
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


#ifndef _HANTEKDSOWIDGET_H_
#define _HANTEKDSOWIDGET_H_

#include "hantekdsowidgetbase.h"
#include "hantekdsoathread.h"
#include <qtimer.h>

enum channel_activity
{
    CHANNEL_OFF = 0,
    CHANNEL_ACTIVE
};

class HantekDSOWidget : public HantekDSOWidgetBase
{
    Q_OBJECT

public:
    HantekDSOWidget(QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~HantekDSOWidget();
    /*$PUBLIC_FUNCTIONS$*/
    
    void saveSetting();

protected:
    /*$PROTECTED_FUNCTIONS$*/
    virtual void polish(void);

protected:
    HantekDSOAThread dsoAThread;
    QTimer refreshTimer;
    int timeBase;
    int selectedChannel;
    int ch1Active, ch2Active;
    int ch1Voltage, ch2Voltage;
    int ch1Atten, ch2Atten;
    int ch1Coupling, ch2Coupling;
    int ch1Offset, ch2Offset, triggerOffset;
    int prevCh1SliderValue, prevCh2SliderValue;
    int ch1Filter, ch2Filter, triggerFilter;
    int triggerSource, triggerSlope, triggerPosition;
    int calData;
    channel_levels chLevels;
    static const double voltagePerDiv[];

public slots:
    /*$PUBLIC_SLOTS$*/
    virtual void buttonStart_clicked();
    virtual void refreshView();
    virtual void setActiveChannel();
    virtual void comboCoupling1_activated(int);
    virtual void comboCoupling2_activated(int);
    virtual void comboVoltage2_activated(int);
    virtual void comboVoltage1_activated(int);
    virtual void comboAtten1_activated(int);
    virtual void comboAtten2_activated(int);
    virtual void comboTimeBase_activated(int);
    virtual void comboTriggerMode_activated(int);
    virtual void sliderTriggerPos_valueChanged(int);
    virtual void sliderCh1_valueChanged(int);
    virtual void sliderCh2_valueChanged(int);
    virtual void sliderChM_valueChanged(int);
    virtual void sliderTrigger_valueChanged(int);
    virtual void buttonStop_clicked();
    virtual void comboDisplayInterpolation_activated(int);
    virtual void checkDigitalPhosphor_stateChanged(int);
    virtual void checkDSound_stateChanged(int);
    virtual void comboViewMode_activated(int);
    virtual void comboMathType_activated(int);
    virtual void comboTriggerSlope_activated(int);
    virtual void comboTriggerSource_activated(int);
    virtual void timeDiv_activated(int);
    virtual void scrollShift_valueChanged(int);
    virtual void checkTrigFilter_stateChanged(int);
    virtual void checkCh2Filter_stateChanged(int);
    virtual void checkCh1Filter_stateChanged(int);
    virtual void timeCursor_stateChanged( int state );
    virtual void cursorCh1_stateChanged( int state );
    virtual void cursorCh2_stateChanged( int state );

protected slots:
    /*$PROTECTED_SLOTS$*/
    virtual int startDSO();
    
private:
    void readSetting();
};

#endif

