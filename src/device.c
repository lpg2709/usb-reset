#include "./device.h"

void init_devices(usb_device d[MAX_DEVICES]){
	int i;
	for(i = 0; i < MAX_DEVICES; i++){
		d[i].toReset = false;
	}
}

void toggle_reset(usb_device *d){
	d->toReset = d->toReset == true ? false : true;
}

