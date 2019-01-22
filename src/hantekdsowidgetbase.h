/****************************************************************************
** Form interface generated from reading ui file './hantekdsowidgetbase.ui'
**
** Created by User Interface Compiler
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef HANTEKDSOWIDGETBASE_H
#define HANTEKDSOWIDGETBASE_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class GLBox;
class QSlider;
class QScrollBar;
class QGroupBox;
class QComboBox;
class QCheckBox;
class QPushButton;
class QLabel;

class HantekDSOWidgetBase : public QWidget
{
    Q_OBJECT

public:
    HantekDSOWidgetBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~HantekDSOWidgetBase();

    QSlider* sliderCh2;
    QSlider* sliderCh1;
    QSlider* sliderTriggerPos;
    GLBox* gLBox1;
    QSlider* sliderTrigger;
    QScrollBar* scrollShift;
    QGroupBox* groupChannel1;
    QComboBox* comboAtten1;
    QComboBox* comboVoltage1;
    QComboBox* comboCoupling1;
    QCheckBox* checkCh1Filter;
    QGroupBox* groupChannel2;
    QComboBox* comboAtten2;
    QComboBox* comboVoltage2;
    QComboBox* comboCoupling2;
    QCheckBox* checkCh2Filter;
    QGroupBox* groupDisplay;
    QComboBox* comboViewMode;
    QComboBox* comboMathType;
    QComboBox* comboDisplayInterpolation;
    QCheckBox* checkDigitalPhosphor;
    QCheckBox* checkDSound;
    QGroupBox* groupTiming;
    QComboBox* comboTimeBase;
    QComboBox* timeDiv;
    QComboBox* comboTriggerSource;
    QComboBox* comboTriggerSlope;
    QComboBox* comboTriggerMode;
    QCheckBox* checkTrigFilter;
    QPushButton* buttonStart;
    QPushButton* buttonStop;
    QLabel* textInfo;

public slots:
    virtual void button_clicked();
    virtual void buttonStart_clicked();
    virtual void buttonStop_clicked();
    virtual void comboCoupling1_activated(int);
    virtual void comboVoltage1_activated(int);
    virtual void comboVoltage2_activated(int);
    virtual void comboCoupling2_activated(int);
    virtual void comboTimeBase_activated(int);
    virtual void checkDigitalPhosphor_stateChanged(int);
    virtual void comboDisplayInterpolation_activated(int);
    virtual void sliderCh1_valueChanged(int);
    virtual void sliderCh2_valueChanged(int);
    virtual void sliderTriggerPos_valueChanged(int);
    virtual void sliderTrigger_valueChanged(int);
    virtual void comboTriggerSource_activated(int);
    virtual void comboTriggerSlope_activated(int);
    virtual void comboTriggerMode_activated(int);
    virtual void comboViewMode_activated(int);
    virtual void scrollShift_valueChanged(int);
    virtual void comboMathType_activated(const QString&);
    virtual void comboMathType_activated(int);
    virtual void timeDiv_activated(int);
    virtual void checkDSound_stateChanged(int);
    virtual void checkCh1Filter_stateChanged(int);
    virtual void checkCh2Filter_stateChanged(int);
    virtual void checkTrigFilter_stateChanged(int);

protected:
    QGridLayout* hantekdsowidgetbaseLayout;
    QVBoxLayout* layout31;
    QHBoxLayout* layout35;
    QVBoxLayout* layout29;
    QSpacerItem* spacer6;
    QHBoxLayout* layout28;
    QVBoxLayout* layout25;
    QVBoxLayout* layout33;
    QSpacerItem* spacer7;
    QHBoxLayout* layout30;
    QSpacerItem* spacer3_2;
    QSpacerItem* spacer3;
    QVBoxLayout* layout29_2;
    QHBoxLayout* layout28_2;
    QGridLayout* groupChannel1Layout;
    QVBoxLayout* layout22;
    QGridLayout* groupChannel2Layout;
    QVBoxLayout* layout23;
    QGridLayout* groupDisplayLayout;
    QVBoxLayout* layout27;
    QSpacerItem* spacer10_2;
    QHBoxLayout* layout15;
    QHBoxLayout* layout23_2;
    QSpacerItem* spacer9_2;
    QHBoxLayout* layout24;
    QGridLayout* groupTimingLayout;
    QHBoxLayout* layout35_2;
    QVBoxLayout* layout34;
    QHBoxLayout* layout65;
    QSpacerItem* spacer18;
    QHBoxLayout* layout61;
    QSpacerItem* spacer10;
    QHBoxLayout* layout26;
    QSpacerItem* spacer9;
    QHBoxLayout* layout24_2;
    QSpacerItem* spacer9_3;
    QVBoxLayout* layout24_3;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // HANTEKDSOWIDGETBASE_H
