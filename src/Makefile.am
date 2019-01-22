# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = fht.h glbox.h hantekdso.h hantekdsoathread.h hantekdsoio.h \
	sansfont.h cursor.h timecursor.h voltagecursor.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(EXTRACTRC) `find . -name \*.ui -o -name \*.rc` > rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/hantekdso.pot

KDE_ICON = AUTO

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = hantekdso

# the application source, library search path, and link libraries
hantekdso_SOURCES = fht.cpp glbox.cpp hantekdso.cpp hantekdsoathread.cpp \
	hantekdsoio.cpp hantekdsowidget.cpp hantekdsowidgetbase.ui main.cpp sansfont.cpp \
	cursor.cpp timecursor.cpp voltagecursor.cpp
hantekdso_LDFLAGS = -avoid-version $(KDE_RPATH) $(all_libraries)
hantekdso_LDADD = $(LIB_KDEUI) -lGL -lusb -lm

# this is where the desktop file will go 
shelldesktopdir   = $(kde_appsdir)/Utilities
shelldesktop_DATA = hantekdso.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/hantekdso
shellrc_DATA = hantekdsoui.rc

