/***************************************************************************
 *   Copyright (C) 2008 by Oleg Khudyakov   *
 *   prcoder@potrebitel.ru   *
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


#ifndef _HANTEKDSO_H_
#define _HANTEKDSO_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kmainwindow.h>

#include "hantekdsowidget.h"

/**
 * @short Application Main Window
 * @author Oleg Khudyakov <prcoder@potrebitel.ru>
 * @version 0.1
 */
class HantekDSO : public KMainWindow
{
    Q_OBJECT
    public:
        /**
         * Default Constructor
         */
        HantekDSO();

        /**
         * Default Destructor
         */
        virtual ~HantekDSO();

    protected:
        virtual bool queryClose();
        
    private:
        HantekDSOWidget *widget;
};

#endif // _HANTEKDSO_H_
