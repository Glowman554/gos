#include "syslib.h"
#include <stdint.h>

void pchar(char c, char msg){
	asm("int $0x30" : : "a" (PUTC), "b" (msg), "c" (c)); 
}

void pnum(char c, int num){
	asm("int $0x30" : : "a" (PNUM), "b" (num), "c" (c));
}

void pstring(char c, char msg[])
{
	int i;
    for (i = 0; msg[i] != '\0'; i++) {
    	asm("int $0x30" : : "a" (PUTC), "b" (msg[i]), "c" (c));
    }
}

char getchar(){
	register char input asm("ebx");
	asm("int $0x30" : : "a" (GETCHAR));
	return input;
}

int read_h(){
	register uint32_t input asm("ebx");
	asm("int $0x30" : : "a" (READ_H));
	return input;
}

int read_m(){
	register int input asm("ebx");
	asm("int $0x30" : : "a" (READ_M));
	return input;
}

int read_s(){
	register int input asm("ebx");
	asm("int $0x30" : : "a" (READ_S));
	return input;
}

void reboot(){
	asm("int $0x30" : : "a" (REBOOT));
}

void reset_tick(){
	asm("int $0x30" : : "a" (RTICK));
}

int get_tick(){
	register int input asm("ebx");
	asm("int $0x30" : : "a" (GTICK));
	return input;
}

void setx(int x){
	asm("int $0x30" : : "a" (SETX), "b" (x));
}
void sety(int y){
	asm("int $0x30" : : "a" (SETY), "b" (y));
}

void clrscr(){
	asm("int $0x30" : : "a" (CLRSCR));
}

void ls(){
	asm("int $0x30" : : "a" (LS));
}

void exec(char p[]){
	asm("int $0x30" : : "a" (LOADF), "b" (p));
}


int strcmp(char *str1, char *str2)
{
      int i = 0;
      int failed = 0;
      while(str1[i] != '\0' && str2[i] != '\0')
      {
          if(str1[i] != str2[i])
          {
              failed = 1;
              break;
          }
          i++;
      }
      // why did the loop exit?
      if( (str1[i] == '\0' && str2[i] != '\0') || (str1[i] != '\0' && str2[i] == '\0') )
          failed = 1;
  
      return failed;
}

int strlen(char *src)
{
    int i = 0;
    while (*src++)
        i++;
    return i;
}

void lspci(){
	asm("int $0x30" : : "a" (LSPCI));
}

int kversion(){
	register uint32_t input asm("ebx");
	asm("int $0x30" : : "a" (KVER));
	return input;
}

int getmov(){
	register char input asm("ebx");
	asm("int $0x30" : : "a" (GETMOV));
	return input;
}

void setpixel(int x, int y, char c){
	asm("int $0x30" : : "a" (SPIXEL), "b" (x), "c" (y), "d" (c));
}

char getpixel(int x, int y){
	register char c asm("edx");
	asm("int $0x30" : : "a" (GPIXEL), "b" (x), "c" (y));
	return c;
}

void exit(int code){
	asm("int $0x30" : : "a" (EXIT), "b" (code));
	while(1);
}

int kvendor(){
	register uint32_t input asm("ebx");
	asm("int $0x30" : : "a" (KVEN));
	return input;
}