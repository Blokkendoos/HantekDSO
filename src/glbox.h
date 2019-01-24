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
#ifndef _GLBOX_H_
#define _GLBOX_H_
#include <Qt/qgl.h>
//Added by qt3to4:
#include <QMouseEvent>
#include "hantekdsoathread.h"
#include "fht.h"
#include "sansfont.h"
#include "cursor.h"

#define DIVS_TIME 10.0
#define DIVS_VOLTAGE 8.0

#define DP_DEPTH 5

enum gl_object_types
{
    GLOBJ_GRID,
    GLOBJ_LAST
};

enum channels
{
    CHANNEL_CH2 = 0,
    CHANNEL_CH1
};

enum interpolation_modes
{
    INTERPOLATION_OFF = 0,
    INTERPOLATION_LINEAR,
    INTERPOLATION_SINC
};

enum view_modes
{
    VIEWMODE_XT = 0,
    VIEWMODE_XY,
    VIEWMODE_SPECTRUM
};

enum math_types
{
    MATHTYPE_OFF = 0,
    MATHTYPE_1ADD2,
    MATHTYPE_1SUB2,
    MATHTYPE_2SUB1
};

enum cursor_types
{
    CURSOR_CH2 = 0,
    CURSOR_CH1,
    CURSOR_TIME
};

#define MAX_CURSOR (MAX_CHANNELS+1)

class GLBox : public QGLWidget
{
    Q_OBJECT
public:
    GLBox(QWidget* parent, const char* name);
    GLBox(QWidget* parent);
    ~GLBox();

public:
    void setAThread(HantekDSOAThread* pAThread);
    void setActiveChannels(bool ch1Active, bool ch2Active);
    void setViewMode(int mode);
    void setMathType(int type);
    void setChMOffset(int offset);
    void setInterpolation(int state);
    void setDigitalPhosphor(int state);
    void setTimeDiv(double div);
    void setTimeShift(double shift);
    void setCursors(Cursor *cur1, Cursor *cur2, Cursor *cur3);
    
    static GLfloat getRed(channels channel);
    static GLfloat getGreen(channels channel);
    static GLfloat getBlue(channels channel);
    static GLfloat getAlpha(channels channel);
    
    static GLfloat getBorder();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    GLuint makeObject(int object);
    
    void mouseMoveEvent(QMouseEvent * e);
    void mousePressEvent(QMouseEvent * e);

private:
    HantekDSOAThread* aThread;
    GLuint gl_grid, gl_channels;
    SansFont font;
    static const GLfloat chColor[MAX_CHANNELS+1][4];
    static const GLfloat border;
    bool chActive[MAX_CHANNELS];
    Cursor* cursors[MAX_CURSOR];
    int digitalPhosphor;
    int dpIndex;
    int viewMode;
    int mathType, chMOffset;
    int interpolationMode;
    double timeDiv;
    double timeShift;
    Cursor *cursorToMove;
};


#endif // GLBOX_H
