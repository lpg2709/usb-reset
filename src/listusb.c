#include "./listusb.h"

bool listusb(usb_device devices[MAX_DEVICES], ssize_t *l_size){
	libusb_context *context;
	libusb_device **list;
	size_t index;

	if (libusb_init(&context) != 0)
	 {
		fprintf(stderr, "error: intializing `libusb'");
		return -1;
	 }

	*l_size = libusb_get_device_list(context, &list);

	for (index = 0; index < *l_size; ++index)
	{
		struct libusb_device *device;
		struct libusb_device_descriptor descriptor;
		struct libusb_device_handle *handle;
		int result;

		device = list[index];
		if ((result = libusb_get_device_descriptor(device, &descriptor)) != 0){
			fprintf(stderr, "error(%d): reading descriptor!\n", result);
			continue;
		}

		if ((result = libusb_open(device, &handle)) != 0) {
			fprintf(stderr, "error(%d): openning device 0x%04X:0x%04X!\n",result, descriptor.idVendor, descriptor.idProduct);
			return false;
		}

		if ((result = libusb_get_string_descriptor_ascii(handle, descriptor.iProduct, devices[index].product, sizeof(devices[index].product))) == 0){
			fprintf(stderr, "error(%d): Get device 0x%04X:0x%04X product string!\n", result, descriptor.idVendor, descriptor.idProduct);
			continue;
		}

		if ((result = libusb_get_string_descriptor_ascii(handle, descriptor.iManufacturer, devices[index].manufacturer, sizeof(devices[index].manufacturer))) == 0){
			fprintf(stderr, "error(%d): Get device 0x%04X:0x%04X manufacturer string!\n", result, descriptor.idVendor, descriptor.idProduct);
			continue;
		}

		devices[index].bus = libusb_get_bus_number(device);
		devices[index].port = libusb_get_device_address(device);
		devices[index].idVendor = descriptor.idVendor;
		devices[index].idProduct = descriptor.idProduct;

		libusb_close(handle);
	}

	return true;
}
