#include <kdialog.h>
#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './hantekdsowidgetbase.ui'
**
** Created by User Interface Compiler
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "hantekdsowidgetbase.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <qscrollbar.h>
#include <qgroupbox.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "glbox.h"

/*
 *  Constructs a HantekDSOWidgetBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
HantekDSOWidgetBase::HantekDSOWidgetBase( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "hantekdsowidgetbase" );
    setEnabled( TRUE );
    hantekdsowidgetbaseLayout = new QGridLayout( this, 1, 1, 11, 3, "hantekdsowidgetbaseLayout"); 

    layout31 = new QVBoxLayout( 0, 0, 3, "layout31"); 

    layout35 = new QHBoxLayout( 0, 0, 0, "layout35"); 

    layout29 = new QVBoxLayout( 0, 0, 0, "layout29"); 
    spacer6 = new QSpacerItem( 20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout29->addItem( spacer6 );

    layout28 = new QHBoxLayout( 0, 0, 0, "layout28"); 

    sliderCh2 = new QSlider( this, "sliderCh2" );
    sliderCh2->setMinimumSize( QSize( 14, 0 ) );
    sliderCh2->setMaximumSize( QSize( 14, 32767 ) );
    sliderCh2->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    QPalette pal;
    QColorGroup cg;
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 0, 255, 255) );
    cg.setColor( QColorGroup::Light, QColor( 127, 255, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 63, 255, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 0, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 0, 170, 170) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 0, 255, 255) );
    cg.setColor( QColorGroup::Light, QColor( 127, 255, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 38, 255, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 0, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 0, 170, 170) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 0, 255, 255) );
    cg.setColor( QColorGroup::Light, QColor( 127, 255, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 38, 255, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 0, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 0, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setDisabled( cg );
    sliderCh2->setPalette( pal );
    sliderCh2->setMouseTracking( TRUE );
    sliderCh2->setMaxValue( 799 );
    sliderCh2->setLineStep( 3 );
    sliderCh2->setPageStep( 100 );
    sliderCh2->setValue( 400 );
    sliderCh2->setOrientation( QSlider::Vertical );
    sliderCh2->setTickmarks( QSlider::Below );
    layout28->addWidget( sliderCh2 );

    sliderCh1 = new QSlider( this, "sliderCh1" );
    sliderCh1->setMinimumSize( QSize( 14, 0 ) );
    sliderCh1->setMaximumSize( QSize( 14, 32767 ) );
    sliderCh1->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 255, 0, 0) );
    cg.setColor( QColorGroup::Light, QColor( 255, 127, 127) );
    cg.setColor( QColorGroup::Midlight, QColor( 255, 63, 63) );
    cg.setColor( QColorGroup::Dark, QColor( 127, 0, 0) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 0, 0) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 255, 0, 0) );
    cg.setColor( QColorGroup::Light, QColor( 255, 127, 127) );
    cg.setColor( QColorGroup::Midlight, QColor( 255, 38, 38) );
    cg.setColor( QColorGroup::Dark, QColor( 127, 0, 0) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 0, 0) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 255, 0, 0) );
    cg.setColor( QColorGroup::Light, QColor( 255, 127, 127) );
    cg.setColor( QColorGroup::Midlight, QColor( 255, 38, 38) );
    cg.setColor( QColorGroup::Dark, QColor( 127, 0, 0) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 0, 0) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setDisabled( cg );
    sliderCh1->setPalette( pal );
    sliderCh1->setMouseTracking( TRUE );
    sliderCh1->setMaxValue( 799 );
    sliderCh1->setLineStep( 3 );
    sliderCh1->setPageStep( 100 );
    sliderCh1->setValue( 400 );
    sliderCh1->setOrientation( QSlider::Vertical );
    sliderCh1->setTickmarks( QSlider::NoMarks );
    layout28->addWidget( sliderCh1 );
    layout29->addLayout( layout28 );
    layout35->addLayout( layout29 );

    layout25 = new QVBoxLayout( 0, 0, 0, "layout25"); 

    sliderTriggerPos = new QSlider( this, "sliderTriggerPos" );
    sliderTriggerPos->setMinimumSize( QSize( 0, 12 ) );
    sliderTriggerPos->setMaximumSize( QSize( 32767, 12 ) );
    sliderTriggerPos->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 170, 0, 255) );
    cg.setColor( QColorGroup::Light, QColor( 212, 127, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 191, 63, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 85, 0, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 113, 0, 170) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 170, 0, 255) );
    cg.setColor( QColorGroup::Light, QColor( 212, 127, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 183, 38, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 85, 0, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 113, 0, 170) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 170, 0, 255) );
    cg.setColor( QColorGroup::Light, QColor( 212, 127, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 183, 38, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 85, 0, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 113, 0, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setDisabled( cg );
    sliderTriggerPos->setPalette( pal );
    sliderTriggerPos->setMouseTracking( TRUE );
    sliderTriggerPos->setMaxValue( 10239 );
    sliderTriggerPos->setValue( 5120 );
    sliderTriggerPos->setOrientation( QSlider::Horizontal );
    layout25->addWidget( sliderTriggerPos );

    gLBox1 = new GLBox( this, "gLBox1" );
    gLBox1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)1, 0, 0, gLBox1->sizePolicy().hasHeightForWidth() ) );
    gLBox1->setMinimumSize( QSize( 0, 350 ) );
    layout25->addWidget( gLBox1 );
    layout35->addLayout( layout25 );

    layout33 = new QVBoxLayout( 0, 0, 0, "layout33"); 
    spacer7 = new QSpacerItem( 10, 12, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout33->addItem( spacer7 );

    sliderTrigger = new QSlider( this, "sliderTrigger" );
    sliderTrigger->setMinimumSize( QSize( 14, 0 ) );
    sliderTrigger->setMaximumSize( QSize( 14, 32767 ) );
    sliderTrigger->setPaletteBackgroundColor( QColor( 0, 0, 0 ) );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 170, 0, 255) );
    cg.setColor( QColorGroup::Light, QColor( 212, 127, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 191, 63, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 85, 0, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 113, 0, 170) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, white );
    cg.setColor( QColorGroup::Button, QColor( 170, 0, 255) );
    cg.setColor( QColorGroup::Light, QColor( 212, 127, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 183, 38, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 85, 0, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 113, 0, 170) );
    cg.setColor( QColorGroup::Text, white );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, white );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 170, 0, 255) );
    cg.setColor( QColorGroup::Light, QColor( 212, 127, 255) );
    cg.setColor( QColorGroup::Midlight, QColor( 183, 38, 255) );
    cg.setColor( QColorGroup::Dark, QColor( 85, 0, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 113, 0, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, black );
    cg.setColor( QColorGroup::Background, black );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 83, 83, 120) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 0, 64, 0) );
    pal.setDisabled( cg );
    sliderTrigger->setPalette( pal );
    sliderTrigger->setMouseTracking( TRUE );
    sliderTrigger->setMaxValue( 799 );
    sliderTrigger->setLineStep( 3 );
    sliderTrigger->setPageStep( 100 );
    sliderTrigger->setValue( 400 );
    sliderTrigger->setOrientation( QSlider::Vertical );
    sliderTrigger->setTickmarks( QSlider::NoMarks );
    layout33->addWidget( sliderTrigger );
    layout35->addLayout( layout33 );
    layout31->addLayout( layout35 );

    scrollShift = new QScrollBar( this, "scrollShift" );
    scrollShift->setMaximumSize( QSize( 32767, 32767 ) );
    QFont scrollShift_font(  scrollShift->font() );
    scrollShift_font.setFamily( "Liberation Sans" );
    scrollShift->setFont( scrollShift_font ); 
    scrollShift->setMaxValue( 32767 );
    scrollShift->setPageStep( 16 );
    scrollShift->setOrientation( QScrollBar::Horizontal );
    layout31->addWidget( scrollShift );

    layout30 = new QHBoxLayout( 0, 0, 3, "layout30"); 
    spacer3_2 = new QSpacerItem( 16, 140, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout30->addItem( spacer3_2 );

    layout29_2 = new QVBoxLayout( 0, 0, 3, "layout29_2"); 

    layout28_2 = new QHBoxLayout( 0, 0, 3, "layout28_2"); 

    groupChannel1 = new QGroupBox( this, "groupChannel1" );
    groupChannel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, groupChannel1->sizePolicy().hasHeightForWidth() ) );
    groupChannel1->setMinimumSize( QSize( 80, 118 ) );
    groupChannel1->setMaximumSize( QSize( 80, 118 ) );
    groupChannel1->setPaletteBackgroundColor( QColor( 255, 190, 190 ) );
    QFont groupChannel1_font(  groupChannel1->font() );
    groupChannel1_font.setFamily( "Liberation Sans" );
    groupChannel1->setFont( groupChannel1_font ); 
    groupChannel1->setColumnLayout(0, Qt::Vertical );
    groupChannel1->layout()->setSpacing( 5 );
    groupChannel1->layout()->setMargin( 5 );
    groupChannel1Layout = new QGridLayout( groupChannel1->layout() );
    groupChannel1Layout->setAlignment( Qt::AlignTop );

    layout22 = new QVBoxLayout( 0, 0, 3, "layout22"); 

    comboAtten1 = new QComboBox( FALSE, groupChannel1, "comboAtten1" );
    comboAtten1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboAtten1->sizePolicy().hasHeightForWidth() ) );
    comboAtten1->setMinimumSize( QSize( 65, 20 ) );
    comboAtten1->setMaximumSize( QSize( 65, 20 ) );
    QFont comboAtten1_font(  comboAtten1->font() );
    comboAtten1->setFont( comboAtten1_font ); 
    layout22->addWidget( comboAtten1 );

    comboVoltage1 = new QComboBox( FALSE, groupChannel1, "comboVoltage1" );
    comboVoltage1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboVoltage1->sizePolicy().hasHeightForWidth() ) );
    comboVoltage1->setMinimumSize( QSize( 65, 20 ) );
    comboVoltage1->setMaximumSize( QSize( 65, 20 ) );
    QFont comboVoltage1_font(  comboVoltage1->font() );
    comboVoltage1->setFont( comboVoltage1_font ); 
    layout22->addWidget( comboVoltage1 );

    comboCoupling1 = new QComboBox( FALSE, groupChannel1, "comboCoupling1" );
    comboCoupling1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboCoupling1->sizePolicy().hasHeightForWidth() ) );
    comboCoupling1->setMinimumSize( QSize( 65, 20 ) );
    comboCoupling1->setMaximumSize( QSize( 65, 20 ) );
    QFont comboCoupling1_font(  comboCoupling1->font() );
    comboCoupling1->setFont( comboCoupling1_font ); 
    layout22->addWidget( comboCoupling1 );

    checkCh1Filter = new QCheckBox( groupChannel1, "checkCh1Filter" );
    checkCh1Filter->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, checkCh1Filter->sizePolicy().hasHeightForWidth() ) );
    checkCh1Filter->setMinimumSize( QSize( 65, 20 ) );
    checkCh1Filter->setMaximumSize( QSize( 65, 20 ) );
    layout22->addWidget( checkCh1Filter );

    groupChannel1Layout->addLayout( layout22, 0, 0 );
    layout28_2->addWidget( groupChannel1 );

    groupChannel2 = new QGroupBox( this, "groupChannel2" );
    groupChannel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)4, (QSizePolicy::SizeType)4, 0, 0, groupChannel2->sizePolicy().hasHeightForWidth() ) );
    groupChannel2->setMinimumSize( QSize( 80, 118 ) );
    groupChannel2->setMaximumSize( QSize( 80, 118 ) );
    groupChannel2->setPaletteBackgroundColor( QColor( 197, 254, 255 ) );
    QFont groupChannel2_font(  groupChannel2->font() );
    groupChannel2_font.setFamily( "Liberation Sans" );
    groupChannel2->setFont( groupChannel2_font ); 
    groupChannel2->setColumnLayout(0, Qt::Vertical );
    groupChannel2->layout()->setSpacing( 5 );
    groupChannel2->layout()->setMargin( 5 );
    groupChannel2Layout = new QGridLayout( groupChannel2->layout() );
    groupChannel2Layout->setAlignment( Qt::AlignTop );

    layout23 = new QVBoxLayout( 0, 0, 3, "layout23"); 

    comboAtten2 = new QComboBox( FALSE, groupChannel2, "comboAtten2" );
    comboAtten2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboAtten2->sizePolicy().hasHeightForWidth() ) );
    comboAtten2->setMinimumSize( QSize( 65, 20 ) );
    comboAtten2->setMaximumSize( QSize( 65, 20 ) );
    QFont comboAtten2_font(  comboAtten2->font() );
    comboAtten2->setFont( comboAtten2_font ); 
    layout23->addWidget( comboAtten2 );

    comboVoltage2 = new QComboBox( FALSE, groupChannel2, "comboVoltage2" );
    comboVoltage2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboVoltage2->sizePolicy().hasHeightForWidth() ) );
    comboVoltage2->setMinimumSize( QSize( 65, 20 ) );
    comboVoltage2->setMaximumSize( QSize( 65, 20 ) );
    QFont comboVoltage2_font(  comboVoltage2->font() );
    comboVoltage2->setFont( comboVoltage2_font ); 
    layout23->addWidget( comboVoltage2 );

    comboCoupling2 = new QComboBox( FALSE, groupChannel2, "comboCoupling2" );
    comboCoupling2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboCoupling2->sizePolicy().hasHeightForWidth() ) );
    comboCoupling2->setMinimumSize( QSize( 65, 20 ) );
    comboCoupling2->setMaximumSize( QSize( 65, 20 ) );
    QFont comboCoupling2_font(  comboCoupling2->font() );
    comboCoupling2->setFont( comboCoupling2_font ); 
    layout23->addWidget( comboCoupling2 );

    checkCh2Filter = new QCheckBox( groupChannel2, "checkCh2Filter" );
    checkCh2Filter->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, checkCh2Filter->sizePolicy().hasHeightForWidth() ) );
    checkCh2Filter->setMinimumSize( QSize( 65, 20 ) );
    checkCh2Filter->setMaximumSize( QSize( 65, 20 ) );
    layout23->addWidget( checkCh2Filter );

    groupChannel2Layout->addLayout( layout23, 0, 0 );
    layout28_2->addWidget( groupChannel2 );

    groupDisplay = new QGroupBox( this, "groupDisplay" );
    groupDisplay->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, groupDisplay->sizePolicy().hasHeightForWidth() ) );
    groupDisplay->setMinimumSize( QSize( 157, 118 ) );
    groupDisplay->setMaximumSize( QSize( 157, 118 ) );
    QFont groupDisplay_font(  groupDisplay->font() );
    groupDisplay_font.setFamily( "Liberation Sans" );
    groupDisplay->setFont( groupDisplay_font ); 
    groupDisplay->setColumnLayout(0, Qt::Vertical );
    groupDisplay->layout()->setSpacing( 3 );
    groupDisplay->layout()->setMargin( 3 );
    groupDisplayLayout = new QGridLayout( groupDisplay->layout() );
    groupDisplayLayout->setAlignment( Qt::AlignTop );

    layout27 = new QVBoxLayout( 0, 0, 3, "layout27"); 

    layout15 = new QHBoxLayout( 0, 0, 3, "layout15"); 

    comboViewMode = new QComboBox( FALSE, groupDisplay, "comboViewMode" );
    comboViewMode->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboViewMode->sizePolicy().hasHeightForWidth() ) );
    comboViewMode->setMinimumSize( QSize( 72, 20 ) );
    comboViewMode->setMaximumSize( QSize( 72, 20 ) );
    QFont comboViewMode_font(  comboViewMode->font() );
    comboViewMode->setFont( comboViewMode_font ); 
    layout15->addWidget( comboViewMode );

    comboMathType = new QComboBox( FALSE, groupDisplay, "comboMathType" );
    comboMathType->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboMathType->sizePolicy().hasHeightForWidth() ) );
    comboMathType->setMinimumSize( QSize( 72, 20 ) );
    comboMathType->setMaximumSize( QSize( 72, 20 ) );
    QFont comboMathType_font(  comboMathType->font() );
    comboMathType->setFont( comboMathType_font ); 
    layout15->addWidget( comboMathType );
    layout27->addLayout( layout15 );

    layout23_2 = new QHBoxLayout( 0, 0, 3, "layout23_2"); 

    comboDisplayInterpolation = new QComboBox( FALSE, groupDisplay, "comboDisplayInterpolation" );
    comboDisplayInterpolation->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboDisplayInterpolation->sizePolicy().hasHeightForWidth() ) );
    comboDisplayInterpolation->setMinimumSize( QSize( 72, 20 ) );
    comboDisplayInterpolation->setMaximumSize( QSize( 72, 20 ) );
    QFont comboDisplayInterpolation_font(  comboDisplayInterpolation->font() );
    comboDisplayInterpolation->setFont( comboDisplayInterpolation_font ); 
    layout23_2->addWidget( comboDisplayInterpolation );
    spacer9_2 = new QSpacerItem( 71, 21, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout23_2->addItem( spacer9_2 );
    layout27->addLayout( layout23_2 );

    layout24 = new QHBoxLayout( 0, 0, 3, "layout24"); 

    checkDigitalPhosphor = new QCheckBox( groupDisplay, "checkDigitalPhosphor" );
    layout24->addWidget( checkDigitalPhosphor );

    checkDSound = new QCheckBox( groupDisplay, "checkDSound" );
    layout24->addWidget( checkDSound );
    layout27->addLayout( layout24 );
    spacer10_2 = new QSpacerItem( 140, 20, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout27->addItem( spacer10_2 );

    groupDisplayLayout->addLayout( layout27, 0, 0 );
    layout28_2->addWidget( groupDisplay );

    groupTiming = new QGroupBox( this, "groupTiming" );
    groupTiming->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, groupTiming->sizePolicy().hasHeightForWidth() ) );
    groupTiming->setMinimumSize( QSize( 0, 93 ) );
    groupTiming->setMaximumSize( QSize( 32767, 118 ) );
    QFont groupTiming_font(  groupTiming->font() );
    groupTiming_font.setFamily( "Liberation Sans" );
    groupTiming->setFont( groupTiming_font ); 
    groupTiming->setColumnLayout(0, Qt::Vertical );
    groupTiming->layout()->setSpacing( 3 );
    groupTiming->layout()->setMargin( 3 );
    groupTimingLayout = new QGridLayout( groupTiming->layout() );
    groupTimingLayout->setAlignment( Qt::AlignTop );

    layout35_2 = new QHBoxLayout( 0, 0, 3, "layout35_2"); 

    layout34 = new QVBoxLayout( 0, 0, 3, "layout34"); 

    layout65 = new QHBoxLayout( 0, 0, 3, "layout65"); 

    comboTimeBase = new QComboBox( FALSE, groupTiming, "comboTimeBase" );
    comboTimeBase->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboTimeBase->sizePolicy().hasHeightForWidth() ) );
    comboTimeBase->setMinimumSize( QSize( 60, 20 ) );
    comboTimeBase->setMaximumSize( QSize( 60, 20 ) );
    QFont comboTimeBase_font(  comboTimeBase->font() );
    comboTimeBase->setFont( comboTimeBase_font ); 
    layout65->addWidget( comboTimeBase );

    timeDiv = new QComboBox( FALSE, groupTiming, "timeDiv" );
    timeDiv->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, timeDiv->sizePolicy().hasHeightForWidth() ) );
    timeDiv->setMinimumSize( QSize( 50, 20 ) );
    timeDiv->setMaximumSize( QSize( 50, 20 ) );
    layout65->addWidget( timeDiv );
    spacer18 = new QSpacerItem( 21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout65->addItem( spacer18 );
    layout34->addLayout( layout65 );

    layout61 = new QHBoxLayout( 0, 0, 3, "layout61"); 

    comboTriggerSource = new QComboBox( FALSE, groupTiming, "comboTriggerSource" );
    comboTriggerSource->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboTriggerSource->sizePolicy().hasHeightForWidth() ) );
    comboTriggerSource->setMinimumSize( QSize( 70, 20 ) );
    comboTriggerSource->setMaximumSize( QSize( 70, 20 ) );
    QFont comboTriggerSource_font(  comboTriggerSource->font() );
    comboTriggerSource->setFont( comboTriggerSource_font ); 
    layout61->addWidget( comboTriggerSource );

    comboTriggerSlope = new QComboBox( FALSE, groupTiming, "comboTriggerSlope" );
    comboTriggerSlope->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboTriggerSlope->sizePolicy().hasHeightForWidth() ) );
    comboTriggerSlope->setMinimumSize( QSize( 35, 20 ) );
    comboTriggerSlope->setMaximumSize( QSize( 35, 20 ) );
    QFont comboTriggerSlope_font(  comboTriggerSlope->font() );
    comboTriggerSlope->setFont( comboTriggerSlope_font ); 
    layout61->addWidget( comboTriggerSlope );
    spacer10 = new QSpacerItem( 22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout61->addItem( spacer10 );
    layout34->addLayout( layout61 );

    layout26 = new QHBoxLayout( 0, 0, 3, "layout26"); 

    comboTriggerMode = new QComboBox( FALSE, groupTiming, "comboTriggerMode" );
    comboTriggerMode->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, comboTriggerMode->sizePolicy().hasHeightForWidth() ) );
    comboTriggerMode->setMinimumSize( QSize( 80, 20 ) );
    comboTriggerMode->setMaximumSize( QSize( 80, 20 ) );
    QFont comboTriggerMode_font(  comboTriggerMode->font() );
    comboTriggerMode->setFont( comboTriggerMode_font ); 
    layout26->addWidget( comboTriggerMode );
    spacer9 = new QSpacerItem( 30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout26->addItem( spacer9 );
    layout34->addLayout( layout26 );

    layout24_2 = new QHBoxLayout( 0, 0, 3, "layout24_2"); 

    checkTrigFilter = new QCheckBox( groupTiming, "checkTrigFilter" );
    checkTrigFilter->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, checkTrigFilter->sizePolicy().hasHeightForWidth() ) );
    checkTrigFilter->setMinimumSize( QSize( 65, 20 ) );
    checkTrigFilter->setMaximumSize( QSize( 65, 20 ) );
    layout24_2->addWidget( checkTrigFilter );
    spacer9_3 = new QSpacerItem( 60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout24_2->addItem( spacer9_3 );
    layout34->addLayout( layout24_2 );
    layout35_2->addLayout( layout34 );

    layout24_3 = new QVBoxLayout( 0, 0, 3, "layout24_3"); 

    buttonStart = new QPushButton( groupTiming, "buttonStart" );
    buttonStart->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, buttonStart->sizePolicy().hasHeightForWidth() ) );
    buttonStart->setMinimumSize( QSize( 52, 39 ) );
    buttonStart->setMaximumSize( QSize( 52, 40 ) );
    QFont buttonStart_font(  buttonStart->font() );
    buttonStart->setFont( buttonStart_font ); 
    layout24_3->addWidget( buttonStart );

    buttonStop = new QPushButton( groupTiming, "buttonStop" );
    buttonStop->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, buttonStop->sizePolicy().hasHeightForWidth() ) );
    buttonStop->setMinimumSize( QSize( 52, 40 ) );
    buttonStop->setMaximumSize( QSize( 52, 40 ) );
    QFont buttonStop_font(  buttonStop->font() );
    buttonStop->setFont( buttonStop_font ); 
    layout24_3->addWidget( buttonStop );
    layout35_2->addLayout( layout24_3 );

    groupTimingLayout->addLayout( layout35_2, 0, 0 );
    layout28_2->addWidget( groupTiming );
    layout29_2->addLayout( layout28_2 );

    textInfo = new QLabel( this, "textInfo" );
    textInfo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textInfo->sizePolicy().hasHeightForWidth() ) );
    textInfo->setMinimumSize( QSize( 0, 18 ) );
    textInfo->setMaximumSize( QSize( 32767, 18 ) );
    QFont textInfo_font(  textInfo->font() );
    textInfo_font.setFamily( "FreeSans" );
    textInfo_font.setBold( TRUE );
    textInfo->setFont( textInfo_font ); 
    textInfo->setFrameShape( QLabel::GroupBoxPanel );
    textInfo->setTextFormat( QLabel::AutoText );
    textInfo->setScaledContents( FALSE );
    textInfo->setAlignment( int( QLabel::WordBreak | QLabel::AlignVCenter ) );
    layout29_2->addWidget( textInfo );
    layout30->addLayout( layout29_2 );
    spacer3 = new QSpacerItem( 16, 140, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout30->addItem( spacer3 );
    layout31->addLayout( layout30 );

    hantekdsowidgetbaseLayout->addLayout( layout31, 0, 0 );
    languageChange();
    resize( QSize(600, 555).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( buttonStart, SIGNAL( clicked() ), this, SLOT( buttonStart_clicked() ) );
    connect( buttonStop, SIGNAL( clicked() ), this, SLOT( buttonStop_clicked() ) );
    connect( comboCoupling1, SIGNAL( activated(int) ), this, SLOT( comboCoupling1_activated(int) ) );
    connect( comboVoltage1, SIGNAL( activated(int) ), this, SLOT( comboVoltage1_activated(int) ) );
    connect( comboVoltage2, SIGNAL( activated(int) ), this, SLOT( comboVoltage2_activated(int) ) );
    connect( comboCoupling2, SIGNAL( activated(int) ), this, SLOT( comboCoupling2_activated(int) ) );
    connect( comboTimeBase, SIGNAL( activated(int) ), this, SLOT( comboTimeBase_activated(int) ) );
    connect( sliderCh1, SIGNAL( valueChanged(int) ), this, SLOT( sliderCh1_valueChanged(int) ) );
    connect( sliderCh2, SIGNAL( valueChanged(int) ), this, SLOT( sliderCh2_valueChanged(int) ) );
    connect( sliderTriggerPos, SIGNAL( valueChanged(int) ), this, SLOT( sliderTriggerPos_valueChanged(int) ) );
    connect( sliderTrigger, SIGNAL( valueChanged(int) ), this, SLOT( sliderTrigger_valueChanged(int) ) );
    connect( comboTriggerSource, SIGNAL( activated(int) ), this, SLOT( comboTriggerSource_activated(int) ) );
    connect( comboTriggerSlope, SIGNAL( activated(int) ), this, SLOT( comboTriggerSlope_activated(int) ) );
    connect( comboViewMode, SIGNAL( activated(int) ), this, SLOT( comboViewMode_activated(int) ) );
    connect( checkDigitalPhosphor, SIGNAL( stateChanged(int) ), this, SLOT( checkDigitalPhosphor_stateChanged(int) ) );
    connect( comboDisplayInterpolation, SIGNAL( activated(int) ), this, SLOT( comboDisplayInterpolation_activated(int) ) );
    connect( scrollShift, SIGNAL( valueChanged(int) ), this, SLOT( scrollShift_valueChanged(int) ) );
    connect( comboMathType, SIGNAL( activated(int) ), this, SLOT( comboMathType_activated(int) ) );
    connect( timeDiv, SIGNAL( activated(int) ), this, SLOT( timeDiv_activated(int) ) );
    connect( checkDSound, SIGNAL( stateChanged(int) ), this, SLOT( checkDSound_stateChanged(int) ) );
    connect( comboTriggerMode, SIGNAL( activated(int) ), this, SLOT( comboTriggerMode_activated(int) ) );
    connect( checkCh1Filter, SIGNAL( stateChanged(int) ), this, SLOT( checkCh1Filter_stateChanged(int) ) );
    connect( checkCh2Filter, SIGNAL( stateChanged(int) ), this, SLOT( checkCh2Filter_stateChanged(int) ) );
    connect( checkTrigFilter, SIGNAL( stateChanged(int) ), this, SLOT( checkTrigFilter_stateChanged(int) ) );
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
    setCaption( tr2i18n( "hantekdsowidgetbase" ) );
    groupChannel1->setTitle( tr2i18n( "Channel 1" ) );
    comboAtten1->clear();
    comboAtten1->insertItem( tr2i18n( "✕1" ) );
    comboAtten1->insertItem( tr2i18n( "✕10" ) );
    comboAtten1->insertItem( tr2i18n( "✕100" ) );
    comboAtten1->insertItem( tr2i18n( "✕1000" ) );
    comboVoltage1->clear();
    comboVoltage1->insertItem( tr2i18n( "5V" ) );
    comboVoltage1->insertItem( tr2i18n( "2V" ) );
    comboVoltage1->insertItem( tr2i18n( "1V" ) );
    comboVoltage1->insertItem( tr2i18n( "500mV" ) );
    comboVoltage1->insertItem( tr2i18n( "200mV" ) );
    comboVoltage1->insertItem( tr2i18n( "100mV" ) );
    comboVoltage1->insertItem( tr2i18n( "50mV" ) );
    comboVoltage1->insertItem( tr2i18n( "20mV" ) );
    comboVoltage1->insertItem( tr2i18n( "10mV" ) );
    comboVoltage1->setCurrentItem( 0 );
    comboCoupling1->clear();
    comboCoupling1->insertItem( tr2i18n( "AC" ) );
    comboCoupling1->insertItem( tr2i18n( "DC" ) );
    comboCoupling1->insertItem( tr2i18n( "OFF" ) );
    comboCoupling1->setCurrentItem( 1 );
    checkCh1Filter->setText( tr2i18n( "Filter" ) );
    groupChannel2->setTitle( tr2i18n( "Channel 2" ) );
    comboAtten2->clear();
    comboAtten2->insertItem( tr2i18n( "✕1" ) );
    comboAtten2->insertItem( tr2i18n( "✕10" ) );
    comboAtten2->insertItem( tr2i18n( "✕100" ) );
    comboAtten2->insertItem( tr2i18n( "✕1000" ) );
    comboVoltage2->clear();
    comboVoltage2->insertItem( tr2i18n( "5V" ) );
    comboVoltage2->insertItem( tr2i18n( "2V" ) );
    comboVoltage2->insertItem( tr2i18n( "1V" ) );
    comboVoltage2->insertItem( tr2i18n( "500mV" ) );
    comboVoltage2->insertItem( tr2i18n( "200mV" ) );
    comboVoltage2->insertItem( tr2i18n( "100mV" ) );
    comboVoltage2->insertItem( tr2i18n( "50mV" ) );
    comboVoltage2->insertItem( tr2i18n( "20mV" ) );
    comboVoltage2->insertItem( tr2i18n( "10mV" ) );
    comboVoltage2->setCurrentItem( 0 );
    comboCoupling2->clear();
    comboCoupling2->insertItem( tr2i18n( "AC" ) );
    comboCoupling2->insertItem( tr2i18n( "DC" ) );
    comboCoupling2->insertItem( tr2i18n( "OFF" ) );
    comboCoupling2->setCurrentItem( 1 );
    checkCh2Filter->setText( tr2i18n( "Filter" ) );
    groupDisplay->setTitle( tr2i18n( "Display" ) );
    comboViewMode->clear();
    comboViewMode->insertItem( tr2i18n( "X-T" ) );
    comboViewMode->insertItem( tr2i18n( "X-Y" ) );
    comboViewMode->insertItem( tr2i18n( "FHT" ) );
    comboMathType->clear();
    comboMathType->insertItem( tr2i18n( "OFF" ) );
    comboMathType->insertItem( tr2i18n( "1+2" ) );
    comboMathType->insertItem( tr2i18n( "1-2" ) );
    comboMathType->insertItem( tr2i18n( "2-1" ) );
    comboDisplayInterpolation->clear();
    comboDisplayInterpolation->insertItem( tr2i18n( "OFF" ) );
    comboDisplayInterpolation->insertItem( tr2i18n( "LINEAR" ) );
    comboDisplayInterpolation->insertItem( tr2i18n( "SINC" ) );
    comboDisplayInterpolation->setCurrentItem( 1 );
    checkDigitalPhosphor->setText( tr2i18n( "DPhosp" ) );
    checkDSound->setText( tr2i18n( "DSound" ) );
    groupTiming->setTitle( tr2i18n( "Time/div, trigger, sync" ) );
    comboTimeBase->clear();
    comboTimeBase->insertItem( tr2i18n( "10μs" ) );
    comboTimeBase->insertItem( tr2i18n( "20μs" ) );
    comboTimeBase->insertItem( tr2i18n( "40μs" ) );
    comboTimeBase->insertItem( tr2i18n( "100μs" ) );
    comboTimeBase->insertItem( tr2i18n( "200μs" ) );
    comboTimeBase->insertItem( tr2i18n( "400μs" ) );
    comboTimeBase->insertItem( tr2i18n( "1ms" ) );
    comboTimeBase->insertItem( tr2i18n( "2ms" ) );
    comboTimeBase->insertItem( tr2i18n( "4ms" ) );
    comboTimeBase->insertItem( tr2i18n( "10ms" ) );
    comboTimeBase->insertItem( tr2i18n( "20ms" ) );
    comboTimeBase->insertItem( tr2i18n( "40ms" ) );
    comboTimeBase->insertItem( tr2i18n( "100ms" ) );
    comboTimeBase->insertItem( tr2i18n( "200ms" ) );
    comboTimeBase->insertItem( tr2i18n( "400ms" ) );
    comboTimeBase->setCurrentItem( 6 );
    timeDiv->clear();
    timeDiv->insertItem( tr2i18n( "/1" ) );
    timeDiv->insertItem( tr2i18n( "/2" ) );
    timeDiv->insertItem( tr2i18n( "/4" ) );
    timeDiv->insertItem( tr2i18n( "/10" ) );
    timeDiv->insertItem( tr2i18n( "/20" ) );
    timeDiv->insertItem( tr2i18n( "/40" ) );
    timeDiv->insertItem( tr2i18n( "/100" ) );
    timeDiv->insertItem( tr2i18n( "/200" ) );
    timeDiv->insertItem( tr2i18n( "/400" ) );
    comboTriggerSource->clear();
    comboTriggerSource->insertItem( tr2i18n( "CH2" ) );
    comboTriggerSource->insertItem( tr2i18n( "CH1" ) );
    comboTriggerSource->insertItem( tr2i18n( "EXT" ) );
    comboTriggerSource->insertItem( tr2i18n( "EXT/10" ) );
    comboTriggerSlope->clear();
    comboTriggerSlope->insertItem( tr2i18n( "➚" ) );
    comboTriggerSlope->insertItem( tr2i18n( "➘" ) );
    comboTriggerMode->clear();
    comboTriggerMode->insertItem( tr2i18n( "AUTO" ) );
    comboTriggerMode->insertItem( tr2i18n( "NORMAL" ) );
    comboTriggerMode->insertItem( tr2i18n( "SINGLE" ) );
    checkTrigFilter->setText( tr2i18n( "Filter" ) );
    buttonStart->setText( tr2i18n( "START" ) );
    buttonStop->setText( tr2i18n( "STOP" ) );
    textInfo->setText( QString::null );
}

void HantekDSOWidgetBase::button_clicked()
{
    qWarning( "HantekDSOWidgetBase::button_clicked(): Not implemented yet" );
}

void HantekDSOWidgetBase::buttonStart_clicked()
{
    qWarning( "HantekDSOWidgetBase::buttonStart_clicked(): Not implemented yet" );
}

void HantekDSOWidgetBase::buttonStop_clicked()
{
    qWarning( "HantekDSOWidgetBase::buttonStop_clicked(): Not implemented yet" );
}

void HantekDSOWidgetBase::comboCoupling1_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboCoupling1_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboVoltage1_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboVoltage1_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboVoltage2_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboVoltage2_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboCoupling2_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboCoupling2_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboTimeBase_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboTimeBase_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::checkDigitalPhosphor_stateChanged(int)
{
    qWarning( "HantekDSOWidgetBase::checkDigitalPhosphor_stateChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboDisplayInterpolation_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboDisplayInterpolation_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::sliderCh1_valueChanged(int)
{
    qWarning( "HantekDSOWidgetBase::sliderCh1_valueChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::sliderCh2_valueChanged(int)
{
    qWarning( "HantekDSOWidgetBase::sliderCh2_valueChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::sliderTriggerPos_valueChanged(int)
{
    qWarning( "HantekDSOWidgetBase::sliderTriggerPos_valueChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::sliderTrigger_valueChanged(int)
{
    qWarning( "HantekDSOWidgetBase::sliderTrigger_valueChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboTriggerSource_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboTriggerSource_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboTriggerSlope_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboTriggerSlope_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboTriggerMode_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboTriggerMode_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboViewMode_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboViewMode_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::scrollShift_valueChanged(int)
{
    qWarning( "HantekDSOWidgetBase::scrollShift_valueChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::comboMathType_activated(const QString&)
{
    qWarning( "HantekDSOWidgetBase::comboMathType_activated(const QString&): Not implemented yet" );
}

void HantekDSOWidgetBase::comboMathType_activated(int)
{
    qWarning( "HantekDSOWidgetBase::comboMathType_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::timeDiv_activated(int)
{
    qWarning( "HantekDSOWidgetBase::timeDiv_activated(int): Not implemented yet" );
}

void HantekDSOWidgetBase::checkDSound_stateChanged(int)
{
    qWarning( "HantekDSOWidgetBase::checkDSound_stateChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::checkCh1Filter_stateChanged(int)
{
    qWarning( "HantekDSOWidgetBase::checkCh1Filter_stateChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::checkCh2Filter_stateChanged(int)
{
    qWarning( "HantekDSOWidgetBase::checkCh2Filter_stateChanged(int): Not implemented yet" );
}

void HantekDSOWidgetBase::checkTrigFilter_stateChanged(int)
{
    qWarning( "HantekDSOWidgetBase::checkTrigFilter_stateChanged(int): Not implemented yet" );
}

#include "hantekdsowidgetbase.moc"
