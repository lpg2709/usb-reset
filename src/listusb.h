#ifndef LISTUSB_H
#define LISTUSB_H
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>
#include <libusb-1.0/libusb.h>

#include "./device.h"

// https://github.com/gregkh/usbutils/blob/master/lsusb.c#L3637

bool listusb(usb_device devices[MAX_DEVICES], ssize_t *l_size);

#endif // LISTUSB_H
