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
#ifndef HANTEKDSOIO_H
#define HANTEKDSOIO_H

#include <usb.h>
#include <qmutex.h>

#define EP_BULK_OUT 2   // Endpoint for sending commands to DSO
#define EP_BULK_IN  6   // Endpoint for reading data from DSO

enum dso_models
{
    DSO_2090 = 0x2090,
    DSO_2100 = 0x2100,
    DSO_2150 = 0x2150,
    DSO_2250 = 0x2250,
    DSO_5200 = 0x5200,
    DSO_LAST = 0
};

enum dso_commands
{
    cmdSetFilter = 0,
    cmdSetTriggerAndSampleRate,
    cmdForceTrigger,
    cmdCaptureStart,
    cmdTriggerEnabled,
    cmdGetChannelData,
    cmdGetCaptureState,
    cmdSetVoltageAndCoupling,
    cmdSetLogicalData,
    cmdGetLogicalData,
    cmdLast
};

enum control_requests
{
    CONTROL_COMMAND = 0xA2,
    CONTROL_GETSPEED = 0xB2,
    CONTROL_BEGINCOMMAND = 0xB3,
    CONTROL_SETOFFSET = 0xB4,
    CONTROL_SETRELAYS = 0xB5
};

enum control_values
{
    VALUE_CHANNELLEVEL = 0x08,
    VALUE_DEVICEADDRESS = 0x0A,
    VALUE_CALDATA = 0x60
};

enum time_bases
{
    TIME_10mks,
    TIME_20mks,
    TIME_40mks,
    TIME_100mks,
    TIME_200mks,
    TIME_400mks,
    TIME_1ms,
    TIME_2ms,
    TIME_4ms,
    TIME_10ms,
    TIME_20ms,
    TIME_40ms,
    TIME_100ms,
    TIME_200ms,
    TIME_400ms,
    TIME_LAST
};

enum voltages
{
    VOLTAGE_5V = 0,
    VOLTAGE_2V,
    VOLTAGE_1V,
    VOLTAGE_500mV,
    VOLTAGE_200mV,
    VOLTAGE_100mV,
    VOLTAGE_50mV,
    VOLTAGE_20mV,
    VOLTAGE_10mV
};

enum couplings
{
    COUPLING_AC = 0,
    COUPLING_DC,
    COUPLING_OFF
};

enum selected_channels
{
    SELECT_CH1 = 0,
    SELECT_CH2,
    SELECT_CH1CH2
};

enum trigger_sources
{
    TRIGGER_CH2 = 0,
    TRIGGER_CH1,
    TRIGGER_ALT,
    TRIGGER_EXT,
    TRIGGER_EXT10
};

enum trigger_slopes
{
    SLOPE_POSITIVE = 0,
    SLOPE_NEGATIVE
};

enum buffer_sizes
{
    BUFFER_SMALL = 10240,
    BUFFER_LARGE = 32768
};

enum getcapturestate_return_values
{
    CAPTURE_VALUE0 = 0,
    CAPTURE_VALUE1,
    CAPTURE_SUCCESS
};

enum level_offsets
{
    OFFSET_START = 0,
    OFFSET_END
};

struct filter_bits
{
    unsigned char channel1:1;
    unsigned char channel2:1;
    unsigned char trigger:1;
    unsigned char reserved:5;
};

union filter_byte
{
    filter_bits bits;
    unsigned char byte;
};

struct voltage_bits
{
    unsigned char channel1:2;
    unsigned char channel2:2;
    unsigned char constant:4;
};

union voltage_byte
{
    voltage_bits bits;
    unsigned char byte;
};

struct tsr_bits1
{
    unsigned char triggerSource:2;
    unsigned char sampleSize:3;
    unsigned char timeBaseFast:3;
};

union tsr_byte1
{
    tsr_bits1 bits;
    unsigned char byte;
};

struct tsr_bits2
{
    unsigned char selectedChannel:2;
    unsigned char fastRatesChannel:1;
    unsigned char triggerSlope:1;
    unsigned char reserved:4;
};

union tsr_byte2
{
    tsr_bits2 bits;
    unsigned char byte;
};

typedef unsigned short channel_levels[2][9][2];

/**
Hantek DSO input/output implementation through libusb
	@author Oleg Khudyakov <prcoder@potrebitel.ru>
*/
class HantekDSOIO{
public:
    HantekDSOIO();
    ~HantekDSOIO();

    int dsoInit();
    unsigned short dsoGetModel();
    int dsoSetFilter(int channel1, int channel2, int trigger);
    int dsoSetTriggerAndSampleRate(int timeBase, int selectedChannel, int triggerSource, int triggerSlope, int triggerPosition, int bufferSize);
    int dsoForceTrigger();
    int dsoCaptureStart();
    int dsoTriggerEnabled();
    int dsoGetChannelData(void *buffer, int bufferSize);
    int dsoGetCaptureState(unsigned *triggerPoint);
    int dsoSetVoltageAndCoupling(int ch1Voltage, int ch2Voltage, int ch1Coupling, int ch2Coupling, int triggerSource);
    int dsoSetLogicalData(int data);
    int dsoGetLogicalData(void *buffer);
    int dsoGetDeviceAddress(int *deviceAddress);
    int dsoSetDeviceAddress(int *deviceAddress);
    int dsoGetCalData(int *calData);
    int dsoSetCalData(int *calData);
    int dsoGetChannelLevel(channel_levels *channelLevels);
    int dsoSetChannelLevel(channel_levels *channelLevels);
    int dsoSetOffset(int ch1Offset, int ch2Offset, int extOffset);

protected:
    int writeBulk(void* buffer, int len);
    int readBulk(void* buffer, int len);
    int writeControl(unsigned char request, void* buffer, int len, int value = 0, int index = 0);
    int readControl(unsigned char request, void* buffer, int len, int value = 0, int index = 0);

    int dsoGetConnectionSpeed();
    int dsoBeginCommand(int index = 0);
    int tpTransform(unsigned *triggerPoint);

private:
    static const unsigned short deviceVendor = 0x04b5; // Hantek DSO after renumeration
    static const unsigned short deviceModelsList[];
    unsigned short deviceModel;
    struct usb_dev_handle *usbDSOHandle;
    int interfaceNumber;
    bool interfaceIsClaimed;
    QMutex dsoIOMutex;
    int timeout;
};

#endif
