#include "./listusb.h"
#include <stdlib.h>


bool listusb(usb_device *devices){
    libusb_context *context;
    libusb_device **list;
    ssize_t         count;
    size_t          index;


    if (libusb_init(&context) != 0)
     {
        fprintf(stderr, "error: intializing `libusb'");
        return -1;
     }

    count = libusb_get_device_list(context, &list);

	devices = malloc(sizeof(usb_device) * count);

    for (index = 0; index < count; ++index)
    {
        struct libusb_device *device;
        struct libusb_device_descriptor descriptor;
        char str_product[256];
        char str_manufacturer[256];
        struct libusb_device_handle *handle;
        int result;
		u_int8_t bus;
		u_int8_t port;

        device = list[index];
        if ((result = libusb_get_device_descriptor(device, &descriptor)) != 0)
         {
            fprintf(stderr, "error(%d): reading descriptor\n", result);
            continue;
         }

        if ((result = libusb_open(device, &handle)) != 0)
         {
            fprintf(stderr, "error(%d): openning device 0x%04X:0x%04X\n",
                result, descriptor.idVendor, descriptor.idProduct);
            continue;
         }

        result = libusb_get_string_descriptor_ascii(
            handle,
            descriptor.iProduct,
            (unsigned char *)str_product,
            sizeof(str_product)
        );

        result = libusb_get_string_descriptor_ascii(
            handle,
            descriptor.iManufacturer,
            (unsigned char *)str_manufacturer,
            sizeof(str_manufacturer)
        );

		bus = libusb_get_bus_number(device);
		port = libusb_get_port_number(device);
		devices->port = port;
		devices->bus = bus;
		devices->idVendor = descriptor.idVendor;
		devices->idProduct = descriptor.idProduct;

        if (result != 0)
            fprintf(stdout, "Bus %.3u Port %.3u: ID %04X:%04X %s %s\n", bus, port, descriptor.idVendor, descriptor.idProduct, str_manufacturer, str_product);

        libusb_close(handle);
    }
    return true;
}
