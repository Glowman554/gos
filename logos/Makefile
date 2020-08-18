SRCS = $(shell find -name '*.c')
OBJS = $(addsuffix .o,$(basename $(SRCS)))

CC = gcc
LD = ld

APP_NAME=logos.bin

SYSLIB = ../lib/syslib.o

ASFLAGS = -m32
CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc -I include
LDFLAGS = -melf_i386 -T app.ld

all: app

app: $(OBJS)
	$(LD) $(LDFLAGS) -o $(APP_NAME) $^ $(SYSLIB)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	
install: app
	cp $(APP_NAME) ../cdrom_files/gui/.

clean:
	rm $(OBJS)

.PHONY: clean app all

