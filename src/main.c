#include <stdio.h>
#include <stdlib.h>

#include "./listusb.h"
#include "./device.h"

int main(){
	usb_device *devices;

	listusb(devices);

	free(devices);
	return 0;
}

