#include "./reset.h"

int usb_reset(usb_device d[MAX_DEVICES], ssize_t l_size){
	int i;
	for(i = 0; i < l_size; i++){
		if(d[i].toReset){
			char filename[255];
			int fd;
			int rc;

			snprintf(filename, sizeof(filename), "/dev/bus/usb/%.3u/%.3u", d[i].bus, d[i].port);

			fd = open(filename, O_WRONLY);
			if (fd < 0) {
				fprintf(stderr, "Error opening output file %s\n", filename);
				continue;
			}else{
				fprintf(stdout, "\rResetting USB device %s ... ", filename);
				rc = ioctl(fd, USBDEVFS_RESET, 0);
				if (rc < 0) {
					fprintf(stderr, "Error in ioctl!\n");
					continue;
				}else
					fprintf(stdout, "Reset successful\n");

				close(fd);
			}
		}
	}
    return 0;
}
