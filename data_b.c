#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "struct.h"

direct_data temp_data;

void save_data (char * file_name){
	char ch;
	int size;
	FILE * sfile, * sdfile;
	temp_data = malloc(256);
	size = get_size (file_name);
	sfile = fopen (file_name, "r");
	rewind (sfile);
	if (size >256) {
		int file_num = size/256;
		for (int i = 1; i <= file_num; i++) {
			while (ftell != 256 * i){
				ch = getc(sfile);
				putc (ch, sdfile);
			}
		}
	}
	else {
		
}

void load_file (char * file_name) {
	
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