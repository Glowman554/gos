#include "vga.h"
#include <stdint.h>
#include "fonts.h"

void setpixel(int x, int y, char c){
	asm("int $0x30" : : "a" (15), "b" (x), "c" (y), "d" (c));
}

volatile void draw_char(char c, int x, int y, uint32_t fgcolor, uint32_t bgcolor) {
	int cx,cy;
	int mask[8]={1,2,4,8,16,32,64,128};
	const char *glyph=LSB[((int)c)];
		
	for(cy=0;cy<14;cy++){
		for(cx=0;cx<8;cx++){
			setpixel(cx+x,cy+y,glyph[cy]&mask[cx]?fgcolor:bgcolor);
		}
	}
}