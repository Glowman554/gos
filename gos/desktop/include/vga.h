#ifndef VGA_H
#include <stdint.h>
#define VGA_H

void setpixel(int x, int y, char c);
volatile void draw_char(char c, int x, int y, uint32_t fgcolor, uint32_t bgcolor);

#endif