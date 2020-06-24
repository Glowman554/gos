#include <stdint.h>
#include <stdbool.h>
#include "cursor.h"
#include "config.h"
#include "../include/syslib.h"


void _start(void)
{	
	//mouse right -> 77
    //mouse left -> 75
    //mouse up -> 72
    //mouse down -> 80
	while(1){
		int i = getmov();
		pnum(0xf,i);
		pchar(0xf,10);
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
				if(getcx() > 5 && getcx() < 25 && getcy() > 20 && getcy() < 40) {
					exec("info.bin");
				}
				if(getcx() > 5 && getcx() < 25 && getcy() > 45 && getcy() < 65) {
				}
		}
		
		reset_tick();
		while(get_tick() < 3);
	}
	
    while(1);
}

