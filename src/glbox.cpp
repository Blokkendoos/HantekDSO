/****************************************************************************
** $Id: qt/glbox.cpp   3.3.8   edited Jan 11 14:37 $
**
** Copyright (C) 1992-2007 Trolltech ASA.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/
#include "glbox.h"
#include "hantekdsoathread.h"
#include "fht.h"
#include <math.h>

const GLfloat GLBox::chColor[MAX_CHANNELS+1][4] = {
    {0.0, 1.0, 1.0, 1.0}, // CH2 Color
    {1.0, 0.0, 0.0, 1.0}, // CH1 Color
    {0.0, 1.0, 0.0, 1.0}  // MATH Color
};

GLBox::GLBox(QWidget* parent, const char* name) : QGLWidget(parent, name),
    aThread(0), gl_grid(0), calData(0), digitalPhosphor(0), dpIndex(0), viewMode(VIEWMODE_XT),
    mathType(MATHTYPE_OFF), interpolationMode(INTERPOLATION_LINEAR), timeDiv(1), timeShift(0)
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

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_POINT_SMOOTH);
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
                                glVertex2f(i, ch1Val + ch2Val + VOLTAGE_SCALE/2);
                                break;
                            case MATHTYPE_1SUB2:
                                glVertex2f(i, ch1Val - ch2Val + VOLTAGE_SCALE/2);
                                break;
                            case MATHTYPE_2SUB1:
                                glVertex2f(i, ch2Val - ch1Val + VOLTAGE_SCALE/2);
                                break;
                        }
                    }
                    glEnd();
                    glEndList();
                }
                aThread->bufferMutex.unlock();

                glPushMatrix();
                glCallList(gl_grid);
/*
                glPushMatrix();
                glColor4f(0.0, 1.0, 0.0, 1.0);
                glTranslatef(-DIVS_TIME/2, -DIVS_VOLTAGE/2, 0.0);
                str=QString("%1 ms/div").arg(1);
                font.glString(str, 0.3);
                glPopMatrix();
*/
                glTranslatef(-DIVS_TIME/2, -DIVS_VOLTAGE/2, 0);
                glScalef(DIVS_TIME*timeDiv/samplesInScale, DIVS_VOLTAGE/VOLTAGE_SCALE, 1.0);
                for (int t = 0 ; t < MAX_CHANNELS; t++)
                {
                    for (int i = (digitalPhosphor?DP_DEPTH:0); i >= 0; i--)
                    {
                        glColor4f(chColor[t][0], chColor[t][1], chColor[t][2],
                            chColor[t][3] - 0.7*log(i + 1));
                        int index = (dpIndex + i) % DP_DEPTH;
                        glCallList(gl_channels + index*MAX_CHANNELS + t);
                    }
                }
                if (mathType != MATHTYPE_OFF)
                {
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
                break;

            case VIEWMODE_XY:
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
                glScalef(DIVS_TIME*timeDiv/transformedSamples, DIVS_VOLTAGE/VOLTAGE_SCALE, 1.0);
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
                            glVertex2f(i+1, aThread->fhtBuffer[t][i+transformViewPos+1]);
                            glVertex2f(i+1, 0);
                        }
                    }
                    glEnd();
                }
                glPopMatrix();
                glCallList(gl_grid);
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
    updateGL();
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

void GLBox::setInterpolation(int state)
{
    interpolationMode = state;
    updateGL();
}

void GLBox::setCalData(double data)
{
    calData = data;
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
            glColor4f(0.7, 0.7, 0.7, 0.7);
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
            glColor4f(1.0, 1.0, 1.0, 0.8);
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
