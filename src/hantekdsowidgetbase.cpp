#include "hantekdsowidgetbase.h"

#include <qvariant.h>
#include <timecursor.h>
#include <voltagecursor.h>
#include "hantekdsowidgetbase.h"
#include "glbox.h"
/*
 *  Constructs a HantekDSOWidgetBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
HantekDSOWidgetBase::HantekDSOWidgetBase(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : QWidget(parent, name, fl)
{
    setupUi(this);

}

/*
 *  Destroys the object and frees any allocated resources
 */
HantekDSOWidgetBase::~HantekDSOWidgetBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void HantekDSOWidgetBase::languageChange()
{
    retranslateUi(this);
}

void HantekDSOWidgetBase::button_clicked()
{
    qWarning("HantekDSOWidgetBase::button_clicked(): Not implemented yet");
}

void HantekDSOWidgetBase::buttonStart_clicked()
{
    qWarning("HantekDSOWidgetBase::buttonStart_clicked(): Not implemented yet");
}

void HantekDSOWidgetBase::buttonStop_clicked()
{
    qWarning("HantekDSOWidgetBase::buttonStop_clicked(): Not implemented yet");
}

void HantekDSOWidgetBase::comboCoupling1_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboCoupling1_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboVoltage1_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboVoltage1_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboVoltage2_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboVoltage2_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboAtten1_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboAtten1_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboAtten2_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboAtten2_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboCoupling2_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboCoupling2_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboTimeBase_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboTimeBase_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::checkDigitalPhosphor_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::checkDigitalPhosphor_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboDisplayInterpolation_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboDisplayInterpolation_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::sliderCh1_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::sliderCh1_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::sliderCh2_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::sliderCh2_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::sliderTriggerPos_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::sliderTriggerPos_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::sliderTrigger_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::sliderTrigger_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboTriggerSource_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboTriggerSource_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboTriggerSlope_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboTriggerSlope_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboTriggerMode_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboTriggerMode_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboViewMode_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboViewMode_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::scrollShift_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::scrollShift_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::comboMathType_activated( const QString &)
{
    qWarning("HantekDSOWidgetBase::comboMathType_activated( const QString &): Not implemented yet");
}

void HantekDSOWidgetBase::comboMathType_activated(int)
{
    qWarning("HantekDSOWidgetBase::comboMathType_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::timeDiv_activated(int)
{
    qWarning("HantekDSOWidgetBase::timeDiv_activated(int): Not implemented yet");
}

void HantekDSOWidgetBase::checkDSound_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::checkDSound_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::checkCh1Filter_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::checkCh1Filter_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::checkCh2Filter_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::checkCh2Filter_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::checkTrigFilter_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::checkTrigFilter_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::sliderMath_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::sliderMath_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::sliderChM_valueChanged(int)
{
    qWarning("HantekDSOWidgetBase::sliderChM_valueChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::timeCursor_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::timeCursor_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::cursorCh1_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::cursorCh1_stateChanged(int): Not implemented yet");
}

void HantekDSOWidgetBase::cursorCh2_stateChanged(int)
{
    qWarning("HantekDSOWidgetBase::cursorCh2_stateChanged(int): Not implemented yet");
}

