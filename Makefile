CC=gcc
CFLAG=-Wall
LFLAG=-lusb -lusb-1.0
C_SOURCES=$(wildcard ./src/*.c)
OBJ=$(C_SOURCES:.c=.o)
P_NAME=usb-reset
RM = rm -rf

all: $(P_NAME)

$(P_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAG) $(LFLAG)

clean:
	@ $(RM) $(OBJ) $(P_NAME)

install: $(P_NAME)
	install -D ./$(P_NAME) $(DESTDIR)$(prefix)/bin/$(P_NAME)

uninstall: $(P_NAME)
	@ $(RM) $(DESTDIR)$(prefix)/bin/$(P_NAME)

.PHONY: all clean install uninstall
