#include <stdint.h>
#include <stdbool.h>
#include <syslib.h>

void kernelfunc_debugerror(){
	asm volatile("int $0x1");
}

void _start(void)
{	
	bool reading = true;
	pchar(0xf,10); // return
    
	int len = 0;
	char in[100];
	
    
    while(1){
		pstring(0xf, ">>");
		while(reading){
			in[len] = getchar();
			pchar(0x8, in[len]);
			if(in[len] == 10){
				in[len] = '\0';
				reading = false;
			}else{
				len++;
			}
			
			reset_tick();
			while(get_tick() < 5);
		}
		
		if(strcmp(in, "ls")==0) ls();
		if(strcmp(in, "lspci")==0) lspci();
		if(strcmp(in, "reboot")==0) reboot();
		if(strcmp(in, "time")==0){
			pnum(0xf,read_h());
			pchar(0xf,':');
			pnum(0xf,read_m());
			pchar(0xf,':');
			pnum(0xf,read_s());
			pchar(0xf,10);
		}
		if(strcmp(in, "help")==0){
			pstring(0xf, "Aviable Commands:");
			pchar(0xf,10); // return
        	pstring(0xf, "help");
			pchar(0xf,10); // return
    		pstring(0xf, "about");
			pchar(0xf,10); // return
    		pstring(0xf, "time");
    		pchar(0xf,10); // return
    		pstring(0xf, "reboot");
			pchar(0xf,10); // return
			pstring(0xf, "ls");
			pchar(0xf,10); // return
			pstring(0xf, "lspci");
			pchar(0xf,10); // return
			//pstring(0xf, "desktop");
			//pchar(0xf,10); // return
			pstring(0xf, "uname");
			pchar(0xf,10); // return
			pstring(0xf, "debugerr");
			pchar(0xf,10); // return
		}
		if(strcmp(in, "about")==0){
			pstring(0xf, "Programiert von glowman554");
			pchar(0xf,10); // return
    		pstring(0xf, "Vielen dank an das tolle tutorial von lowlevel.eu");
			pchar(0xf,10); // return
		}

		if(strcmp(in, "uname")==0){
			pstring(0xf, "Kernel Reports version ");
			pnum(0xf, kversion());
			pchar(0xf, 10);
			pstring(0xf, "Kernel reports vendor ");
			pstring(0xf, kvendor());
			pchar(0xf, 10);

		}
		if(strcmp(in, "debugerr")==0){
			asm volatile("int $0x30" : : "a" (RUNK), "b" (&kernelfunc_debugerror));

		}
		if(in[len-1] == 'n' && in[len-2] == 'i' && in[len-3] == 'b' && in[len-4] == '.'){
  			exec(in);
			exit(0);
		}

		
		reading = true;
		len = 0;
		
	}

    while(1);
}

