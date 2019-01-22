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
#ifndef SANSFONT_H
#define SANSFONT_H
#include <qgl.h>
#include <qstring.h>

#define CHARNUMBER 175
#define TEXTUREW 256
#define TEXTUREH 256
#define POINTSIZE 4 // RGBA
#define FONTSCALE 30

/**
	@author Oleg Khudyakov <prcoder@potrebitel.ru>
*/
struct font_info
{
    char chr;
    unsigned char x, y;
    unsigned char w, h;
    unsigned char xofs, yofs;
    unsigned char xadv;
};

/**
	@author Oleg Khudyakov <prcoder@potrebitel.ru>
*/
class SansFont
{
public:
    SansFont();
    ~SansFont();

    void init();
    int glChar(QChar chr, float scale);
    int glString(QString str, float scale);

private:
    int findChar(QChar chr);

private:
    GLuint sansTexture;
    static const font_info sansFont[];
    static const GLbyte sansTextureBytes[];
};

#endif
