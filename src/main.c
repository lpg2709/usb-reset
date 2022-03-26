#include "./listusb.h"
#include "./device.h"
#include "./reset.h"
#include "./cli.h"

int main(){
	usb_device devices[MAX_DEVICES];
    ssize_t l_size;


	if(listusb(devices, &l_size)){
		if(menu(devices, l_size))
			usb_reset(devices, l_size);
	}

	return 0;
}

