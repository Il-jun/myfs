#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "struct.h"

void save_file_data (inode * i){
	char ch;
	char * temp;
	int num = 1;
	FILE * data_b;
	FILE * file = fopen(i->filename, "rb+");
	temp = malloc(256);
	data_b = fopen("datablock", "ab");
	
	while (num < 9) {
		int e_num = find_empty_datab();
		fseek(data_b, 256*e_num, 0);
		while ((ch = getc(file)) != EOF && ftell(file) != 256*num) {
			putc(ch, data_b);
		}
		add_sblock_inode(e_num);
		num++;
		if (ch == EOF)
			break;
	}
}

void load_file (inode i) {
	
}

int get_size (char * file_name) {
	FILE * f;
	int size;
	f = fopen(file_name, "r");
	fseek (f, 0, SEEK_END);
	size = ftell(f);
	fclose(f);
	return size;
}