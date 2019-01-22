/***************************************************************************
 *   Copyright (C) 2008 by Oleg Khudyakov   *
 *   prcoder@gmail.com   *
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
#ifndef FHT_H
#define FHT_H

/**
	@author Oleg Khudyakov <prcoder@potrebitel.ru>
*/
class FHT
{
public:
    FHT();
    ~FHT();

    void transform(double *buf, int n, int skip);
    void reverse(double *buf, int n, int skip);

private:
    void scale(double *buf, int n, int skip);
    static const double sintab[22];
};

#endif
