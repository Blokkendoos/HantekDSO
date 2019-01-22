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
#include "glbox.h"
#include "hantekdsoathread.h"
#include "fht.h"
#include <math.h>

const GLfloat GLBox::chColor[MAX_CHANNELS+1][4] = {
    {0.0, 1.0, 1.0, 1.0}, // CH2 Color
    {1.0, 0.0, 0.0, 1.0}, // CH1 Color
    {0.0, 1.0, 0.0, 1.0}  // CHM Color
};

GLBox::GLBox(QWidget* parent, const char* name) : QGLWidget(parent, name),
    aThread(0), gl_grid(0), digitalPhosphor(0), dpIndex(0), viewMode(VIEWMODE_XT),
    mathType(MATHTYPE_OFF), chMOffset(0), interpolationMode(INTERPOLATION_LINEAR),
    timeDiv(1), timeShift(0)
{
}

GLBox::~GLBox()
{
    makeCurrent();

    if (gl_channels)
    {
        glDeleteLists(gl_channels, DP_DEPTH*(MAX_CHANNELS+1));
    }

    if (gl_grid)
    {
        glDeleteLists(gl_grid, GLOBJ_LAST);
    }
}

void GLBox::initializeGL()
{
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//    glEnable(GL_POINT_SMOOTH);
    glPointSize(1);

    qglClearColor(black);
    gl_grid = makeObject(GLOBJ_GRID);
    gl_channels = glGenLists(DP_DEPTH*(MAX_CHANNELS+1));
    glShadeModel(GL_SMOOTH/*GL_FLAT*/);
    glLineStipple (1, 0x00FF);

    font.init();
}

void GLBox::paintGL()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScalef(1.0, 1.0, 1.0);

    if (aThread)
    {
        unsigned samplesInBuffer = aThread->bufferSize;
        unsigned samplesInScale = 10000;
        unsigned samplesInvisible = samplesInBuffer - samplesInScale;
        unsigned viewLen = (unsigned)(samplesInScale/timeDiv);
        unsigned restLen = samplesInScale - viewLen;
        unsigned viewPos = (unsigned)(restLen*timeShift) + samplesInvisible/2;

        unsigned samplesToTransform = aThread->transformSize;
        unsigned samplesUntransformed = samplesInBuffer - samplesToTransform;
        unsigned transformedSamples = samplesToTransform/2;
        unsigned transformViewLen = (unsigned)(transformedSamples/timeDiv);
        unsigned transformRestLen = transformedSamples - transformViewLen;
        unsigned transformViewPos = (unsigned)(transformRestLen*timeShift);

        QString str;

        switch(viewMode)
        {
            case VIEWMODE_XT:
                aThread->bufferMutex.lock();
                for (int t = 0 ; t < MAX_CHANNELS; t++)
                {
                    if (chActive[t])
                    {
                        glNewList(gl_channels + dpIndex*MAX_CHANNELS + t, GL_COMPILE);
                        glBegin((interpolationMode == INTERPOLATION_OFF)?GL_POINTS:GL_LINE_STRIP);
                        unsigned p = aThread->triggerPoint + viewPos;
                        for (unsigned i = 0; i < viewLen; i++)
                        {
                            if (p >= samplesInBuffer)
                            {
                                p -= samplesInBuffer;
                            }
                            glVertex2f(i, aThread->buffer[p++][t]);
                        }
                        glEnd();
                        glEndList();
                    }
                }
                if (mathType != MATHTYPE_OFF)
                {
                    glNewList(gl_channels + dpIndex*MAX_CHANNELS + MAX_CHANNELS, GL_COMPILE);
                    glBegin((interpolationMode == INTERPOLATION_OFF)?GL_POINTS:GL_LINE_STRIP);
                    unsigned p = aThread->triggerPoint + viewPos;
                    for (unsigned i = 0; i < viewLen; i++)
                    {
                        if (p >= samplesInBuffer)
                        {
                            p -= samplesInBuffer;
                        }
                        int ch2Val = aThread->buffer[p][0] - VOLTAGE_SCALE/2;
                        int ch1Val = aThread->buffer[p++][1] - VOLTAGE_SCALE/2;
                        switch(mathType)
                        {
                            case MATHTYPE_1ADD2:
                                glVertex2f(i, ch1Val + ch2Val + chMOffset);
                                break;
                            case MATHTYPE_1SUB2:
                                glVertex2f(i, ch1Val - ch2Val + chMOffset);
                                break;
                            case MATHTYPE_2SUB1:
                                glVertex2f(i, ch2Val - ch1Val + chMOffset);
                                break;
                        }
                    }
                    glEnd();
                    glEndList();
                }
                aThread->bufferMutex.unlock();

                glPushMatrix();
                glTranslatef(-DIVS_TIME/2, -DIVS_VOLTAGE/2, 0);
                glScalef(DIVS_TIME*timeDiv/samplesInScale, DIVS_VOLTAGE/VOLTAGE_SCALE, 1.0);

                glEnable(GL_LINE_SMOOTH);
                glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

                for (int t = 0 ; t < MAX_CHANNELS; t++)
                {
                    if (chActive[t])
                    {
                        for (int i = (digitalPhosphor?DP_DEPTH:0); i >= 0; i--)
                        {
                            glColor4f(chColor[t][0], chColor[t][1], chColor[t][2],
                                chColor[t][3] - 0.7*log(i + 1));
                            int index = (dpIndex + i) % DP_DEPTH;
                            glCallList(gl_channels + index*MAX_CHANNELS + t);
                        }
                    }
                }
                if (mathType != MATHTYPE_OFF)
                {
                    // TODO: find error in math channel digital phosphor code
                    for (int i = (digitalPhosphor?DP_DEPTH:0); i >= 0; i--)
                    {
                        glColor4f(chColor[MAX_CHANNELS][0], chColor[MAX_CHANNELS][1],
                            chColor[MAX_CHANNELS][2], chColor[MAX_CHANNELS][3] - 0.7*log(i + 1));
                        int index = (dpIndex + i) % DP_DEPTH;
                        glCallList(gl_channels + index*MAX_CHANNELS + MAX_CHANNELS);
                    }
                }
                if (digitalPhosphor)
                {
                    if (++dpIndex >= DP_DEPTH)
                    {
                        dpIndex = 0;
                    }
                }

                glPopMatrix();
/*
                glPushMatrix();
                glColor4f(0.0, 1.0, 0.0, 1.0);
                glTranslatef(-DIVS_TIME/2, -DIVS_VOLTAGE/2, 0.0);
                str=QString("%1").arg("400ms");
                font.glString(str, 0.3);
                glPopMatrix();
*/
                glDisable(GL_LINE_SMOOTH);
                glCallList(gl_grid);    // Draw grid
                break;

            case VIEWMODE_XY:
                glDisable(GL_LINE_SMOOTH);
                glCallList(gl_grid);
                break;

            case VIEWMODE_SPECTRUM:
                aThread->bufferMutex.lock();
                unsigned p = aThread->triggerPoint + samplesUntransformed/2;
                for (unsigned i = 0; i < samplesToTransform; i++, p++)
                {
                    if (p >= samplesInBuffer)
                    {
                        p -= samplesInBuffer;
                    }
                    for (int t = 0; t < MAX_CHANNELS; t++)
                    {
                        aThread->fhtBuffer[t][i] = (double)aThread->buffer[p][t];
                    }
                }
                aThread->transform();
                aThread->bufferMutex.unlock();

                glPushMatrix();
                glTranslatef(-DIVS_TIME/2, -DIVS_VOLTAGE/2, 0);
                glScalef(DIVS_TIME*timeDiv/transformedSamples, DIVS_VOLTAGE, 1.0);
                glLineWidth(1);
                for (int t = 0; t < MAX_CHANNELS; t++)
                {
                    glColor4f(chColor[t][0], chColor[t][1], chColor[t][2], chColor[t][3]);
                    glBegin((interpolationMode == INTERPOLATION_OFF)?GL_LINES:GL_QUADS);
                    GLfloat viewLen = transformViewLen;
                    if (interpolationMode != INTERPOLATION_OFF)
                    {
                        viewLen--;
                    }
                    for (unsigned i = 0; i < viewLen; i++)
                    {
                        glVertex2f(i, 0);
                        glVertex2f(i, aThread->fhtBuffer[t][i+transformViewPos]);
                        if (interpolationMode != INTERPOLATION_OFF)
                        {
                            glVertex2f(i+1, aThread->fhtBuffer[t][i+transformViewPos]);
                            glVertex2f(i+1, 0);
                        }
                    }
                    glEnd();
                }
                glPopMatrix();
                glDisable(GL_LINE_SMOOTH);
                glCallList(gl_grid);    // Draw grid
                break;
        }
    }
    glPopMatrix();
}

void GLBox::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-DIVS_TIME/2 - 0.1, DIVS_TIME/2 + 0.1, -DIVS_VOLTAGE/2 - 0.1, DIVS_VOLTAGE/2 + 0.1, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void GLBox::setAThread(HantekDSOAThread* pAThread)
{
    aThread = pAThread;
}

void GLBox::setActiveChannels(bool ch1Active, bool ch2Active)
{
    chActive[0] = ch2Active;
    chActive[1] = ch1Active;
}

void GLBox::setViewMode(int mode)
{
    viewMode = mode;
    updateGL();
}

void GLBox::setMathType(int type)
{
    mathType = type;
    updateGL();
}

void GLBox::setChMOffset(int offset)
{
    chMOffset = offset;
    updateGL();
}

void GLBox::setInterpolation(int state)
{
    interpolationMode = state;
    updateGL();
}

void GLBox::setDigitalPhosphor(int state)
{
    digitalPhosphor = state;
    updateGL();
}

GLuint GLBox::makeObject(int object)
{
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glLineWidth(1);
    switch (object)
    {
        case GLOBJ_GRID:
            glColor4f(0.7, 0.7, 0.7, 0.5);  // Grid Color
            glEnable(GL_LINE_STIPPLE);
            glBegin(GL_LINES);
            for(GLfloat i=1; i<=DIVS_TIME/2; i++)
            {
                glVertex2f(i, -DIVS_VOLTAGE/2);
                glVertex2f(i, DIVS_VOLTAGE/2);
                glVertex2f(-i, -DIVS_VOLTAGE/2);
                glVertex2f(-i, DIVS_VOLTAGE/2);
            }
            for(GLfloat i=1; i<=DIVS_VOLTAGE/2; i++)
            {
                glVertex2f(-DIVS_TIME/2, i);
                glVertex2f(DIVS_TIME/2, i);
                glVertex2f(-DIVS_TIME/2, -i);
                glVertex2f(DIVS_TIME/2, -i);
            }
            glEnd();
            glColor4f(1.0, 1.0, 1.0, 0.5);  // Axis Color
            glDisable(GL_LINE_STIPPLE);
            glBegin(GL_LINES);
            glVertex2f(-DIVS_TIME/2, 0);
            glVertex2f(DIVS_TIME/2, 0);
            glVertex2f(0, -DIVS_VOLTAGE/2);
            glVertex2f(0, DIVS_VOLTAGE/2);
            for(GLfloat i=0; i<=DIVS_TIME/2; i+=0.5)
            {
                glVertex2f(i, -0.1);
                glVertex2f(i, 0.1);
                glVertex2f(-i, -0.1);
                glVertex2f(-i, 0.1);
            }
            for(GLfloat i=0; i<=DIVS_VOLTAGE/2; i+=0.5)
            {
                glVertex2f(-0.1, i);
                glVertex2f(0.1, i);
                glVertex2f(-0.1, -i);
                glVertex2f(0.1, -i);
            }
            glEnd();
            break;
    }
    glEndList();

    return list;
}

/*!
    \fn GLBox::setTimeDiv(double div)
 */
void GLBox::setTimeDiv(double div)
{
    timeDiv = div;
    updateGL();
}

/*!
    \fn GLBox::setTimeShift(double timeShift)
 */
void GLBox::setTimeShift(double shift)
{
    timeShift = shift;
    updateGL();
}
