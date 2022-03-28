#include "./listusb.h"
#include "./device.h"
#include "./reset.h"
#include "./cli.h"
#include "./arg_parser.h"

int main(int argc, char **argv){
	usb_device devices[MAX_DEVICES];
    ssize_t l_size;
	Options options;

	inti_options(&options);
	options_parser(&options, argc, argv);

	if(options.show_help)
		usage();
	else if(options.show_version)
		version();
	else
		if(options.bus == 0 && options.port == 0){
			if(listusb(devices, &l_size)){
				if(menu(devices, l_size, options))
					usb_reset_list(devices, l_size);
			}
		}else{
			usb_reset(options.bus, options.port);
		}

	return 0;
}

