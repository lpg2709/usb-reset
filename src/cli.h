#ifndef CLI_H
#define CLI_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>

#include "./device.h"

bool menu(usb_device devices[MAX_DEVICES], ssize_t l_size);

#endif // CLI_H
