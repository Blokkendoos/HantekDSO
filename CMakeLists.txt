cmake_minimum_required( VERSION 2.6 )

project( HantekDSO )

set( HANTEKDSO_BUILD_DIR "${PROJECT_SOURCE_DIR}/build/src" )
set( HANTEKDSO_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src" )
include_directories( ${HANTEKDSO_BUILD_DIR} ${HANTEKDSO_SOURCE_DIR} )

find_package( PkgConfig REQUIRED )

# GLib2
#pkg_check_modules( GLIB REQUIRED glib-2.0 gobject-2.0 gio-2.0)
pkg_check_modules( GLIB REQUIRED glib-2.0 )
include_directories( ${GLIB_INCLUDE_DIRS} )
link_directories( ${GLIB_LIBRARY_DIRS} )
#add_definitions( ${GLIB_CFLAGS_OTHER} )

# OpenGL
find_package( OpenGL REQUIRED )
find_package( GLUT REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

# USB library
find_path( LIBUSB_INCLUDE_DIR
  NAMES libusb.h
  PATH_SUFFIXES "include" "libusb" "libusb-1.0" )
find_library( LIBUSB_LIBRARY
  NAMES usb
  PATH_SUFFIXES "lib" "lib32" "lib64" )
include_directories( ${LIBUSB_INCLUDE_DIR} )

# KDE4
find_package( KDE4 REQUIRED )
include_directories( ${KDE4_INCLUDES})

# Qt4
set( CMAKE_AUTOMOC ON )
find_package( Qt4 REQUIRED QtCore QtGui QtOpenGL QtXml QtTest QtWebKit Qt3Support )
include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )
include_directories( ${QT_INCLUDE_DIR} )

add_subdirectory(src)

#for debugging
message( STATUS "===" )
message( STATUS "PROJECT_NAME: " ${PROJECT_NAME} )
message( STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR} )
message( STATUS "LIBUSB_INCLUDE_DIR: " ${LIBUSB_INCLUDE_DIR} )
message( STATUS "LIBUSB_LIBRARY: " ${LIBUSB_LIBRARY} )
message( STATUS "QT_LIBRARIES: " ${QT_LIBRARIES} )
message( STATUS "GLIB_INCLUDE_DIRS: " ${GLIB_INCLUDE_DIRS} )
message( STATUS "GLIB_LIBRARIES: " ${GLIB_LIBRARIES} )
message( STATUS "===" )

# source: https://wiki.qt.io/Using_CMake_build_system
# generate proper GUI program on specified platform
if(WIN32) # Check if we are on Windows
	if(MSVC) # Check if we are using the Visual Studio compiler
		set_target_properties(${PROJECT_NAME} PROPERTIES
			WIN32_EXECUTABLE YES
			LINK_FLAGS "/ENTRY:mainCRTStartup"
		)
	elseif(CMAKE_COMPILER_IS_GNUCXX)
			# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
	else()
		message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
	endif(MSVC)
elseif(APPLE)
	set_target_properties(${PROJECT_NAME} PROPERTIES
			MACOSX_BUNDLE YES
	)
elseif(UNIX)
	# Nothing special required
else()
	message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)
