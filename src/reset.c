#include "./reset.h"

void reset(uint8_t bus, uint8_t port){
	char filename[255];
	int fd;
	int rc;

	snprintf(filename, sizeof(filename), "/dev/bus/usb/%.3u/%.3u", bus, port);

	fd = open(filename, O_WRONLY);
	if (fd < 0) {
		fprintf(stderr, "Error opening output file %s\n", filename);
	}else{
		fprintf(stdout, "\rResetting USB device %s ... ", filename);
		rc = ioctl(fd, USBDEVFS_RESET, 0);
		if (rc < 0) {
			fprintf(stderr, "Error in ioctl!\n");
		}else
			fprintf(stdout, "Reset successful\n");

		close(fd);
	}

}

int usb_reset(uint8_t bus, uint8_t port){
	reset(bus, port);
	return 0;
}

int usb_reset_list(usb_device d[MAX_DEVICES], ssize_t l_size){
	int i;
	for(i = 0; i < l_size; i++){
		if(d[i].toReset){
			reset(d[i].bus, d[i].port);
		}
	}
    return 0;
}
