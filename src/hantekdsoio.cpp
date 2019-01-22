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
#include "hantekdsoio.h"
#include <qapplication.h>
#include <errno.h>
#include <string.h>

HantekDSOIO::HantekDSOIO() : deviceModel(0), usbDSOHandle(0), interfaceNumber(0),
    interfaceIsClaimed(false), epOutMaxPacketLen(0), epInMaxPacketLen(0), timeout(500), attempts(5)
{
}

HantekDSOIO::~HantekDSOIO()
{
    if (interfaceIsClaimed)
    {
        if (::usb_release_interface(usbDSOHandle, interfaceNumber))
        {
            qDebug("Not able to release USB interface");
        }
    }

    if (usbDSOHandle)
    {
        if (::usb_close(usbDSOHandle))
        {
            qDebug("Can't close USB handle");
        }
    }
}

const unsigned short HantekDSOIO::deviceModelsList[] =
    { DSO_2090, DSO_2100, DSO_2150, DSO_2250, DSO_5200, DSO_5200A, DSO_LAST };

/*!
    \fn HantekDSOIO::dsoInit()
 */
int HantekDSOIO::dsoInit()
{
    dsoIOMutex.lock();

    ::usb_init();
    ::usb_find_busses();
    ::usb_find_devices();

    struct usb_device *usbDSO = NULL;
    for (struct usb_bus *usb_bus = usb_busses; usb_bus; usb_bus = usb_bus->next)
    {
        for (struct usb_device *dev = usb_bus->devices; dev; dev = dev->next)
        {
            if (dev->descriptor.idVendor == deviceVendor)
            {
                for (int i = 0; deviceModelsList[i] != DSO_LAST; i++)
                {
                    if (dev->descriptor.idProduct == deviceModelsList[i])
                    {
                        usbDSO = dev;
                        deviceModel = dev->descriptor.idProduct;
                        qDebug("Hantek DSO model %4X found", deviceModel);
                        break;
                    }
                }
            }
        }
    }

    if (usbDSO == NULL)
    {
        dsoIOMutex.unlock();
        qDebug("Hantek DSO not found");
        return -1;
    }

    usbDSOHandle = ::usb_open(usbDSO);
    if (usbDSOHandle == NULL)
    {
        dsoIOMutex.unlock();
        qDebug("Can't open USB device");
        return -2;
    }

    struct usb_config_descriptor *usbConfig = usbDSO->config;
    for (int i = 0; i < usbConfig->bNumInterfaces; i++)
    {
        struct usb_interface *usbInterface = &usbConfig->interface[i];
        if (usbInterface->num_altsetting < 1)
            continue;

        struct usb_interface_descriptor *usbInterfaceDescr = &usbInterface->altsetting[0];
        if (usbInterfaceDescr->bInterfaceClass == USB_CLASS_VENDOR_SPEC
            && usbInterfaceDescr->bInterfaceSubClass == 0
            && usbInterfaceDescr->bInterfaceProtocol == 0
            && usbInterfaceDescr->bNumEndpoints == 2)
        {
            if (::usb_claim_interface(usbDSOHandle, usbInterfaceDescr->bInterfaceNumber))
            {
                if (::usb_close(usbDSOHandle))
                {
                    qDebug("Can't close USB handle");
                }

                dsoIOMutex.unlock();
                qDebug("Not able to claim USB interface");
                return -3;
            }

            interfaceNumber = usbInterfaceDescr->bInterfaceNumber;
            interfaceIsClaimed = true;

            for (int i = 0; i < usbInterfaceDescr->bNumEndpoints; i++)
            {
                usb_endpoint_descriptor *usbEndpointDescr = &usbInterfaceDescr->endpoint[i];
                switch (usbEndpointDescr->bEndpointAddress)
                {
                    case 0x02:  // EP OUT
                        epOutMaxPacketLen = usbEndpointDescr->wMaxPacketSize;
                        qDebug("EP OUT MaxPacketLen = %i", epOutMaxPacketLen);
                        break;
                    case 0x86:  // EP IN
                        epInMaxPacketLen = usbEndpointDescr->wMaxPacketSize;
                        qDebug("EP IN MaxPacketLen = %i", epInMaxPacketLen);
                        break;
                    default:
                        qDebug("Unknown endpoint #%02X", usbEndpointDescr->bEndpointAddress);
                }
            }

            break;
        }
    }

    if (!interfaceIsClaimed)
    {
        qDebug("Can't find USB interface (Class:0xFF, SubClass:0, Protocol:0) with two endpoints");
        return -4;
    }

    dsoIOMutex.unlock();

    return 0;
}

/*!
    \fn HantekDSOIO::getDSOModel()
 */
bool HantekDSOIO::dsoIsFound()
{
    return interfaceIsClaimed;
}


/*!
    \fn HantekDSOIO::getDSOModel()
 */
unsigned short HantekDSOIO::dsoGetModel()
{
    return deviceModel;
}

/*!
    \fn HantekDSOIO::writeBulk(void *buffer, int len)
 */
int HantekDSOIO::writeBulk(void *buffer, int len)
{
    int i, rv = -ETIMEDOUT;
    for(i = 0; (rv == -ETIMEDOUT) && (i < attempts); i++)
    {
        rv = ::usb_bulk_write(usbDSOHandle, EP_BULK_OUT | USB_ENDPOINT_OUT, (char*)buffer, len, timeout);
    }

    if (rv < 0)
    {
        qDebug("Usb write bulk returns error %i", rv);
        qDebug("Error: %s", ::usb_strerror());
        return rv;
    }

    return 0;
}

/*!
    \fn HantekDSOIO::readBulk(void *buffer, int len)
 */
int HantekDSOIO::readBulk(void *buffer, int len)
{
    int i, rv = -ETIMEDOUT;
    for(i = 0; (rv == -ETIMEDOUT) && (i < attempts); i++)
    {
        rv = ::usb_bulk_read(usbDSOHandle, EP_BULK_IN | USB_ENDPOINT_IN, (char*)buffer, len, timeout);
    }

    if (rv < 0)
    {
        qDebug("Usb read bulk returns error %i", rv);
        qDebug("Error: %s", ::usb_strerror());
        return rv;
    }

    return 0;
}

/*!
    \fn HantekDSOIO::writeControl(unsigned char request, void *buffer, int len)
 */
int HantekDSOIO::writeControl(unsigned char request, void *buffer, int len, int value, int index)
{
    int i, rv = -ETIMEDOUT;
    for(i = 0; (rv == -ETIMEDOUT) && (i < attempts); i++)
    {
        rv = ::usb_control_msg(usbDSOHandle, USB_ENDPOINT_OUT | USB_TYPE_VENDOR,
                    request, value, index, (char*)buffer, len, timeout);
    }

    if (rv < 0)
    {
        qDebug("Usb write control message %02X returns error %i", request, rv);
        qDebug("Error: %s", ::usb_strerror());
        return rv;
    }

    return 0;
}

/*!
    \fn HantekDSOIO::readControl(unsigned char request, void *buffer, int len)
 */
int HantekDSOIO::readControl(unsigned char request, void *buffer, int len, int value, int index)
{
    int i, rv = -ETIMEDOUT;
    for(i = 0; (rv == -ETIMEDOUT) && (i < attempts); i++)
    {
        rv = ::usb_control_msg(usbDSOHandle, USB_ENDPOINT_IN | USB_TYPE_VENDOR,
                    request, value, index, (char*)buffer, len, timeout);
    }

    if (rv < 0)
    {
        qDebug("Usb read control message %02X returns error %i", request, rv);
        qDebug("Error: %s", ::usb_strerror());
        return rv;
    }

    return 0;
}

/*!
    \fn HantekDSOIO::getConnectionSpeed()
 */
/**
 * 
 * @return 0 - FullSpeed, 1 - HighSpeed
 */
int HantekDSOIO::dsoGetConnectionSpeed()
{
    unsigned char buffer[10];
    int rv = readControl(CONTROL_GETSPEED, buffer, sizeof(buffer));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        return rv;
    }

    return (int)buffer[0];
}


/*!
    \fn HantekDSOIO::dsoBeginCommand(int index=0)
 */
int HantekDSOIO::dsoBeginCommand(int index)
{
    unsigned char buffer[10] = { 0x0F, 0x03, 0x03, 0x03, 0, 0, 0, 0, 0, 0};
    switch (index)
    {
        case 5:
            memset(&buffer[1], 0x08, 3);
            break;
        case 4:
            memset(&buffer[1], 0x02, 3);
            break;
        case 3:
            memset(&buffer[1], 0x01, 3);
            break;
        case 2:
            memset(&buffer[1], 0x09, 3);
            break;
        case 1:
            memset(&buffer[1], 0x0A, 3);
            break;
        default:
        case 0:
            memset(&buffer[1], 0x3, 3);
            break;
    }

    int rv = writeControl(CONTROL_BEGINCOMMAND, buffer, sizeof(buffer));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        return rv;
    }

    return 0;
}

/*!
    \fn HantekDSOIO::dsoSetFilter(int channel1, int channel2, int trigger)
 */
int HantekDSOIO::dsoSetFilter(int channel1, int channel2, int trigger)
{
    filter_byte filter;
    filter.bits.channel1 = channel1;
    filter.bits.channel2 = channel2;
    filter.bits.trigger = trigger;
    filter.bits.reserved = 0;

    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[8] = {cmdSetFilter, 0x0F, 0, 0, 0, 0, 0, 0};
    command[2] = filter.byte;

    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoSetTriggerAndSampleRate(int timeBase, int selectedChannel, int triggerSource, int triggerSlope, int triggerPosition, int bufferSize)
 */
int HantekDSOIO::dsoSetTriggerAndSampleRate(int timeBase, int selectedChannel, int triggerSource, int triggerSlope, int triggerPosition, int bufferSize)
{
    unsigned char timeBaseTableFastSmall[4] = {1, 2, 3, 4};
    unsigned char timeBaseTableFastLarge[4] = {0, 0, 2, 3};
    unsigned short timeBaseTableSlowSmall[12] = {0xFFFF, 0xFFFC, 0xFFF7, 0xFFE8, 0xFFCE, 0xFF9C, 0xFF07, 0xFE0D, 0xFC19, 0xF63D, 0xEC79, 0xD8F1};
    unsigned short timeBaseTableSlowLarge[12] = {0xFFFF, 0x0000, 0xFFFC, 0xFFF7, 0xFFE8, 0xFFCE, 0xFF9D, 0xFF07, 0xFE0D, 0xFC19, 0xF63D, 0xEC79 };

    tsr_byte1 tsr1;
    tsr1.bits.triggerSource = triggerSource;
    tsr1.bits.sampleSize = (bufferSize==BUFFER_SMALL)?1:2;
    tsr1.bits.timeBaseFast = 0;

    if (timeBase >= TIME_20mks && timeBase <= TIME_200mks)
        tsr1.bits.timeBaseFast = (bufferSize==BUFFER_SMALL)?timeBaseTableFastSmall[timeBase - TIME_20mks]:
        timeBaseTableFastLarge[timeBase - TIME_20mks];
    if (timeBase >= TIME_200mks)
        tsr1.bits.timeBaseFast = 4;

    tsr_byte2 tsr2;
    tsr2.bits.selectedChannel = selectedChannel;
    tsr2.bits.fastRatesChannel = (timeBase < TIME_10mks)?selectedChannel:0;
    tsr2.bits.triggerSlope = triggerSlope;
    tsr2.bits.reserved = 0;

    unsigned short timeBaseValue = 0;
    if (timeBase >= TIME_100mks && timeBase <= TIME_400ms)
        timeBaseValue = (bufferSize==BUFFER_SMALL)?timeBaseTableSlowSmall[timeBase - TIME_100mks]:
        timeBaseTableSlowLarge[timeBase - TIME_100mks];
    if (timeBase > TIME_400ms)
        timeBaseValue = 0xFFED;

    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[12] = {cmdSetTriggerAndSampleRate, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    command[2] = tsr1.byte;
    command[3] = tsr2.byte;
    command[4] = (unsigned char)timeBaseValue;
    command[5] = (unsigned char)(timeBaseValue >> 8);
    command[6] = (unsigned char)triggerPosition;
    command[7] = (unsigned char)(triggerPosition >> 8);
    command[10] = (unsigned char)(triggerPosition >> 16);

    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}


/*!
    \fn HantekDSOIO::dsoForceTrigger()
 */
int HantekDSOIO::dsoForceTrigger()
{
    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[2] = {cmdForceTrigger, 0};
    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoCaptureStart()
 */
int HantekDSOIO::dsoCaptureStart()
{
    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[2] = {cmdCaptureStart, 0};
    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}


/*!
    \fn HantekDSOIO::dsoTriggerEnabled()
 */
int HantekDSOIO::dsoTriggerEnabled()
{
    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[2] = {cmdTriggerEnabled, 0};
    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}


/*!
    \fn HantekDSOIO::dsoGetChannelData(void *buffer)
 */
int HantekDSOIO::dsoGetChannelData(void *buffer, int bufferSize)
{
    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[2] = {cmdGetChannelData, 0};
    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    int packets = bufferSize*sizeof(unsigned short)/epInMaxPacketLen;

    for(int i=0; i<packets; i++)
    {
        rv = readBulk((unsigned char*)buffer + i*epInMaxPacketLen, epInMaxPacketLen);
        if (rv < 0)
        {
        qDebug("In function %s", __FUNCTION__);
            dsoIOMutex.unlock();
            return rv;
        }
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::tpTransform(unsigned triggerPoint)
 */
int HantekDSOIO::tpTransform(unsigned *triggerPoint)
{
    unsigned tp1 = *triggerPoint;
    unsigned tp2 = 1;
    while(tp1 > 0) {
        tp1 >>= 1;
        tp2 <<= 1;
    }

    if(tp2 == 0)
    {
        return -1;
    }

    unsigned var_1 = tp2 - 1;
    unsigned var_2 = 0;

    unsigned var_C = 0;
    unsigned var_10 = 0;

    bool flag = true;
    while (var_1 > var_2)
    {
        var_C = (var_1 - var_2 + 1)/2 + var_10;
        if ((var_C > *triggerPoint) == flag)
        {
            if (!flag)
            {
                var_10 = var_C;
            }
            var_1 = (var_1 + var_2 - 1)/2;
            flag = true;
        }
        else
        {
            if (flag)
            {
                var_10 = var_C;
            }
            var_2 = (var_2 + var_1 + 1)/2;
            flag = false;
        }
    }

    *triggerPoint = var_2;

    return 0;
}

/*!
    \fn HantekDSOIO::dsoGetCaptureState(int *triggerPoint)
 */
/**
 * 
 * @param triggerPoint Address of variable for returning trigger point
 * @return 
 */
int HantekDSOIO::dsoGetCaptureState(unsigned *triggerPoint)
{
    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[2] = {cmdGetCaptureState, 0};
    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char temp[epInMaxPacketLen];

    rv = readBulk(temp, epInMaxPacketLen);
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    rv = temp[0];
    *triggerPoint = (temp[1] << 16) | (temp[3] << 8) | temp[2];
    if (tpTransform(triggerPoint) < 0)
    {
        qDebug("Trigger point transform returns an error");
    }

    dsoIOMutex.unlock();
    return rv;
}

/*!
    \fn HantekDSOIO::dsoSetVoltageAndCoupling(int ch1Voltage, int ch2Voltage, int ch1Coupling, int ch2Coupling, int triggerSource)
 */
int HantekDSOIO::dsoSetVoltageAndCoupling(int ch1Voltage, int ch2Voltage, int ch1Coupling, int ch2Coupling, int triggerSource)
{
    voltage_byte voltage;
    voltage.bits.channel1 = 2 - ch1Voltage % 3;
    voltage.bits.channel2 = 2 - ch2Voltage % 3;
    voltage.bits.constant = 3;

    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[8] = {cmdSetVoltageAndCoupling, 0x0F, 0, 0, 0, 0, 0, 0};
    command[2] = voltage.byte;

    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char relays[17] = { 0x00, 0x04, 0x08, 0x02, 0x20, 0x40, 0x10, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    ch1Voltage /= 3;
    ch2Voltage /= 3;

    if (ch1Voltage > 0)
        relays[1] = ~relays[1];

    if (ch1Voltage > 1)
        relays[2] = ~relays[2];

    if (ch1Coupling)
        relays[3] = ~relays[3];

    if (ch2Voltage > 0)
        relays[4] = ~relays[4];

    if (ch2Voltage > 1)
        relays[5] = ~relays[5];

    if (ch2Coupling)
        relays[6] = ~relays[6];

    if (triggerSource == TRIGGER_EXT || triggerSource == TRIGGER_EXT10)
        relays[7] = ~relays[7];

    rv = writeControl(CONTROL_SETRELAYS, relays, sizeof(relays));
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoSetLogicalData(int data)
 */
int HantekDSOIO::dsoSetLogicalData(int data)
{
    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[8] = {cmdSetLogicalData, 0x0F, 0, 0, 0, 0, 0, 0};
    command[2] = (unsigned char)data;

    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoGetLogicalData(void *buffer)
 */
int HantekDSOIO::dsoGetLogicalData(void *buffer)
{
    dsoIOMutex.lock();

    int rv = dsoBeginCommand();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    unsigned char command[2] = {cmdGetLogicalData, 0};
    rv = writeBulk(command, sizeof(command));
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();
        return rv;
    }

    rv = dsoGetConnectionSpeed();
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        return rv;
    }

    rv = readBulk(buffer, epInMaxPacketLen);
    if (rv < 0)
    {
        qDebug("In function %s", __FUNCTION__);
        dsoIOMutex.unlock();

        return rv;
    }

    dsoIOMutex.unlock();
    return epInMaxPacketLen;
}

/*!
    \fn HantekDSOIO::dsoGetDeviceAddress(int& deviceAddress)
 */
int HantekDSOIO::dsoGetDeviceAddress(int *deviceAddress)
{
    dsoIOMutex.lock();

    *deviceAddress=0;
    int rv = readControl(CONTROL_COMMAND, (char*)deviceAddress, sizeof(char), VALUE_DEVICEADDRESS);
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);
        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoSetDeviceAddress(int& deviceAddress)
 */
int HantekDSOIO::dsoSetDeviceAddress(int *deviceAddress)
{
    dsoIOMutex.lock();

    int rv = writeControl(CONTROL_COMMAND, (char*)deviceAddress, sizeof(char), VALUE_DEVICEADDRESS);
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoGetCalData(int& calData)
 */
int HantekDSOIO::dsoGetCalData(int *calData)
{
    dsoIOMutex.lock();

    *calData = 0;
    int rv = readControl(CONTROL_COMMAND, (char*)calData, sizeof(char), VALUE_CALDATA);
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}


/*!
    \fn HantekDSOIO::dsoSetCalData(int& calData)
 */
int HantekDSOIO::dsoSetCalData(int *calData)
{
    dsoIOMutex.lock();

    int rv = writeControl(CONTROL_COMMAND, (char*)calData, sizeof(char), VALUE_CALDATA);
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoGetChannelLevel(channel_levels *channelLevels)
 */
int HantekDSOIO::dsoGetChannelLevel(channel_levels *channelLevels)
{
    dsoIOMutex.lock();

    int rv = readControl(CONTROL_COMMAND, (char*)channelLevels, sizeof(channel_levels),
        VALUE_CHANNELLEVEL);
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}

/*!
    \fn HantekDSOIO::dsoSetChannelLevel(channel_levels *channelLevels)
 */
int HantekDSOIO::dsoSetChannelLevel(channel_levels *channelLevels)
{
    dsoIOMutex.lock();

    int rv = writeControl(CONTROL_COMMAND, (char*)channelLevels, sizeof(channel_levels),
        VALUE_CHANNELLEVEL);
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;
}


/*!
    \fn HantekDSOIO::dsoSetOffset(int ch1Offset, int ch2Offset, int extOffset)
 */
int HantekDSOIO::dsoSetOffset(int ch1Offset, int ch2Offset, int extOffset)
{
    unsigned char offset[17] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

    offset[0] = (unsigned char)(ch1Offset >> 8) | 0x20;
    offset[1] = (unsigned char)ch1Offset;
    offset[2] = (unsigned char)(ch2Offset >> 8) | 0x20;
    offset[3] = (unsigned char)ch2Offset;
    offset[4] = (unsigned char)(extOffset >> 8) | 0x20;
    offset[5] = (unsigned char)extOffset;

    dsoIOMutex.lock();

    int rv = writeControl(CONTROL_SETOFFSET, offset, sizeof(offset));
    if (rv < 0)
    {
        dsoIOMutex.unlock();
        qDebug("In function %s", __FUNCTION__);

        return rv;
    }

    dsoIOMutex.unlock();
    return 0;

}
