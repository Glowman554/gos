#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "../include/syslib.h"

char pixbuf[15] = {0};

void loadpixel();
void savepixel();
void redraw();

bool reloadp = false;

int x,y = 0;

void cursor_move_up() {
	//kprintf(0x4,"%d,%d\n", x,y);
	if(reloadp) loadpixel();
	y--;
	savepixel();
	reloadp = true;
	redraw();
}

void cursor_move_down() {
	//kprintf(0x4,"%d,%d\n", x,y);
	if(reloadp) loadpixel();
	y++;
	savepixel();
	reloadp = true;
	redraw();
}

void cursor_move_left() {
	//kprintf(0x4,"%d,%d\n", x,y);
	if(reloadp) loadpixel();
	x--;
	savepixel();
	reloadp = true;
	redraw();
}

void cursor_move_right() {
	//kprintf(0x4,"%d,%d\n", x,y);
	if(reloadp) loadpixel();
	x++;
	savepixel();
	reloadp = true;
	redraw();
}

void redraw() {
	setpixel(x,y,15);
	setpixel(x+1,y,15);
	setpixel(x,y+1,15);
	setpixel(x+1,y+1,15);
	setpixel(x+2,y,15);
	setpixel(x,y+2,15);
	setpixel(x+2,y+2,15);
	setpixel(x+1,y+2,15);
	setpixel(x+2,y+1,15);
	setpixel(x+3,y,15);
	setpixel(x,y+3,15);
	setpixel(x+4,y+4,15);
	setpixel(x+5,y+5,15);
	setpixel(x+3,y+3,15);
	setpixel(x+6,y+6,15);

}

void loadpixel(){
	setpixel(x,y,pixbuf[0]);
	setpixel(x+1,y,pixbuf[1]);
	setpixel(x,y+1,pixbuf[2]);
	setpixel(x+1,y+1,pixbuf[3]);
	setpixel(x+2,y,pixbuf[4]);
	setpixel(x,y+2,pixbuf[5]);
	setpixel(x+2,y+2,pixbuf[6]);
	setpixel(x+1,y+2,pixbuf[7]);
	setpixel(x+2,y+1,pixbuf[8]);
	setpixel(x+3,y,pixbuf[9]);
	setpixel(x,y+3,pixbuf[10]);
	setpixel(x+4,y+4,pixbuf[11]);
	setpixel(x+5,y+5,pixbuf[12]);
	setpixel(x+3,y+3,pixbuf[13]);
	setpixel(x+6,y+6,pixbuf[14]);

}

void savepixel() {
	pixbuf[0] = getpixel(x,y);
	pixbuf[1] = getpixel(x+1,y);
	pixbuf[2] = getpixel(x,y+1);
	pixbuf[3] = getpixel(x+1,y+1);
	pixbuf[4] = getpixel(x+2,y);
	pixbuf[5] = getpixel(x,y+2);
	pixbuf[6] = getpixel(x+2,y+2);
	pixbuf[7] = getpixel(x+1,y+2);
	pixbuf[8] = getpixel(x+2,y+1);
	pixbuf[9] = getpixel(x+3,y);
	pixbuf[10] = getpixel(x,y+3);
	pixbuf[11] = getpixel(x+4,y+4);
	pixbuf[12] = getpixel(x+5,y+5);
	pixbuf[13] = getpixel(x+3,y+3);
	pixbuf[14] = getpixel(x+6,y+6);
	
	//pnum(0xf, getpixel(x,y));
	//pchar(0xf,10);
	
	//for(int i = 0; i<15; i++){pnum(0xf,pixbuf[i]); pchar(0xf,10);}

}

void _start(void)
{	
	//mouse right -> 77
    //mouse left -> 75
    //mouse up -> 72
    //mouse down -> 80
	while(1){
		int i = getmov();
		//pnum(0xf,i);
		//pchar(0xf,10);
		switch(i){
			case UP:
				cursor_move_up();
				break;
			case DOWN:
				cursor_move_down();
				break;
			case LEFT:
				cursor_move_left();
				break;
			case RIGHT:
				cursor_move_right();
				break;
			case OK:
				if(x > 5 && x < 25 && y > 20 && y < 40) {
					exec("info.bin");
				}
		}
		
		reset_tick();
		while(get_tick() < 3);
	}
	
    while(1);
}

