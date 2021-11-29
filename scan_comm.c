#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void scan_comm (char ** comm1, char ** comm2, char ** comm3) {
	char *temp;
	char *p_str = NULL;
	int total_size = 0, size = 0, comm_num = 1; 
		
	temp = malloc(sizeof(char));
	while (1) {  
		fgets(temp, 2, stdin);
		size = strlen(temp);
		total_size += size;
		if (temp[0] == ' '){
			switch (comm_num) {
				case 1 :
					*comm1 = p_str;
					break;
				case 2 :
					*comm2 = p_str;
					break;
			}
			p_str = NULL;
			comm_num++;
			continue;
		}
		if (temp[0] == '\n') {
			if (comm_num == 1)
				*comm1 = p_str;
			if (comm_num == 2)
				*comm2 = p_str;
			if (comm_num == 3)
				*comm3 = p_str;
			break;
		}
			
		if (p_str == NULL) {  
			p_str = (char *)malloc(total_size + 1);
			strcpy(p_str, temp);
		}
		else {
			p_str = (char *)realloc(p_str, total_size + 1);
			strcat(p_str, temp);
		}
	}
}

void cmp_comm (char * comm1, char * comm2, char * comm3) {
	if (!strcmp(comm1, "myfs"))
		//make_fs();
	if (!strcmp(comm1, "myls"))
		//show_ls();
	if (!strcmp(comm1, "mycat"))
		
	if (!strcmp(comm1, "myshowfile"))
		
	if (!strcmp(comm1, "mypwd"))
		//print_pwd();
	if (!strcmp(comm1, "mycd"))
		
	if (!strcmp(comm1, "mycp"))
		
	if (!strcmp(comm1, "mycpto"))
		
	if (!strcmp(comm1, "mycpfrom"))
		
	if (!strcmp(comm1, "mymkdir"))
		
	if (!strcmp(comm1, "myrmdir"))
		
	if (!strcmp(comm1, "myrm"))
		
	if (!strcmp(comm1, "mymv"))
		
	if (!strcmp(comm1, "mytouch"))
		
	if (!strcmp(comm1, "myinode"))
		
	if (!strcmp(comm1, "mydatablock"))
		
	if (!strcmp(comm1, "mystate"))
		
	if (!strcmp(comm1, "mytree"))
		
	if (!strcmp(comm1, "exit"))
		exit(0);
}