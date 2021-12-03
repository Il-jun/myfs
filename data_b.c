#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "struct.h"

int main () {
	inode i1;
	i1.filename = malloc (sizeof(char) * 10);
	i1.filename = "test.txt";
	mkfirst_sblock();
	save_file_data (&i1);
	
}

void save_file_data (inode * i){
	char ch;
	char * temp;
	int num = 1;
	FILE * data_b;
	FILE * file = fopen(i->filename, "ab");
	temp = malloc(256);
	data_b = fopen("datablock", "ab");
	
	while (num < 9) {
		int e_num = find_empty_datab();
		fseek(data_b, 256*e_num, 0);
		while ((ch = getc(file)) != EOF && ftell(file) != 256*num) {
			putc(ch, data_b);
		}
		add_sblock_inode(e_num);
		switch (num) {
			case 1 :
				i -> data1 = e_num;
				break;
			case 2 :
				i -> data2 = e_num;
				break;
			case 3 :
				i -> data3 = e_num;
				break;
			case 4 :
				i -> data4 = e_num;
				break;
			case 5 :
				i -> data5 = e_num;
				break;
			case 6 :
				i -> data6 = e_num;
				break;
			case 7 :
				i -> data7 = e_num;
				break;
			case 8 :
				i -> data8 = e_num;
				break;
		}
		num++;
		if (ch == EOF)
			break;
	}
}

void make_dir_data (inode * i) {
	char * temp;
	FILE * data_b;
	FILE * file = fopen(i->filename, "rb+");
	temp = malloc(256);
	data_b = fopen("datablock", "ab");
	
}

void load_file (inode i) {
	;
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