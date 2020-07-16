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
	pstring(0xf, "1 -> Terminal Boot");
	pchar(0xf, 10);
	pstring(0xf, "2 -> Desktop Boot");
	pchar(0xf, 10);
	
	char in = getchar();
	
	switch(in){
		case '1':
			exec("terminal.bin");
			break;
		case '2':
			exec("desktop.bin");
			break;
	}
	exit(0);
}

