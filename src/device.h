#ifndef DEVICE_H
#define DEVICE_H
#include <stdbool.h>
#include <stdint.h>

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

void setToReset(usb_device *d);

#endif // DEVICE_H
