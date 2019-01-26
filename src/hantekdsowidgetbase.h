#ifndef HANTEKDSOWIDGETBASE_H
#define HANTEKDSOWIDGETBASE_H

#include <qvariant.h>


#include <Qt3Support/Q3GroupBox>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <timecursor.h>
#include <voltagecursor.h>
#include "glbox.h"
#include "timecursor.h"
#include "voltagecursor.h"

QT_BEGIN_NAMESPACE

class Ui_HantekDSOWidgetBase
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout2;
    QSpacerItem *spacer6;
    QHBoxLayout *hboxLayout2;
    QSlider *sliderCh2;
    QSlider *sliderCh1;
    QVBoxLayout *vboxLayout3;
    QSlider *sliderTriggerPos;
    GLBox *gLBox1;
    QVBoxLayout *vboxLayout4;
    QSpacerItem *spacer7;
    QHBoxLayout *hboxLayout3;
    QSlider *sliderTrigger;
    QSlider *sliderChM;
    QScrollBar *scrollShift;
    QVBoxLayout *vboxLayout5;
    QSpacerItem *spacer20;
    Q3GroupBox *groupTiming;
    QWidget *layout65;
    QHBoxLayout *hboxLayout4;
    QComboBox *comboTimeBase;
    QComboBox *timeDiv;
    QSpacerItem *spacer18;
    QWidget *layout61;
    QHBoxLayout *hboxLayout5;
    QComboBox *comboTriggerSource;
    QComboBox *comboTriggerSlope;
    QSpacerItem *spacer10;
    QWidget *layout26;
    QHBoxLayout *hboxLayout6;
    QComboBox *comboTriggerMode;
    QSpacerItem *spacer9;
    QWidget *layout18;
    QHBoxLayout *hboxLayout7;
    QCheckBox *checkTrigFilter;
    TimeCursor *timeCursor;
    QSpacerItem *spacer29;
    QWidget *layout46;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *spacer13;
    QPushButton *buttonStart;
    QPushButton *buttonStop;
    QSpacerItem *spacer12;
    QHBoxLayout *hboxLayout9;
    Q3GroupBox *groupChannel1;
    QComboBox *comboAtten1;
    QComboBox *comboVoltage1;
    QComboBox *comboCoupling1;
    QCheckBox *checkCh1Filter;
    VoltageCursor *cursorCh1;
    Q3GroupBox *groupChannel2;
    QComboBox *comboAtten2;
    QComboBox *comboVoltage2;
    QComboBox *comboCoupling2;
    QCheckBox *checkCh2Filter;
    VoltageCursor *cursorCh2;
    QHBoxLayout *hboxLayout10;
    Q3GroupBox *groupChannelMath;
    QVBoxLayout *vboxLayout6;
    QComboBox *comboMathType;
    QSpacerItem *spacer11;
    Q3GroupBox *groupDisplay;
    QVBoxLayout *vboxLayout7;
    QComboBox *comboViewMode;
    QComboBox *comboDisplayInterpolation;
    QCheckBox *checkDigitalPhosphor;
    QCheckBox *checkDSound;
    QSpacerItem *spacer14;
    QLabel *textInfo;

    void setupUi(QWidget *hantekdsowidgetbase)
    {
        if (hantekdsowidgetbase->objectName().isEmpty())
            hantekdsowidgetbase->setObjectName(QString::fromUtf8("hantekdsowidgetbase"));
        hantekdsowidgetbase->setEnabled(true);
        hantekdsowidgetbase->resize(818, 574);
        gridLayout = new QGridLayout(hantekdsowidgetbase);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(5);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(5);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(0);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(0);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(0);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        spacer6 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacer6);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(0);
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        sliderCh2 = new QSlider(hantekdsowidgetbase);
        sliderCh2->setObjectName(QString::fromUtf8("sliderCh2"));
        sliderCh2->setMinimumSize(QSize(14, 0));
        sliderCh2->setMaximumSize(QSize(14, 32767));
        QPalette palette;
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(1), QColor(0, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(2), QColor(127, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(3), QColor(63, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(4), QColor(0, 127, 127));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(5), QColor(0, 170, 170));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(14), QColor(0, 0, 0));
        palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(15), QColor(0, 0, 0));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(1), QColor(0, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(2), QColor(127, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(3), QColor(38, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(4), QColor(0, 127, 127));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(5), QColor(0, 170, 170));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(0), QColor(128, 128, 128));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(1), QColor(0, 255, 255));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(2), QColor(127, 255, 255));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(3), QColor(38, 255, 255));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(4), QColor(0, 127, 127));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(5), QColor(0, 170, 170));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(6), QColor(128, 128, 128));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(8), QColor(128, 128, 128));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        sliderCh2->setPalette(palette);
        sliderCh2->setMouseTracking(true);
        sliderCh2->setMaximum(799);
        sliderCh2->setSingleStep(3);
        sliderCh2->setPageStep(100);
        sliderCh2->setValue(400);
        sliderCh2->setOrientation(Qt::Vertical);
        sliderCh2->setTickPosition(QSlider::TicksBelow);
        sliderCh2->setAttribute(Qt::WA_LayoutUsesWidgetRect);

        hboxLayout2->addWidget(sliderCh2);

        sliderCh1 = new QSlider(hantekdsowidgetbase);
        sliderCh1->setObjectName(QString::fromUtf8("sliderCh1"));
        sliderCh1->setMinimumSize(QSize(14, 0));
        sliderCh1->setMaximumSize(QSize(14, 32767));
        QPalette palette1;
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(1), QColor(255, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(2), QColor(255, 127, 127));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(3), QColor(255, 63, 63));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(4), QColor(127, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(5), QColor(170, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(14), QColor(0, 0, 0));
        palette1.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(15), QColor(0, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(1), QColor(255, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(2), QColor(255, 127, 127));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(3), QColor(255, 38, 38));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(4), QColor(127, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(5), QColor(170, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette1.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(0), QColor(128, 128, 128));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(1), QColor(255, 0, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(2), QColor(255, 127, 127));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(3), QColor(255, 38, 38));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(4), QColor(127, 0, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(5), QColor(170, 0, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(6), QColor(128, 128, 128));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(8), QColor(128, 128, 128));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette1.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        sliderCh1->setPalette(palette1);
        sliderCh1->setMouseTracking(true);
        sliderCh1->setMaximum(799);
        sliderCh1->setSingleStep(3);
        sliderCh1->setPageStep(100);
        sliderCh1->setValue(400);
        sliderCh1->setOrientation(Qt::Vertical);
        sliderCh1->setTickPosition(QSlider::TicksBelow);
        sliderCh1->setAttribute(Qt::WA_LayoutUsesWidgetRect);

        hboxLayout2->addWidget(sliderCh1);


        vboxLayout2->addLayout(hboxLayout2);


        hboxLayout1->addLayout(vboxLayout2);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(0);
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        sliderTriggerPos = new QSlider(hantekdsowidgetbase);
        sliderTriggerPos->setObjectName(QString::fromUtf8("sliderTriggerPos"));
        sliderTriggerPos->setMinimumSize(QSize(0, 12));
        sliderTriggerPos->setMaximumSize(QSize(32767, 12));
        QPalette palette2;
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(1), QColor(170, 0, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(2), QColor(212, 127, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(3), QColor(191, 63, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(4), QColor(85, 0, 127));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(5), QColor(113, 0, 170));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(14), QColor(0, 0, 0));
        palette2.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(15), QColor(0, 0, 0));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(1), QColor(170, 0, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(2), QColor(212, 127, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(3), QColor(183, 38, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(4), QColor(85, 0, 127));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(5), QColor(113, 0, 170));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette2.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(0), QColor(128, 128, 128));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(1), QColor(170, 0, 255));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(2), QColor(212, 127, 255));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(3), QColor(183, 38, 255));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(4), QColor(85, 0, 127));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(5), QColor(113, 0, 170));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(6), QColor(128, 128, 128));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(8), QColor(128, 128, 128));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette2.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        sliderTriggerPos->setPalette(palette2);
        sliderTriggerPos->setMouseTracking(true);
        sliderTriggerPos->setMaximum(10239);
        sliderTriggerPos->setValue(5120);
        sliderTriggerPos->setOrientation(Qt::Horizontal);
        sliderTriggerPos->setAttribute(Qt::WA_LayoutUsesWidgetRect);

        vboxLayout3->addWidget(sliderTriggerPos);

        gLBox1 = new GLBox(hantekdsowidgetbase);
        gLBox1->setObjectName(QString::fromUtf8("gLBox1"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gLBox1->sizePolicy().hasHeightForWidth());
        gLBox1->setSizePolicy(sizePolicy);
        gLBox1->setMinimumSize(QSize(540, 432));

        vboxLayout3->addWidget(gLBox1);


        hboxLayout1->addLayout(vboxLayout3);

        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setSpacing(0);
        vboxLayout4->setContentsMargins(0, 0, 0, 0);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        spacer7 = new QSpacerItem(30, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout4->addItem(spacer7);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(0);
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        sliderTrigger = new QSlider(hantekdsowidgetbase);
        sliderTrigger->setObjectName(QString::fromUtf8("sliderTrigger"));
        sliderTrigger->setMinimumSize(QSize(14, 0));
        sliderTrigger->setMaximumSize(QSize(14, 32767));
        QPalette palette3;
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(1), QColor(170, 0, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(2), QColor(212, 127, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(3), QColor(191, 63, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(4), QColor(85, 0, 127));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(5), QColor(113, 0, 170));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(14), QColor(0, 0, 0));
        palette3.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(15), QColor(0, 0, 0));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(1), QColor(170, 0, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(2), QColor(212, 127, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(3), QColor(183, 38, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(4), QColor(85, 0, 127));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(5), QColor(113, 0, 170));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette3.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(0), QColor(128, 128, 128));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(1), QColor(170, 0, 255));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(2), QColor(212, 127, 255));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(3), QColor(183, 38, 255));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(4), QColor(85, 0, 127));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(5), QColor(113, 0, 170));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(6), QColor(128, 128, 128));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(8), QColor(128, 128, 128));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette3.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        sliderTrigger->setPalette(palette3);
        sliderTrigger->setMouseTracking(true);
        sliderTrigger->setMaximum(799);
        sliderTrigger->setSingleStep(3);
        sliderTrigger->setPageStep(100);
        sliderTrigger->setValue(400);
        sliderTrigger->setOrientation(Qt::Vertical);
        sliderTrigger->setTickPosition(QSlider::TicksAbove);
        sliderTrigger->setAttribute(Qt::WA_LayoutUsesWidgetRect);

        hboxLayout3->addWidget(sliderTrigger);

        sliderChM = new QSlider(hantekdsowidgetbase);
        sliderChM->setObjectName(QString::fromUtf8("sliderChM"));
        sliderChM->setMinimumSize(QSize(14, 0));
        sliderChM->setMaximumSize(QSize(14, 32767));
        QPalette palette4;
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(1), QColor(0, 255, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(2), QColor(127, 255, 127));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(3), QColor(63, 255, 63));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(4), QColor(0, 127, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(5), QColor(0, 170, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(14), QColor(0, 0, 0));
        palette4.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(15), QColor(0, 0, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(0), QColor(255, 255, 255));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(1), QColor(0, 255, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(2), QColor(127, 255, 127));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(3), QColor(38, 255, 38));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(4), QColor(0, 127, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(5), QColor(0, 170, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(6), QColor(255, 255, 255));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(8), QColor(255, 255, 255));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette4.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(0), QColor(128, 128, 128));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(1), QColor(0, 255, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(2), QColor(127, 255, 127));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(3), QColor(38, 255, 38));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(4), QColor(0, 127, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(5), QColor(0, 170, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(6), QColor(128, 128, 128));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(8), QColor(128, 128, 128));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(9), QColor(0, 0, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(10), QColor(0, 0, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(12), QColor(0, 0, 128));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette4.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        sliderChM->setPalette(palette4);
        sliderChM->setMouseTracking(true);
        sliderChM->setMaximum(799);
        sliderChM->setSingleStep(3);
        sliderChM->setPageStep(100);
        sliderChM->setValue(400);
        sliderChM->setOrientation(Qt::Vertical);
        sliderChM->setTickPosition(QSlider::TicksAbove);
        sliderChM->setAttribute(Qt::WA_LayoutUsesWidgetRect);

        hboxLayout3->addWidget(sliderChM);


        vboxLayout4->addLayout(hboxLayout3);


        hboxLayout1->addLayout(vboxLayout4);


        vboxLayout1->addLayout(hboxLayout1);

        scrollShift = new QScrollBar(hantekdsowidgetbase);
        scrollShift->setObjectName(QString::fromUtf8("scrollShift"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollShift->sizePolicy().hasHeightForWidth());
        scrollShift->setSizePolicy(sizePolicy1);
        scrollShift->setMaximumSize(QSize(32767, 32767));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        scrollShift->setFont(font);
        scrollShift->setMaximum(32767);
        scrollShift->setPageStep(16);
        scrollShift->setOrientation(Qt::Horizontal);

        vboxLayout1->addWidget(scrollShift);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout5 = new QVBoxLayout();
        vboxLayout5->setSpacing(5);
        vboxLayout5->setContentsMargins(0, 0, 0, 0);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        spacer20 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout5->addItem(spacer20);

        groupTiming = new Q3GroupBox(hantekdsowidgetbase);
        groupTiming->setObjectName(QString::fromUtf8("groupTiming"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupTiming->sizePolicy().hasHeightForWidth());
        groupTiming->setSizePolicy(sizePolicy2);
        groupTiming->setMinimumSize(QSize(173, 175));
        groupTiming->setMaximumSize(QSize(173, 175));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Luxi Sans"));
        groupTiming->setFont(font1);
        layout65 = new QWidget(groupTiming);
        layout65->setObjectName(QString::fromUtf8("layout65"));
        layout65->setGeometry(QRect(5, 20, 163, 22));
        hboxLayout4 = new QHBoxLayout(layout65);
        hboxLayout4->setSpacing(0);
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        comboTimeBase = new QComboBox(layout65);
        comboTimeBase->setObjectName(QString::fromUtf8("comboTimeBase"));
        sizePolicy2.setHeightForWidth(comboTimeBase->sizePolicy().hasHeightForWidth());
        comboTimeBase->setSizePolicy(sizePolicy2);
        comboTimeBase->setMinimumSize(QSize(80, 20));
        comboTimeBase->setMaximumSize(QSize(80, 20));

        hboxLayout4->addWidget(comboTimeBase);

        timeDiv = new QComboBox(layout65);
        timeDiv->setObjectName(QString::fromUtf8("timeDiv"));
        sizePolicy2.setHeightForWidth(timeDiv->sizePolicy().hasHeightForWidth());
        timeDiv->setSizePolicy(sizePolicy2);
        timeDiv->setMinimumSize(QSize(50, 20));
        timeDiv->setMaximumSize(QSize(50, 20));

        hboxLayout4->addWidget(timeDiv);

        spacer18 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacer18);

        layout61 = new QWidget(groupTiming);
        layout61->setObjectName(QString::fromUtf8("layout61"));
        layout61->setGeometry(QRect(5, 47, 163, 22));
        hboxLayout5 = new QHBoxLayout(layout61);
        hboxLayout5->setSpacing(0);
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        comboTriggerSource = new QComboBox(layout61);
        comboTriggerSource->setObjectName(QString::fromUtf8("comboTriggerSource"));
        sizePolicy2.setHeightForWidth(comboTriggerSource->sizePolicy().hasHeightForWidth());
        comboTriggerSource->setSizePolicy(sizePolicy2);
        comboTriggerSource->setMinimumSize(QSize(80, 20));
        comboTriggerSource->setMaximumSize(QSize(80, 20));

        hboxLayout5->addWidget(comboTriggerSource);

        comboTriggerSlope = new QComboBox(layout61);
        comboTriggerSlope->setObjectName(QString::fromUtf8("comboTriggerSlope"));
        sizePolicy2.setHeightForWidth(comboTriggerSlope->sizePolicy().hasHeightForWidth());
        comboTriggerSlope->setSizePolicy(sizePolicy2);
        comboTriggerSlope->setMinimumSize(QSize(50, 20));
        comboTriggerSlope->setMaximumSize(QSize(50, 20));

        hboxLayout5->addWidget(comboTriggerSlope);

        spacer10 = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacer10);

        layout26 = new QWidget(groupTiming);
        layout26->setObjectName(QString::fromUtf8("layout26"));
        layout26->setGeometry(QRect(5, 74, 163, 22));
        hboxLayout6 = new QHBoxLayout(layout26);
        hboxLayout6->setSpacing(0);
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        comboTriggerMode = new QComboBox(layout26);
        comboTriggerMode->setObjectName(QString::fromUtf8("comboTriggerMode"));
        sizePolicy2.setHeightForWidth(comboTriggerMode->sizePolicy().hasHeightForWidth());
        comboTriggerMode->setSizePolicy(sizePolicy2);
        comboTriggerMode->setMinimumSize(QSize(80, 20));
        comboTriggerMode->setMaximumSize(QSize(80, 20));

        hboxLayout6->addWidget(comboTriggerMode);

        spacer9 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout6->addItem(spacer9);

        layout18 = new QWidget(groupTiming);
        layout18->setObjectName(QString::fromUtf8("layout18"));
        layout18->setGeometry(QRect(5, 101, 163, 22));
        hboxLayout7 = new QHBoxLayout(layout18);
        hboxLayout7->setSpacing(0);
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        checkTrigFilter = new QCheckBox(layout18);
        checkTrigFilter->setObjectName(QString::fromUtf8("checkTrigFilter"));
        sizePolicy2.setHeightForWidth(checkTrigFilter->sizePolicy().hasHeightForWidth());
        checkTrigFilter->setSizePolicy(sizePolicy2);
        checkTrigFilter->setMinimumSize(QSize(65, 20));
        checkTrigFilter->setMaximumSize(QSize(65, 20));

        hboxLayout7->addWidget(checkTrigFilter);

        timeCursor = new TimeCursor(layout18);
        timeCursor->setObjectName(QString::fromUtf8("timeCursor"));
        sizePolicy2.setHeightForWidth(timeCursor->sizePolicy().hasHeightForWidth());
        timeCursor->setSizePolicy(sizePolicy2);
        timeCursor->setMinimumSize(QSize(65, 20));
        timeCursor->setMaximumSize(QSize(65, 20));

        hboxLayout7->addWidget(timeCursor);

        spacer29 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacer29);

        layout46 = new QWidget(groupTiming);
        layout46->setObjectName(QString::fromUtf8("layout46"));
        layout46->setGeometry(QRect(5, 128, 163, 42));
        hboxLayout8 = new QHBoxLayout(layout46);
        hboxLayout8->setSpacing(0);
        hboxLayout8->setContentsMargins(0, 0, 0, 0);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        hboxLayout8->setContentsMargins(0, 0, 0, 0);
        spacer13 = new QSpacerItem(25, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(spacer13);

        buttonStart = new QPushButton(layout46);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        sizePolicy2.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy2);
        buttonStart->setMinimumSize(QSize(70, 39));
        buttonStart->setMaximumSize(QSize(70, 40));
        buttonStart->setFont(font1);

        hboxLayout8->addWidget(buttonStart);

        buttonStop = new QPushButton(layout46);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        sizePolicy2.setHeightForWidth(buttonStop->sizePolicy().hasHeightForWidth());
        buttonStop->setSizePolicy(sizePolicy2);
        buttonStop->setMinimumSize(QSize(70, 40));
        buttonStop->setMaximumSize(QSize(70, 40));
        buttonStop->setFont(font1);

        hboxLayout8->addWidget(buttonStop);

        spacer12 = new QSpacerItem(24, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout8->addItem(spacer12);


        vboxLayout5->addWidget(groupTiming);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setSpacing(5);
        hboxLayout9->setContentsMargins(0, 0, 0, 0);
        hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
        groupChannel1 = new Q3GroupBox(hantekdsowidgetbase);
        groupChannel1->setObjectName(QString::fromUtf8("groupChannel1"));
        sizePolicy2.setHeightForWidth(groupChannel1->sizePolicy().hasHeightForWidth());
        groupChannel1->setSizePolicy(sizePolicy2);
        groupChannel1->setMinimumSize(QSize(84, 140));
        groupChannel1->setMaximumSize(QSize(84, 140));
        groupChannel1->setFont(font1);
        comboAtten1 = new QComboBox(groupChannel1);
        comboAtten1->setObjectName(QString::fromUtf8("comboAtten1"));
        comboAtten1->setGeometry(QRect(5, 20, 72, 20));
        sizePolicy2.setHeightForWidth(comboAtten1->sizePolicy().hasHeightForWidth());
        comboAtten1->setSizePolicy(sizePolicy2);
        comboAtten1->setMinimumSize(QSize(72, 20));
        comboAtten1->setMaximumSize(QSize(72, 20));
        comboVoltage1 = new QComboBox(groupChannel1);
        comboVoltage1->setObjectName(QString::fromUtf8("comboVoltage1"));
        comboVoltage1->setGeometry(QRect(5, 45, 72, 20));
        sizePolicy2.setHeightForWidth(comboVoltage1->sizePolicy().hasHeightForWidth());
        comboVoltage1->setSizePolicy(sizePolicy2);
        comboVoltage1->setMinimumSize(QSize(72, 20));
        comboVoltage1->setMaximumSize(QSize(72, 20));
        comboCoupling1 = new QComboBox(groupChannel1);
        comboCoupling1->setObjectName(QString::fromUtf8("comboCoupling1"));
        comboCoupling1->setGeometry(QRect(5, 70, 72, 20));
        sizePolicy2.setHeightForWidth(comboCoupling1->sizePolicy().hasHeightForWidth());
        comboCoupling1->setSizePolicy(sizePolicy2);
        comboCoupling1->setMinimumSize(QSize(72, 20));
        comboCoupling1->setMaximumSize(QSize(72, 20));
        checkCh1Filter = new QCheckBox(groupChannel1);
        checkCh1Filter->setObjectName(QString::fromUtf8("checkCh1Filter"));
        checkCh1Filter->setGeometry(QRect(5, 95, 65, 20));
        sizePolicy2.setHeightForWidth(checkCh1Filter->sizePolicy().hasHeightForWidth());
        checkCh1Filter->setSizePolicy(sizePolicy2);
        checkCh1Filter->setMinimumSize(QSize(65, 20));
        checkCh1Filter->setMaximumSize(QSize(65, 20));
        cursorCh1 = new VoltageCursor(groupChannel1);
        cursorCh1->setObjectName(QString::fromUtf8("cursorCh1"));
        cursorCh1->setGeometry(QRect(5, 115, 65, 20));
        sizePolicy2.setHeightForWidth(cursorCh1->sizePolicy().hasHeightForWidth());
        cursorCh1->setSizePolicy(sizePolicy2);
        cursorCh1->setMinimumSize(QSize(65, 20));
        cursorCh1->setMaximumSize(QSize(65, 20));

        hboxLayout9->addWidget(groupChannel1);

        groupChannel2 = new Q3GroupBox(hantekdsowidgetbase);
        groupChannel2->setObjectName(QString::fromUtf8("groupChannel2"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(4));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupChannel2->sizePolicy().hasHeightForWidth());
        groupChannel2->setSizePolicy(sizePolicy3);
        groupChannel2->setMinimumSize(QSize(84, 140));
        groupChannel2->setMaximumSize(QSize(84, 140));
        groupChannel2->setFont(font1);
        comboAtten2 = new QComboBox(groupChannel2);
        comboAtten2->setObjectName(QString::fromUtf8("comboAtten2"));
        comboAtten2->setGeometry(QRect(5, 20, 72, 20));
        sizePolicy2.setHeightForWidth(comboAtten2->sizePolicy().hasHeightForWidth());
        comboAtten2->setSizePolicy(sizePolicy2);
        comboAtten2->setMinimumSize(QSize(72, 20));
        comboAtten2->setMaximumSize(QSize(72, 20));
        comboVoltage2 = new QComboBox(groupChannel2);
        comboVoltage2->setObjectName(QString::fromUtf8("comboVoltage2"));
        comboVoltage2->setGeometry(QRect(5, 45, 72, 20));
        sizePolicy2.setHeightForWidth(comboVoltage2->sizePolicy().hasHeightForWidth());
        comboVoltage2->setSizePolicy(sizePolicy2);
        comboVoltage2->setMinimumSize(QSize(72, 20));
        comboVoltage2->setMaximumSize(QSize(72, 20));
        comboCoupling2 = new QComboBox(groupChannel2);
        comboCoupling2->setObjectName(QString::fromUtf8("comboCoupling2"));
        comboCoupling2->setGeometry(QRect(5, 70, 72, 20));
        sizePolicy2.setHeightForWidth(comboCoupling2->sizePolicy().hasHeightForWidth());
        comboCoupling2->setSizePolicy(sizePolicy2);
        comboCoupling2->setMinimumSize(QSize(72, 20));
        comboCoupling2->setMaximumSize(QSize(72, 20));
        checkCh2Filter = new QCheckBox(groupChannel2);
        checkCh2Filter->setObjectName(QString::fromUtf8("checkCh2Filter"));
        checkCh2Filter->setGeometry(QRect(5, 95, 65, 20));
        sizePolicy2.setHeightForWidth(checkCh2Filter->sizePolicy().hasHeightForWidth());
        checkCh2Filter->setSizePolicy(sizePolicy2);
        checkCh2Filter->setMinimumSize(QSize(65, 20));
        checkCh2Filter->setMaximumSize(QSize(65, 20));
        cursorCh2 = new VoltageCursor(groupChannel2);
        cursorCh2->setObjectName(QString::fromUtf8("cursorCh2"));
        cursorCh2->setGeometry(QRect(5, 115, 65, 20));
        sizePolicy2.setHeightForWidth(cursorCh2->sizePolicy().hasHeightForWidth());
        cursorCh2->setSizePolicy(sizePolicy2);
        cursorCh2->setMinimumSize(QSize(65, 20));
        cursorCh2->setMaximumSize(QSize(65, 20));

        hboxLayout9->addWidget(groupChannel2);


        vboxLayout5->addLayout(hboxLayout9);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setSpacing(5);
        hboxLayout10->setContentsMargins(0, 0, 0, 0);
        hboxLayout10->setObjectName(QString::fromUtf8("hboxLayout10"));
        groupChannelMath = new Q3GroupBox(hantekdsowidgetbase);
        groupChannelMath->setObjectName(QString::fromUtf8("groupChannelMath"));
        sizePolicy3.setHeightForWidth(groupChannelMath->sizePolicy().hasHeightForWidth());
        groupChannelMath->setSizePolicy(sizePolicy3);
        groupChannelMath->setMinimumSize(QSize(84, 125));
        groupChannelMath->setMaximumSize(QSize(84, 125));
        QPalette palette5;
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(0), QColor(0, 0, 0));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(1), QColor(235, 235, 235));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(2), QColor(255, 255, 255));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(3), QColor(255, 255, 255));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(4), QColor(78, 78, 78));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(5), QColor(195, 195, 195));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(6), QColor(0, 0, 0));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(8), QColor(0, 0, 0));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(9), QColor(255, 255, 255));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(197, 255, 197));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(12), QColor(68, 123, 205));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette5.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(0), QColor(0, 0, 0));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(1), QColor(235, 235, 235));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(2), QColor(255, 255, 255));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(3), QColor(255, 255, 255));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(4), QColor(78, 78, 78));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(5), QColor(195, 195, 195));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(6), QColor(0, 0, 0));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(8), QColor(0, 0, 0));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(9), QColor(255, 255, 255));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(10), QColor(197, 255, 197));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(12), QColor(68, 123, 205));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette5.setColor(QPalette::Inactive, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(0), QColor(128, 128, 128));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(1), QColor(235, 235, 235));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(2), QColor(255, 255, 255));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(3), QColor(255, 255, 255));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(4), QColor(78, 78, 78));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(5), QColor(195, 195, 195));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(6), QColor(195, 195, 195));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(7), QColor(255, 255, 255));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(8), QColor(128, 128, 128));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(9), QColor(255, 255, 255));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(10), QColor(197, 255, 197));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(11), QColor(0, 0, 0));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(12), QColor(57, 102, 170));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(13), QColor(255, 255, 255));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(14), QColor(83, 83, 120));
        palette5.setColor(QPalette::Disabled, static_cast<QPalette::ColorRole>(15), QColor(0, 64, 0));
        groupChannelMath->setPalette(palette5);
        groupChannelMath->setFont(font1);
        groupChannelMath->setColumnLayout(0, Qt::Vertical);
        groupChannelMath->layout()->setSpacing(5);
        groupChannelMath->layout()->setContentsMargins(5, 5, 5, 5);
        vboxLayout6 = new QVBoxLayout();
        QBoxLayout *boxlayout = qobject_cast<QBoxLayout *>(groupChannelMath->layout());
        if (boxlayout)
            boxlayout->addLayout(vboxLayout6);
        vboxLayout6->setAlignment(Qt::AlignTop);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        comboMathType = new QComboBox(groupChannelMath);
        comboMathType->setObjectName(QString::fromUtf8("comboMathType"));
        sizePolicy2.setHeightForWidth(comboMathType->sizePolicy().hasHeightForWidth());
        comboMathType->setSizePolicy(sizePolicy2);
        comboMathType->setMinimumSize(QSize(72, 20));
        comboMathType->setMaximumSize(QSize(72, 20));

        vboxLayout6->addWidget(comboMathType);

        spacer11 = new QSpacerItem(60, 74, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout6->addItem(spacer11);


        hboxLayout10->addWidget(groupChannelMath);

        groupDisplay = new Q3GroupBox(hantekdsowidgetbase);
        groupDisplay->setObjectName(QString::fromUtf8("groupDisplay"));
        sizePolicy2.setHeightForWidth(groupDisplay->sizePolicy().hasHeightForWidth());
        groupDisplay->setSizePolicy(sizePolicy2);
        groupDisplay->setMinimumSize(QSize(84, 125));
        groupDisplay->setMaximumSize(QSize(84, 125));
        groupDisplay->setFont(font1);
        groupDisplay->setColumnLayout(0, Qt::Vertical);
        groupDisplay->layout()->setSpacing(5);
        groupDisplay->layout()->setContentsMargins(5, 5, 5, 5);
        vboxLayout7 = new QVBoxLayout();
        QBoxLayout *boxlayout1 = qobject_cast<QBoxLayout *>(groupDisplay->layout());
        if (boxlayout1)
            boxlayout1->addLayout(vboxLayout7);
        vboxLayout7->setAlignment(Qt::AlignTop);
        vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
        comboViewMode = new QComboBox(groupDisplay);
        comboViewMode->setObjectName(QString::fromUtf8("comboViewMode"));
        sizePolicy2.setHeightForWidth(comboViewMode->sizePolicy().hasHeightForWidth());
        comboViewMode->setSizePolicy(sizePolicy2);
        comboViewMode->setMinimumSize(QSize(72, 20));
        comboViewMode->setMaximumSize(QSize(72, 20));

        vboxLayout7->addWidget(comboViewMode);

        comboDisplayInterpolation = new QComboBox(groupDisplay);
        comboDisplayInterpolation->setObjectName(QString::fromUtf8("comboDisplayInterpolation"));
        sizePolicy2.setHeightForWidth(comboDisplayInterpolation->sizePolicy().hasHeightForWidth());
        comboDisplayInterpolation->setSizePolicy(sizePolicy2);
        comboDisplayInterpolation->setMinimumSize(QSize(72, 20));
        comboDisplayInterpolation->setMaximumSize(QSize(72, 20));

        vboxLayout7->addWidget(comboDisplayInterpolation);

        checkDigitalPhosphor = new QCheckBox(groupDisplay);
        checkDigitalPhosphor->setObjectName(QString::fromUtf8("checkDigitalPhosphor"));

        vboxLayout7->addWidget(checkDigitalPhosphor);

        checkDSound = new QCheckBox(groupDisplay);
        checkDSound->setObjectName(QString::fromUtf8("checkDSound"));

        vboxLayout7->addWidget(checkDSound);


        hboxLayout10->addWidget(groupDisplay);


        vboxLayout5->addLayout(hboxLayout10);

        spacer14 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacer14);


        hboxLayout->addLayout(vboxLayout5);


        vboxLayout->addLayout(hboxLayout);

        textInfo = new QLabel(hantekdsowidgetbase);
        textInfo->setObjectName(QString::fromUtf8("textInfo"));
        sizePolicy1.setHeightForWidth(textInfo->sizePolicy().hasHeightForWidth());
        textInfo->setSizePolicy(sizePolicy1);
        textInfo->setMinimumSize(QSize(0, 18));
        textInfo->setMaximumSize(QSize(32767, 18));
        QFont font2;
        font2.setFamily(QString::fromUtf8("FreeSans"));
        font2.setBold(true);
        textInfo->setFont(font2);
        textInfo->setTextFormat(Qt::AutoText);
        textInfo->setScaledContents(false);
        textInfo->setAlignment(Qt::AlignVCenter);
        textInfo->setWordWrap(true);

        vboxLayout->addWidget(textInfo);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        QWidget::setTabOrder(buttonStart, buttonStop);
        QWidget::setTabOrder(buttonStop, comboAtten1);
        QWidget::setTabOrder(comboAtten1, comboVoltage1);
        QWidget::setTabOrder(comboVoltage1, comboCoupling1);
        QWidget::setTabOrder(comboCoupling1, checkCh1Filter);
        QWidget::setTabOrder(checkCh1Filter, comboAtten2);
        QWidget::setTabOrder(comboAtten2, comboVoltage2);
        QWidget::setTabOrder(comboVoltage2, comboCoupling2);
        QWidget::setTabOrder(comboCoupling2, checkCh2Filter);
        QWidget::setTabOrder(checkCh2Filter, comboViewMode);
        QWidget::setTabOrder(comboViewMode, comboMathType);
        QWidget::setTabOrder(comboMathType, comboDisplayInterpolation);
        QWidget::setTabOrder(comboDisplayInterpolation, checkDigitalPhosphor);
        QWidget::setTabOrder(checkDigitalPhosphor, checkDSound);
        QWidget::setTabOrder(checkDSound, comboTimeBase);
        QWidget::setTabOrder(comboTimeBase, timeDiv);
        QWidget::setTabOrder(timeDiv, comboTriggerSource);
        QWidget::setTabOrder(comboTriggerSource, comboTriggerSlope);
        QWidget::setTabOrder(comboTriggerSlope, comboTriggerMode);
        QWidget::setTabOrder(comboTriggerMode, checkTrigFilter);
        QWidget::setTabOrder(checkTrigFilter, sliderCh2);
        QWidget::setTabOrder(sliderCh2, sliderCh1);
        QWidget::setTabOrder(sliderCh1, sliderTriggerPos);
        QWidget::setTabOrder(sliderTriggerPos, sliderTrigger);
        QWidget::setTabOrder(sliderTrigger, sliderChM);

        retranslateUi(hantekdsowidgetbase);
        QObject::connect(buttonStart, SIGNAL(clicked()), hantekdsowidgetbase, SLOT(buttonStart_clicked()));
        QObject::connect(buttonStop, SIGNAL(clicked()), hantekdsowidgetbase, SLOT(buttonStop_clicked()));
        QObject::connect(comboVoltage2, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboVoltage2_activated(int)));
        QObject::connect(comboAtten2, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboAtten2_activated(int)));
        QObject::connect(comboCoupling2, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboCoupling2_activated(int)));
        QObject::connect(comboTimeBase, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboTimeBase_activated(int)));
        QObject::connect(sliderCh1, SIGNAL(valueChanged(int)), hantekdsowidgetbase, SLOT(sliderCh1_valueChanged(int)));
        QObject::connect(sliderCh2, SIGNAL(valueChanged(int)), hantekdsowidgetbase, SLOT(sliderCh2_valueChanged(int)));
        QObject::connect(sliderTriggerPos, SIGNAL(valueChanged(int)), hantekdsowidgetbase, SLOT(sliderTriggerPos_valueChanged(int)));
        QObject::connect(sliderTrigger, SIGNAL(valueChanged(int)), hantekdsowidgetbase, SLOT(sliderTrigger_valueChanged(int)));
        QObject::connect(comboTriggerSource, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboTriggerSource_activated(int)));
        QObject::connect(comboTriggerSlope, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboTriggerSlope_activated(int)));
        QObject::connect(comboViewMode, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboViewMode_activated(int)));
        QObject::connect(checkDigitalPhosphor, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(checkDigitalPhosphor_stateChanged(int)));
        QObject::connect(comboDisplayInterpolation, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboDisplayInterpolation_activated(int)));
        QObject::connect(scrollShift, SIGNAL(valueChanged(int)), hantekdsowidgetbase, SLOT(scrollShift_valueChanged(int)));
        QObject::connect(comboMathType, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboMathType_activated(int)));
        QObject::connect(timeDiv, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(timeDiv_activated(int)));
        QObject::connect(checkDSound, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(checkDSound_stateChanged(int)));
        QObject::connect(comboTriggerMode, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboTriggerMode_activated(int)));
        QObject::connect(checkCh2Filter, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(checkCh2Filter_stateChanged(int)));
        QObject::connect(checkTrigFilter, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(checkTrigFilter_stateChanged(int)));
        QObject::connect(sliderChM, SIGNAL(valueChanged(int)), hantekdsowidgetbase, SLOT(sliderChM_valueChanged(int)));
        QObject::connect(checkCh1Filter, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(checkCh1Filter_stateChanged(int)));
        QObject::connect(comboCoupling1, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboCoupling1_activated(int)));
        QObject::connect(comboVoltage1, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboVoltage1_activated(int)));
        QObject::connect(comboAtten1, SIGNAL(activated(int)), hantekdsowidgetbase, SLOT(comboAtten1_activated(int)));
        QObject::connect(timeCursor, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(timeCursor_stateChanged(int)));
        QObject::connect(cursorCh1, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(cursorCh1_stateChanged(int)));
        QObject::connect(cursorCh2, SIGNAL(stateChanged(int)), hantekdsowidgetbase, SLOT(cursorCh2_stateChanged(int)));

        comboTimeBase->setCurrentIndex(6);
        comboTriggerSource->setCurrentIndex(1);
        comboTriggerMode->setCurrentIndex(1);
        comboVoltage1->setCurrentIndex(0);
        comboCoupling1->setCurrentIndex(1);
        comboVoltage2->setCurrentIndex(0);
        comboCoupling2->setCurrentIndex(1);
        comboDisplayInterpolation->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(hantekdsowidgetbase);
    } // setupUi

    void retranslateUi(QWidget *hantekdsowidgetbase)
    {
        hantekdsowidgetbase->setWindowTitle(QApplication::translate("HantekDSOWidgetBase", "hantekdsowidgetbase", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sliderCh2->setProperty("toolTip", QVariant(QApplication::translate("HantekDSOWidgetBase", "Channel 2 Offset", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        sliderCh1->setProperty("toolTip", QVariant(QApplication::translate("HantekDSOWidgetBase", "Channel 1 Offset", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        sliderTriggerPos->setProperty("toolTip", QVariant(QApplication::translate("HantekDSOWidgetBase", "Trigger Position", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        sliderTrigger->setProperty("toolTip", QVariant(QApplication::translate("HantekDSOWidgetBase", "Trigger Offset", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        sliderChM->setProperty("toolTip", QVariant(QApplication::translate("HantekDSOWidgetBase", "Math Channel Offset", 0, QApplication::UnicodeUTF8)));
#endif // QT_NO_TOOLTIP
        groupTiming->setTitle(QApplication::translate("HantekDSOWidgetBase", "Time/div, trigger, sync", 0, QApplication::UnicodeUTF8));
        comboTimeBase->clear();
        comboTimeBase->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "10\316\274s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "20\316\274s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "40\316\274s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "100\316\274s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "200\316\274s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "400\316\274s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "1ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "2ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "4ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "10ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "20ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "40ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "100ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "200ms", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "400ms", 0, QApplication::UnicodeUTF8)
        );
        timeDiv->clear();
        timeDiv->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "/1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "/400", 0, QApplication::UnicodeUTF8)
        );
        comboTriggerSource->clear();
        comboTriggerSource->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "CH2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "CH1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "EXT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "EXT/10", 0, QApplication::UnicodeUTF8)
        );
        comboTriggerSlope->clear();
        comboTriggerSlope->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "\342\236\232", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\236\230", 0, QApplication::UnicodeUTF8)
        );
        comboTriggerMode->clear();
        comboTriggerMode->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "AUTO", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "NORMAL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "SINGLE", 0, QApplication::UnicodeUTF8)
        );
        checkTrigFilter->setText(QApplication::translate("HantekDSOWidgetBase", "Filter", 0, QApplication::UnicodeUTF8));
        timeCursor->setProperty("text", QVariant(QApplication::translate("HantekDSOWidgetBase", "Cursor", 0, QApplication::UnicodeUTF8)));
        buttonStart->setText(QApplication::translate("HantekDSOWidgetBase", "ST&ART", 0, QApplication::UnicodeUTF8));
        buttonStart->setShortcut(QApplication::translate("HantekDSOWidgetBase", "Alt+A", 0, QApplication::UnicodeUTF8));
        buttonStop->setText(QApplication::translate("HantekDSOWidgetBase", "STOP", 0, QApplication::UnicodeUTF8));
        groupChannel1->setTitle(QApplication::translate("HantekDSOWidgetBase", "Channel 1", 0, QApplication::UnicodeUTF8));
        comboAtten1->clear();
        comboAtten1->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\2251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\22510", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\225100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\2251000", 0, QApplication::UnicodeUTF8)
        );
        comboVoltage1->clear();
        comboVoltage1->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "5V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "2V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "1V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "500mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "200mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "100mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "50mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "20mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "10mV", 0, QApplication::UnicodeUTF8)
        );
        comboCoupling1->clear();
        comboCoupling1->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "AC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "OFF", 0, QApplication::UnicodeUTF8)
        );
        checkCh1Filter->setText(QApplication::translate("HantekDSOWidgetBase", "Filter", 0, QApplication::UnicodeUTF8));
        cursorCh1->setProperty("text", QVariant(QApplication::translate("HantekDSOWidgetBase", "Cursor", 0, QApplication::UnicodeUTF8)));
        groupChannel2->setTitle(QApplication::translate("HantekDSOWidgetBase", "Channel 2", 0, QApplication::UnicodeUTF8));
        comboAtten2->clear();
        comboAtten2->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\2251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\22510", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\225100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "\342\234\2251000", 0, QApplication::UnicodeUTF8)
        );
        comboVoltage2->clear();
        comboVoltage2->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "5V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "2V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "1V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "500mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "200mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "100mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "50mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "20mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "10mV", 0, QApplication::UnicodeUTF8)
        );
        comboCoupling2->clear();
        comboCoupling2->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "AC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "OFF", 0, QApplication::UnicodeUTF8)
        );
        checkCh2Filter->setText(QApplication::translate("HantekDSOWidgetBase", "Filter", 0, QApplication::UnicodeUTF8));
        cursorCh2->setProperty("text", QVariant(QApplication::translate("HantekDSOWidgetBase", "Cursor", 0, QApplication::UnicodeUTF8)));
        groupChannelMath->setTitle(QApplication::translate("HantekDSOWidgetBase", "Channel M", 0, QApplication::UnicodeUTF8));
        comboMathType->clear();
        comboMathType->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "OFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "1+2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "1-2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "2-1", 0, QApplication::UnicodeUTF8)
        );
        groupDisplay->setTitle(QApplication::translate("HantekDSOWidgetBase", "Display", 0, QApplication::UnicodeUTF8));
        comboViewMode->clear();
        comboViewMode->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "X-T", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "X-Y", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "FHT", 0, QApplication::UnicodeUTF8)
        );
        comboDisplayInterpolation->clear();
        comboDisplayInterpolation->insertItems(0, QStringList()
         << QApplication::translate("HantekDSOWidgetBase", "OFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "LINEAR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HantekDSOWidgetBase", "SINC", 0, QApplication::UnicodeUTF8)
        );
        checkDigitalPhosphor->setText(QApplication::translate("HantekDSOWidgetBase", "&DPhosp", 0, QApplication::UnicodeUTF8));
        checkDigitalPhosphor->setShortcut(QApplication::translate("HantekDSOWidgetBase", "Alt+D", 0, QApplication::UnicodeUTF8));
        checkDSound->setText(QApplication::translate("HantekDSOWidgetBase", "DSo&und", 0, QApplication::UnicodeUTF8));
        checkDSound->setShortcut(QApplication::translate("HantekDSOWidgetBase", "Alt+U", 0, QApplication::UnicodeUTF8));
        textInfo->setText(QString());
    } // retranslateUi


protected:
    enum IconID
    {
        image0_ID,
        image1_ID,
        unknown_ID
    };
    static QPixmap qt_get_icon(IconID id)
    {
    static const unsigned char image0_data[] = { 
    0x78, 0x9c, 0x53, 0x4e, 0x49, 0x4d, 0xcb, 0xcc, 0x4b, 0x55, 0x48, 0x29,
    0xcd, 0xcd, 0xad, 0x8c, 0x2f, 0xcf, 0x4c, 0x29, 0xc9, 0x50, 0x30, 0xe0,
    0x52, 0x46, 0x11, 0xcd, 0x48, 0xcd, 0x4c, 0xcf, 0x28, 0x01, 0x0a, 0x17,
    0x97, 0x24, 0x96, 0x64, 0x26, 0x2b, 0x24, 0x67, 0x24, 0x16, 0x41, 0xa5,
    0x92, 0x32, 0x4b, 0x8a, 0xa3, 0x63, 0x15, 0x6c, 0x15, 0xaa, 0xb9, 0x14,
    0x14, 0x6a, 0xad, 0xb9, 0x00, 0x67, 0x11, 0x1b, 0x1f
};

    static const unsigned char image1_data[] = { 
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x16,
    0x08, 0x06, 0x00, 0x00, 0x00, 0xc4, 0xb4, 0x6c, 0x3b, 0x00, 0x00, 0x03,
    0xb1, 0x49, 0x44, 0x41, 0x54, 0x38, 0x8d, 0xad, 0x94, 0x5f, 0x4c, 0x5b,
    0x55, 0x1c, 0xc7, 0x3f, 0xe7, 0xdc, 0x4b, 0x7b, 0x4b, 0xcb, 0xa0, 0x76,
    0x2d, 0x45, 0xc4, 0x31, 0x14, 0x32, 0x35, 0x99, 0xee, 0x61, 0x92, 0x60,
    0x9c, 0x51, 0xd8, 0x83, 0x89, 0x2c, 0xe0, 0x83, 0xf1, 0x71, 0x8b, 0x3e,
    0xbb, 0x18, 0x5f, 0x8d, 0xc9, 0x1e, 0x97, 0x2c, 0xf3, 0x9d, 0x2d, 0x2a,
    0x2f, 0x1a, 0xf6, 0x64, 0xb6, 0xf1, 0xe0, 0xfe, 0x38, 0x63, 0xa0, 0x71,
    0x89, 0x69, 0x70, 0x0e, 0xb0, 0xc5, 0x21, 0x42, 0xda, 0x02, 0x42, 0xa1,
    0xbd, 0x6d, 0x69, 0x6f, 0x7b, 0xcf, 0xf1, 0x01, 0x58, 0x52, 0x03, 0xce,
    0xb8, 0xfd, 0x9e, 0xce, 0x39, 0xf9, 0x9d, 0xcf, 0xf9, 0xfe, 0x7e, 0xdf,
    0x93, 0x9f, 0x88, 0xc5, 0x62, 0xec, 0x46, 0x5f, 0x5f, 0x9f, 0xe6, 0x09,
    0x44, 0x2c, 0x16, 0x13, 0x62, 0x17, 0x3c, 0x3e, 0x3e, 0xae, 0x7b, 0x7a,
    0x7a, 0xc8, 0xe7, 0xf3, 0x64, 0x32, 0x19, 0x6c, 0xdb, 0xfe, 0x4f, 0x90,
    0x7c, 0x3e, 0x4f, 0x22, 0x91, 0x20, 0x1e, 0x8f, 0xe3, 0x38, 0xce, 0xc3,
    0x73, 0x73, 0x57, 0xe9, 0xe8, 0xe8, 0x28, 0xad, 0xed, 0x1e, 0x22, 0x9d,
    0x65, 0x0e, 0x1f, 0x2d, 0x51, 0x75, 0x4b, 0x08, 0x21, 0x10, 0x12, 0x4c,
    0x13, 0xa4, 0xdc, 0x5e, 0xa3, 0x41, 0xeb, 0x9d, 0xc2, 0x84, 0xc0, 0x55,
    0x8a, 0x85, 0x3f, 0x3c, 0xe8, 0xcb, 0x06, 0x77, 0xef, 0x50, 0x0f, 0xde,
    0x7d, 0x39, 0xd2, 0x59, 0x66, 0x79, 0xe3, 0x26, 0x59, 0x7b, 0x8e, 0x9a,
    0xbb, 0x85, 0xd7, 0xa7, 0x70, 0xab, 0x16, 0xab, 0x69, 0x83, 0xec, 0x5a,
    0x05, 0xb4, 0x87, 0xa7, 0x0e, 0x36, 0xf0, 0xf4, 0xe1, 0x0a, 0xfe, 0x40,
    0x8d, 0x6a, 0x55, 0x83, 0x10, 0x98, 0x01, 0x08, 0x47, 0x8d, 0xba, 0x4a,
    0x1e, 0x82, 0x33, 0x99, 0x0c, 0x5d, 0x47, 0x4b, 0x64, 0xed, 0x39, 0xaa,
    0x3a, 0x8f, 0xe5, 0xf3, 0x31, 0x7f, 0xbf, 0x81, 0xdb, 0xd7, 0x0b, 0xcc,
    0xfe, 0xb2, 0x05, 0x94, 0x76, 0x32, 0xfd, 0x74, 0xf6, 0x58, 0x9c, 0x1c,
    0x6e, 0xa2, 0xf7, 0x0d, 0x03, 0xa5, 0x8b, 0xa0, 0xc1, 0xf2, 0xc9, 0xbd,
    0xc1, 0xb6, 0x6d, 0xe3, 0xb8, 0x25, 0x6a, 0x6e, 0x11, 0xcb, 0xe7, 0xe3,
    0xee, 0x1d, 0x18, 0x1b, 0x59, 0x01, 0x24, 0xfe, 0x26, 0x93, 0xae, 0xee,
    0x08, 0xd2, 0x23, 0xc8, 0x2c, 0x3a, 0x2c, 0x24, 0xb7, 0xb8, 0x74, 0xbe,
    0xc8, 0xf2, 0x62, 0x88, 0x77, 0x4f, 0x7b, 0xd0, 0x54, 0x50, 0x4a, 0xef,
    0x0d, 0xde, 0x6e, 0x99, 0xc0, 0xeb, 0x83, 0xf9, 0xfb, 0x26, 0x63, 0x23,
    0xcb, 0x80, 0xa2, 0x7f, 0xb0, 0x95, 0x81, 0x41, 0x83, 0x60, 0x44, 0x60,
    0x5a, 0x2e, 0xe5, 0x52, 0x33, 0x93, 0x37, 0x1c, 0xc6, 0x46, 0xfe, 0xe2,
    0xda, 0x37, 0x19, 0x5a, 0xa3, 0x5d, 0x0c, 0x0c, 0x5b, 0x48, 0x59, 0xac,
    0x03, 0xd7, 0xe9, 0x17, 0x12, 0xdc, 0xaa, 0xc5, 0xad, 0xab, 0x36, 0x50,
    0xa3, 0xff, 0x9d, 0x08, 0xef, 0x7d, 0xd8, 0x40, 0x4b, 0xb4, 0x88, 0x69,
    0xe5, 0xd9, 0x58, 0xb5, 0xb8, 0x7d, 0xad, 0xc4, 0xc9, 0xa1, 0x46, 0x4e,
    0x9f, 0x0d, 0x03, 0x26, 0xdf, 0x7e, 0xbd, 0x86, 0xbd, 0x2e, 0x31, 0x0c,
    0xb1, 0xbf, 0x62, 0xd3, 0x84, 0xd5, 0x94, 0x41, 0xf2, 0xd7, 0x0a, 0x07,
    0x0e, 0x1c, 0x60, 0xe0, 0x94, 0x89, 0x92, 0x9b, 0x98, 0x86, 0x81, 0xbd,
    0xd9, 0xcc, 0x97, 0x17, 0x0b, 0xcc, 0x4c, 0x65, 0x59, 0x5f, 0x71, 0xf8,
    0xe0, 0xe3, 0x30, 0x13, 0x37, 0xfc, 0x24, 0xa7, 0x73, 0x24, 0x67, 0x83,
    0x18, 0x75, 0xa4, 0x7f, 0x28, 0x96, 0x52, 0xb0, 0xbe, 0x5e, 0x41, 0x51,
    0xe6, 0xd0, 0x73, 0x16, 0xc1, 0xb0, 0xc0, 0x34, 0x0d, 0x8a, 0xb9, 0x20,
    0x23, 0xe7, 0x6d, 0x66, 0xa6, 0xb2, 0x84, 0x0e, 0x36, 0xd2, 0xfb, 0x7a,
    0x13, 0xfe, 0xe6, 0x32, 0x47, 0x5e, 0x6e, 0xdc, 0x36, 0x7e, 0xa9, 0x8a,
    0x90, 0xfb, 0x98, 0xb7, 0xdd, 0x63, 0x10, 0xca, 0x03, 0x28, 0xa4, 0x47,
    0x61, 0x58, 0x2e, 0x1b, 0xab, 0x41, 0xbe, 0xfa, 0xbc, 0xc0, 0xec, 0x94,
    0x0d, 0x28, 0xbc, 0x5e, 0x93, 0xb6, 0x8e, 0x06, 0x4c, 0xab, 0x84, 0xe1,
    0xd9, 0xbe, 0xae, 0xb4, 0x89, 0x34, 0xea, 0xc1, 0xf5, 0x3b, 0x01, 0xc1,
    0xb0, 0x00, 0xfc, 0xa4, 0x96, 0xaa, 0x54, 0xb6, 0x1a, 0x99, 0xfc, 0xde,
    0x61, 0x66, 0x2a, 0x4b, 0x4b, 0x4b, 0x23, 0xd1, 0x68, 0x0b, 0xe9, 0xd4,
    0x26, 0x17, 0x3e, 0x4d, 0xf3, 0x60, 0x2a, 0x48, 0xea, 0x41, 0x19, 0x89,
    0xa4, 0xfd, 0x59, 0x0f, 0x52, 0xa8, 0xfd, 0x15, 0x6b, 0x05, 0xed, 0x9d,
    0x35, 0x0e, 0x3d, 0xef, 0xe3, 0xcf, 0xdf, 0x4b, 0x4c, 0x7c, 0xe7, 0x70,
    0xea, 0x7d, 0x3f, 0xb9, 0xf5, 0x20, 0xaf, 0xbe, 0x16, 0x20, 0xda, 0xee,
    0xe5, 0xc2, 0x67, 0x35, 0xd2, 0x0b, 0x9b, 0x9c, 0xfb, 0x68, 0x11, 0xa7,
    0x54, 0xa4, 0x39, 0xe4, 0xe5, 0xc5, 0x63, 0x9a, 0x4c, 0xaa, 0x1e, 0x5c,
    0xaf, 0x58, 0x6b, 0xfc, 0x01, 0x97, 0xb7, 0x87, 0x02, 0x00, 0x5c, 0xb9,
    0xb4, 0xca, 0xe4, 0xcd, 0x32, 0x67, 0xce, 0x86, 0x38, 0xfe, 0x96, 0x4b,
    0xd7, 0x2b, 0x39, 0x3e, 0x39, 0xd7, 0x49, 0x28, 0xd2, 0x42, 0x61, 0x73,
    0x03, 0xa7, 0x56, 0xa3, 0x7f, 0x28, 0x44, 0x47, 0x77, 0x0d, 0xcd, 0xbf,
    0xfc, 0x63, 0x84, 0xa0, 0x5a, 0x85, 0xde, 0x13, 0x06, 0xe9, 0xa5, 0x20,
    0x57, 0xc7, 0x52, 0x7c, 0x71, 0x31, 0xc3, 0xc4, 0x2d, 0x3f, 0x47, 0x5e,
    0xb2, 0x30, 0x3c, 0x82, 0xd4, 0xfc, 0x32, 0x76, 0xd6, 0x81, 0x1d, 0xb3,
    0x7e, 0xfe, 0xb1, 0x48, 0x72, 0x30, 0x82, 0xd9, 0xb0, 0x8f, 0x79, 0xf9,
    0x7c, 0x1e, 0x57, 0x29, 0x10, 0x9a, 0x9a, 0x28, 0x30, 0x7c, 0xc6, 0x22,
    0xd2, 0xd6, 0xcd, 0xf5, 0x2b, 0x2b, 0x24, 0xef, 0xe5, 0x48, 0xde, 0xdb,
    0x00, 0x14, 0x20, 0x09, 0x86, 0x2c, 0xfa, 0x87, 0x9e, 0xe1, 0xa7, 0x1f,
    0x6c, 0xec, 0x92, 0x83, 0x53, 0x51, 0x14, 0x72, 0xfb, 0xf4, 0x38, 0x91,
    0x48, 0xb0, 0xb0, 0xe0, 0xc1, 0x08, 0x08, 0x14, 0x12, 0x45, 0x8d, 0xfe,
    0x21, 0xc9, 0xf1, 0x13, 0x51, 0xe6, 0x7e, 0x73, 0x58, 0x59, 0x54, 0x68,
    0x24, 0x6d, 0x1d, 0x1e, 0x5e, 0x38, 0xa6, 0xe9, 0xe8, 0x51, 0xbc, 0x39,
    0xd8, 0x4a, 0xb5, 0x02, 0xa6, 0x69, 0x33, 0x1d, 0xaf, 0xec, 0x0d, 0x8e,
    0xc7, 0xe3, 0xe8, 0xcb, 0x06, 0xe1, 0xa8, 0x81, 0xd7, 0x27, 0xd1, 0xae,
    0x40, 0x18, 0x0a, 0x43, 0x4a, 0x8c, 0x9d, 0xb1, 0x29, 0xa5, 0x41, 0x26,
    0xad, 0x48, 0xa7, 0x35, 0x8c, 0x2b, 0x4c, 0x53, 0x52, 0xc8, 0xc3, 0x74,
    0xbc, 0xcc, 0xda, 0xb2, 0xbb, 0x37, 0xd8, 0x71, 0x9c, 0xba, 0x79, 0xfa,
    0xb8, 0x21, 0x1f, 0x9d, 0xf2, 0x18, 0xe0, 0x58, 0x2c, 0x26, 0x1e, 0x95,
    0xf8, 0xbf, 0xc0, 0x4f, 0x1a, 0x1e, 0x8b, 0xc5, 0xc4, 0xdf, 0xe0, 0xa1,
    0x90, 0x17, 0x2a, 0xf6, 0xa9, 0x69, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45,
    0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

    switch (id) {
        case image0_ID:  { QImage img; img.loadFromData(image0_data, sizeof(image0_data), "XBM.GZ"); return QPixmap::fromImage(img); }
        case image1_ID:  { QImage img; img.loadFromData(image1_data, sizeof(image1_data), "PNG"); return QPixmap::fromImage(img); }
        default: return QPixmap();
    } // switch
    } // icon

};

namespace Ui {
    class HantekDSOWidgetBase: public Ui_HantekDSOWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

class HantekDSOWidgetBase : public QWidget, public Ui::HantekDSOWidgetBase
{
    Q_OBJECT

public:
    HantekDSOWidgetBase(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
    ~HantekDSOWidgetBase();

public slots:
    virtual void button_clicked();
    virtual void buttonStart_clicked();
    virtual void buttonStop_clicked();
    virtual void comboCoupling1_activated( int );
    virtual void comboVoltage1_activated( int );
    virtual void comboVoltage2_activated( int );
    virtual void comboAtten1_activated( int );
    virtual void comboAtten2_activated( int );
    virtual void comboCoupling2_activated( int );
    virtual void comboTimeBase_activated( int );
    virtual void checkDigitalPhosphor_stateChanged( int );
    virtual void comboDisplayInterpolation_activated( int );
    virtual void sliderCh1_valueChanged( int );
    virtual void sliderCh2_valueChanged( int );
    virtual void sliderTriggerPos_valueChanged( int );
    virtual void sliderTrigger_valueChanged( int );
    virtual void comboTriggerSource_activated( int );
    virtual void comboTriggerSlope_activated( int );
    virtual void comboTriggerMode_activated( int );
    virtual void comboViewMode_activated( int );
    virtual void scrollShift_valueChanged( int );
    virtual void comboMathType_activated( const QString & );
    virtual void comboMathType_activated( int );
    virtual void timeDiv_activated( int );
    virtual void checkDSound_stateChanged( int );
    virtual void checkCh1Filter_stateChanged( int );
    virtual void checkCh2Filter_stateChanged( int );
    virtual void checkTrigFilter_stateChanged( int );
    virtual void sliderMath_valueChanged( int );
    virtual void sliderChM_valueChanged( int );
    virtual void stateChanged( int state );
    virtual void timeCursor_stateChanged( int state );
    virtual void cursorCh1_stateChanged( int state );
    virtual void cursorCh2_stateChanged( int state );

protected slots:
    virtual void languageChange();

};

#endif // HANTEKDSOWIDGETBASE_H
