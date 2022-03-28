#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>



typedef struct stc_option Options;

struct stc_option {
	bool confirmation;
	bool show_help;
	bool show_version;
	uint8_t bus;
	uint8_t port;
};

void inti_options(Options *opt);
bool options_parser(Options *opt, int argc, char **argv);

#endif
