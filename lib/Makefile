all: syslib.o

CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc -I include
	
syslib.o: syslib.c
	$(CC) $(CFLAGS) -c -o $@ $^
	
clean:
	rm *.o

.PHONY: all syslib