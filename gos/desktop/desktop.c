#include <stdint.h>
#include <stdbool.h>
#include "vga.h"
#include "config.h"
#include "interface.h"
#include "../include/syslib.h"


void _start(void)
{	
	asm("int $0x30" : : "a" (14)); //init vga mode
	init_desktop();
	exec("cursor.bin");
	exec("logos.bin");
	
	/*
	create_view(30,35,210,100,"info");
	
	int ox = 31;
	int oy = 36;
	char i1[] = "Under Construction";
	
	int len = strlen(i1);
	for(int i = 0; i < len; i++)
	{
		draw_char(i1[i], ox+1+(i*8), oy, 10, 7);	
	}*/
	
    while(1);
}

