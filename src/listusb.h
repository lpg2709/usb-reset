#ifndef LISTUSB_H
#define LISTUSB_H

#include <libusb-1.0/libusb.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct struct_usb_device usb_device;

struct struct_usb_device {
	uint8_t bus;
	uint8_t port;
	uint16_t idVendor;
	uint16_t idProduct;
	const char manufacturer[215];
	const char product[215];
	bool toReset;
};

// https://github.com/gregkh/usbutils/blob/master/lsusb.c#L3637

bool listusb(usb_device *devices);

#endif // LISTUSB_H
