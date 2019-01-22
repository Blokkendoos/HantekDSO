/*
    Copyright (c) 2010, Thomas Gerner
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY <copyright holder> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "timecursor.h"
#include "glbox.h"

TimeCursor::TimeCursor(QWidget* parent, const char* name): Cursor(parent, name),
    timeDiv(0.0), timeShift(0.0), timeBase(0.0)
{
}

TimeCursor::~TimeCursor()
{
}

bool TimeCursor::isSelected(QMouseEvent* e, int width, int height)
{
    int pos = (getPosition() / (DIVS_TIME/2 + GLBox::getBorder()) + 1.0) * width / 2;
    if (abs(pos - e->x()) < 5)
	return true;
    return false;
}

void TimeCursor::setPosition(QMouseEvent* e, int width, int height)
{
	Cursor::setPosition((GLfloat)((DIVS_TIME/2 + GLBox::getBorder()) * ((double)e->x() * 2.0 / (double)width - 1.0)));
}

GLfloat TimeCursor::getLower()
{
    return -DIVS_TIME/2;
}

GLfloat TimeCursor::getUpper()
{
    return DIVS_TIME/2;
}

void TimeCursor::paintCursor(SansFont &font)
{
    if (!isChecked())
	return;
    
    GLfloat cp = getPosition();
    glPushMatrix();
    glLineWidth(1);
    glColor4f(0.8, 0.8, 0.8, 1.0);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(cp, -DIVS_VOLTAGE/2);
    glVertex2f(cp, DIVS_VOLTAGE/2);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
    
    glPushMatrix();
    glColor4f(0.8, 0.8, 0.8, 1.0);
    double timePos = (cp + DIVS_TIME/2) / timeDiv + (DIVS_TIME - DIVS_TIME / timeDiv) * timeShift - DIVS_TIME/2;
    timePos *= timeBase;
    int precision;
    if (timeDiv < 10)
	precision = 2;
    else if (timeDiv < 100)
	precision = 3;
    else
	precision = 4;
    QString str;
    if (timeBase < 1e-3)
	str = QString::number(timePos * 1e6, 'f', precision).append(QChar(0xB5)).append("s");
    else if (timeBase < 1)
	str = QString::number(timePos * 1e3, 'f', precision).append("ms");
    else
	str = QString::number(timePos, 'f', precision).append("s");
    double strWidth = 0.17 * str.length();
    if (cp < DIVS_TIME/2 - strWidth)
	glTranslatef(cp, -DIVS_VOLTAGE/2, 0.0);
    else
	glTranslatef(cp - strWidth, -DIVS_VOLTAGE/2, 0.0);
    font.glString(str, 0.3);
    glPopMatrix();
}

void TimeCursor::setTimebase(GLfloat base)
{
    timeBase = base;
}

void TimeCursor::setTimeDiv(GLfloat div)
{
    timeDiv = div;
}

void TimeCursor::setTimeShift(GLfloat shift)
{
    timeShift = shift;
}

