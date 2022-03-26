#include "./cli.h"

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

bool menu(usb_device devices[MAX_DEVICES], ssize_t l_size){

    size_t index;
    int8_t selected_index = 0;
	char confirmation;

	bool on_main_menu = true;
	while(on_main_menu) {
		system("clear");
		fprintf(stdout, "Press SPACE to toggle selection end ENTER to reset the selecteds: \n");
		for (index = 0; index < l_size; ++index){
			usb_device device = devices[index];
			fprintf(stdout,
					"%c [%c] Bus %.3u Port %.3u: ID %04X:%04X %s %s\n",
					selected_index == index ? '>' : ' ',
					device.toReset == true ? 'x' : ' ',
					device.bus, device.port,
					device.idVendor, device.idProduct,
					device.manufacturer, device.product);
		}

		switch(getch()){
			case ' ':
				toggle_reset(&devices[selected_index]);
				break;
			case '\n':
				on_main_menu = false;
				break;
			case 'A':
				selected_index--;
				if(selected_index < 0)
					selected_index = 0;
				break;
			case 'B':
				selected_index++;
				if(selected_index > l_size - 1)
					selected_index = l_size - 1;
				break;
		}
	}

	system("clear");
	fprintf(stdout, "The follow devices gone be reseted\n");
	for (index = 0; index < l_size; ++index){
		usb_device device = devices[index];
		if(device.toReset)
			fprintf(stdout,
					"Bus %.3u Port %.3u: ID %04X:%04X %s %s\n",
					device.bus, device.port,
					device.idVendor, device.idProduct,
					device.manufacturer, device.product);
	}
	fprintf(stdout, "You confirm the selection? (y/n) ");

	confirmation = getchar();
	getchar();

	if(confirmation == 'y' || confirmation == 'Y')
		return true;
	else{
		fprintf(stdout, "Operation canceled!\n");
		return false;
	}
}
