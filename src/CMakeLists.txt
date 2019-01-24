include_directories( ${hantekdso_include_DIR} )

set( SOURCES
	cursor.cpp
	fht.cpp
	glbox.cpp
	hantekdso.cpp
	hantekdsoathread.cpp
	hantekdsoio.cpp
	hantekdsowidget.cpp
	hantekdsowidgetbase.cpp
	main.cpp
	sansfont.cpp
	timecursor.cpp
	voltagecursor.cpp
)

set( MOC_HEADERS
	cursor.h
	fht.h
	glbox.h
	hantekdso.h
	hantekdsoathread.h
	hantekdsoio.h
	hantekdsowidget.h
	hantekdsowidgetbase.h
	sansfont.h
	timecursor.h
	voltagecursor.h
)

set( UIS
 hantekdsowidgetbase.ui
)

set( RESOURCES
 hantekdsoui.rc
)

# using Qt meta-system (precompiler)
QT4_ADD_RESOURCES( RES_SOURCES ${RESOURCES} )
#QT4_WRAP_UI( UI_HEADERS ${UIS} )
QT4_WRAP_CPP( MOC_SRCS ${MOC_HEADERS} )

add_executable( HantekDSO ${SOURCES} )

# debug
#message( STATUS "GLIB INCLUDE DIRS " ${GLIB_INCLUDE_DIRS} )
#message( STATUS "GLIB LIBRARIES " ${GLIB_LIBRARIES} )

# build it (link libraries)
target_link_libraries( HantekDSO ${QT_LIBRARIES} )
target_link_libraries( HantekDSO ${KDE4_KDEUI_LIBS} )
target_link_libraries( HantekDSO ${LIBUSB_LIBRARY} )
target_link_libraries( HantekDSO INTERFACE ${GLIB_LIBRARIES} )
target_link_libraries( HantekDSO ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

target_include_directories( HantekDSO PRIVATE ${GLIB_INCLUDE_DIRS} )

