#ifndef DEVICE_H
#define DEVICE_H
#include <stdbool.h>
#include <stdint.h>

#define MAX_DEVICES 100

typedef struct struct_usb_device usb_device;

struct struct_usb_device {
	uint8_t bus;
	uint8_t port;
	uint16_t idVendor;
	uint16_t idProduct;
	unsigned char manufacturer[215];
	unsigned char product[215];
	bool toReset;
};

void init_devices(usb_device d[MAX_DEVICES]);
void toggle_reset(usb_device *d);

#endif // DEVICE_H
