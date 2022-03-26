#ifndef LISTUSB_H
#define LISTUSB_H
#include <libusb-1.0/libusb.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "./device.h"

// https://github.com/gregkh/usbutils/blob/master/lsusb.c#L3637

bool listusb(usb_device *devices);

#endif // LISTUSB_H
