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

#include "voltagecursor.h"
//Added by qt3to4:
#include <QMouseEvent>

VoltageCursor::VoltageCursor(QWidget* parent, const char* name): Cursor(parent, name),
    chOffset(0.0), chDiv(0.0), chActive(false), channel(CHANNEL_CH1)
{
}

VoltageCursor::VoltageCursor(QWidget* parent): Cursor(parent),
    chOffset(0.0), chDiv(0.0), chActive(false), channel(CHANNEL_CH1)
{
}

VoltageCursor::~VoltageCursor()
{
}

bool VoltageCursor::isSelected(QMouseEvent* e, int width, int height)
{
    int pos = (getPosition() / -(DIVS_VOLTAGE/2 + GLBox::getBorder()) + 1.0) * height / 2;
    if (abs(pos - e->y()) < 5)
	return true;
    return false;
}

void VoltageCursor::setPosition(QMouseEvent* e, int width, int height)
{
    Cursor::setPosition((GLfloat)(-(DIVS_VOLTAGE/2 + GLBox::getBorder()) * ((double)e->y() * 2.0 / (double)height - 1.0)));
}

GLfloat VoltageCursor::getLower()
{
    return -DIVS_VOLTAGE/2;
}

GLfloat VoltageCursor::getUpper()
{
    return DIVS_VOLTAGE/2;
}

void VoltageCursor::paintCursor(SansFont& font)
{
    if (!chActive || !isChecked())
	return;
    
    glPushMatrix();
    glLineWidth(1);
    glColor4f(GLBox::getRed(channel), GLBox::getGreen(channel), GLBox::getBlue(channel), GLBox::getAlpha(channel));
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(-DIVS_TIME/2, getPosition());
    glVertex2f(DIVS_TIME/2, getPosition());
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
    
    glPushMatrix();
    glColor4f(GLBox::getRed(channel), GLBox::getGreen(channel), GLBox::getBlue(channel), GLBox::getAlpha(channel));
    double chVoltage = chOffset + getPosition() * chDiv;
    QString str;
    if (chVoltage > - 1.0 && chVoltage < 1.0)
	str = QString::number(chVoltage * 1000, 'f', 0).append("mV");
    else
	str = QString::number(chVoltage, 'f', 2).append("V");
    
    if (getPosition() < DIVS_VOLTAGE/2 - 0.3)
	glTranslatef(-DIVS_TIME/2, getPosition(), 0.0);
    else
	glTranslatef(-DIVS_TIME/2, getPosition() - 0.3, 0.0);
    
    font.glString(str, 0.3);
    glPopMatrix();
}

void VoltageCursor::setChActive(bool active)
{
    chActive = active;
}

void VoltageCursor::setChannel(channels ch)
{
    channel = ch;
}

void VoltageCursor::setChannelVoltage(double offset, double div)
{
    chOffset = offset;
    chDiv = div;
}

