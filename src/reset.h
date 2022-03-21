#ifndef RESET_H
#define RESET_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>

int usb_reset(const char *bus, const char *device);

#endif // RESET_H
