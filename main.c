#include <stdio.h>
#include <stdlib.h>
#include "func.h"

static int Is_Make_fs;

int main (){
	int Is_making = 0;
	if (Is_Make_fs == 0){
		Is_making = Make_fs();
		if (Is_making == 1)
			Is_Make_fs = 1;
		else{
			printf("파일시스템이 만들어지지 않았습니다. 다시 시도해주세요.");
			exit (1);
		}
	}
	char * comm;
	do {
		print_shell();
		comm = scan_comm();
		if (comm == "exit")
			exit(0);
		op_comm(comm);
	} while(1);
}



