# usb-reset

Linux system utility for usb port reset.

## Dependencies

- [libusb](https://libusb.info/)

## Install

After clone the project:

```sh
cd usb-reset
sudo make install
```

## Usage

In this version enter the following command after installation

```sh
sudo usb-reset
```

## Script

To use usb-reset in scripts, it is possible to pass the bus and the port as
arguments, both being mandatory.

```sh
sudo ./usb-reset -b 1 -p 2
```

For more information:

```sh
usb-reset --help
```

## TODO

- Add Code standardization
- Add test cases
- Make program more consistent in use
