#include <stdint.h>
#include <stdbool.h>
#include "../include/syslib.h"
#include "config.h"


void _start(void)
{	
	clrscr();
	pchar(0xf,10);
	pstring(0xa, "Loading gos version ");
	pnum(0xa, VERSION);
	pstring(0xa, " with GKernel version ");
	pnum(0xa, kversion());
	pchar(0xf,10); // return

	pstring(0x4, "Note: This is a alpha release");
	pchar(0xf, 10);
	exec("terminal.bin");
    while(1);
}

