all: init desktop terminal writer cursor logos info

CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc -I include

init: syslib.o 
	$(MAKE) -C init


desktop: syslib.o 
	$(MAKE) -C desktop

cursor: syslib.o 
	$(MAKE) -C cursor

logos: syslib.o 
	$(MAKE) -C logos

info: syslib.o 
	$(MAKE) -C info

terminal: syslib.o 
	$(MAKE) -C terminal

writer: syslib.o 
	$(MAKE) -C writer
	
syslib.o: syslib.c
	$(CC) $(CFLAGS) -c -o $@ $^
	
clean:
	$(MAKE) -C init clean
	$(MAKE) -C desktop clean
	$(MAKE) -C cursor clean
	$(MAKE) -C logos clean
	$(MAKE) -C info clean
	$(MAKE) -C terminal clean
	$(MAKE) -C writer clean
	rm *.o

.PHONY: init all desktop terminal writer cursor logos info clean
