all: init desktop terminal writer

CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc -I include

init: syslib.o 
	$(MAKE) -C init


desktop: syslib.o 
	$(MAKE) -C desktop

terminal: syslib.o 
	$(MAKE) -C terminal

writer: syslib.o 
	$(MAKE) -C writer
	
syslib.o: syslib.c
	$(CC) $(CFLAGS) -c -o $@ $^
	
.PHONY: init all desktop terminal writer