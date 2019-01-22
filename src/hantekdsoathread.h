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
#ifndef HANTEKDSOATHREAD_H
#define HANTEKDSOATHREAD_H

#include <qthread.h>
#include <qmutex.h>
#include "hantekdsoio.h"
#include "fht.h"

#define MAX_CHANNELS 2
#define VOLTAGE_SCALE 256

/**
Hantek DSO acquisition thread

	@author Oleg Khudyakov <prcoder@potrebitel.ru>
*/
class HantekDSOAThread : public QThread
{
public:
    HantekDSOAThread();
    ~HantekDSOAThread();

    virtual void run();
    virtual void setBufferSize(unsigned bufferSize);
    virtual void getCalData();
    virtual void calibrateBuffer();
    virtual void transform();

public:
    HantekDSOIO dsoIO;
    QMutex bufferMutex;
    FHT fht;
    unsigned bufferSize, transformSize;
    unsigned char buffer[BUFFER_LARGE][MAX_CHANNELS];
    int calData;
    unsigned triggerPoint;
    double fhtBuffer[MAX_CHANNELS][BUFFER_LARGE];
    double windowCoeff[BUFFER_LARGE];
};

#endif
