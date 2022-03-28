#ifndef RESET_H
#define RESET_H
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/usbdevice_fs.h>

#include "./device.h"

void reset(uint8_t bus, uint8_t port);
int usb_reset(uint8_t bus, uint8_t port);
int usb_reset_list(usb_device d[MAX_DEVICES], ssize_t l_size);

#endif // RESET_H
