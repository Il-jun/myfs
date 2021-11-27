#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main (){
	make_fs();
	char * comm;
	do {
		print_shell();
		comm = scan_comm();
		if (comm == "exit")
			exit(0);
		op_comm(comm);
	} while(1);
}



