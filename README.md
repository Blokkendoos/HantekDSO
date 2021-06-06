# HantekDSO

This project is a fork from SourceForge [HantekDSO-0.5.4](https://sourceforge.net/projects/hantekdso)

## Description
HantekDSO is a USB-oscilloscope software for
Hantek, Novatek, Voltcraft, Darkwire, Protek, Acetech, etc
DSO2090, 2150, 2250, 5200A, etc. oscilloscopes.

It is based on libusb and QT/OpenGL libraries. Project includes a firmware
extraction utility and udev rules file for loading firmware under Linux/Unix.

## Dependencies
* libusb (library to enable user space application programs to communicate with USB devices)
* Qt4 (cross-platform application and UI framework)
* mesa-libGL (open-source implementation of the OpenGL specification)
To successfully build a project you need to have all development packages installed
(libusb-devel, qt-devel (version 4.X), mesa-libGL-devel)

### Firmware extraction utility dependencies
* libbfd (mechanism for the portable manipulation of object files in a variety of formats)
* libiberty (collection of subroutines used by various GNU programs)

Both libraries (libbfd and libiberty) are included in the binutils-devel package

Also you need to have fxload utility installed in order to be able to upload firmware
in to the oscilloscope.

![Screenshot](Schermafbeelding%202021-06-05%20om%2023.43.31.png?raw=true "Screenshot")

## How to BUILD
```
mkdir build
cd build
cmake ..
make
make install
```

## How to install Firmware
You need to find the firmware for the oscilloscope (usually in the folder
`/Driver` on CD), convert it to .hex files, and make sure they get loaded
into the oscilloscope when it is connected.
Locate one of the following files, depending on the model of 
your scope: DSO20901.SYS, DSO21001.SYS, DSO21501.SYS, DSO22501.SYS, 
DSO520A1.SYS and put it in the folder with dsoextractfw utility.
All characters in the file name **must** be uppercase. Please, rename the file
to uppercase letters if need.

Run the program dsoextractfw. It searches
for the files listed above in the current directory. If it finds any of
them, it creates two files named `DSOxxxx_firmware.hex` and `DSOxxxx_loader.hex`. Move these files to `/usr/share/HantekDSO/`.
Copy the file HantekDSO.rules to `/etc/udev/rules.d/`, and add your user to the plugdev group.

Now, the firmware should be loaded automatically when the DSO is connected 
to an USB port. Once the firmware is loaded, the LED on the DSO starts to 
flash red. You can now run the program hantekdso. The LED will blink green.
Make sure you have sufficient privilegies on the USB device or run as root
(probably not recommended in the long run).

Thanks to:
- Fredrik Jansson
