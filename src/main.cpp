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


#include "hantekdso.h"
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>
#include <klocalizedstring.h>

KLocalizedString description = ki18n("A KDE KPart Application");
KLocalizedString copyright = ki18n("(C) 2008-2009 Oleg Khudyakov");

static const char version[] = "0.1";

//static KCmdLineOptions *options = new KCmdLineOptions();
static KCmdLineOptions options;

int main(int argc, char **argv)
{
    KAboutData *about = new KAboutData( "hantekdso"
                                      , NULL
                                      , ki18n("HantekDSO")
                                      , version
                                      , description
                                      , KAboutData::License_GPL
                                      , copyright
                                      , ki18n(""), 0, "prcoder@gmail.com" );
    about->addAuthor( ki18n("Oleg Khudyakov"), ki18n(""), "prcoder@gmail.com" );
    KCmdLineArgs::init(argc, argv, about);
    KCmdLineArgs::addCmdLineOptions( options );
    KApplication app;
    HantekDSO *mainWin = 0;

    if (app.isSessionRestored())
    {
        RESTORE(HantekDSO);
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

        /// @todo do something with the command line args here

        mainWin = new HantekDSO();
        app.setMainWidget( mainWin );
        mainWin->show();

        args->clear();
    }

    // mainWin has WDestructiveClose flag by default, so it will delete itself.
    return app.exec();
}

