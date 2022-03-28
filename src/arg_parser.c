#include "./arg_parser.h"

void inti_options(Options *opt){
	opt->confirmation = true;
	opt->show_help = false;
	opt->show_version = false;
	opt->bus = 0;
	opt->port = 0;
}

uint8_t getInNumber(char *str){
	return (uint8_t) atoi(str);
}

bool options_parser(Options *opt, int argc, char **argv){
	int i = 1;

	while(i < argc){
		char *o = argv[i];
		if(strcmp(o, "--version") == 0 || strcmp(o, "-v") == 0){
			opt->show_version = true;
		}

		if(strcmp(o, "--help") == 0 || strcmp(o, "-h") == 0){
			opt->show_help = true;
		}

		if(strcmp(o, "--yes") == 0 || strcmp(o, "-y") == 0){
			opt->confirmation = false;
		}

		if(strcmp(o, "--bus") == 0 || strcmp(o, "-b") == 0){
			i++;
			opt->bus = getInNumber(argv[i]);
		}

		if(strcmp(o, "--port") == 0 || strcmp(o, "-p") == 0){
			i++;
			opt->port = getInNumber(argv[i]);
		}

		i++;
	}

	return true;
}
