#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "struct.h"

char * set_time(void) //시간설정함수
{
	char * time_ = malloc(sizeof(char) * 20);

	struct tm * date;
	const time_t t = time(NULL);
	date = localtime(&t);

	sprintf(time_, "%d/%d/%d %d:%d:%d", date -> tm_year + 1900, date -> tm_mon + 1, date -> tm_mday, date -> tm_hour, date -> tm_min, date -> tm_sec);
	return (time_);
}

void mkinode(int inode_num, _Bool type, char * filename)
{
	FILE * fp;

	fp = fopen("inode.bin", "ab");

	inode mkinode;
	mkinode.inode_num = inode_num;
	mkinode.type = type;
	mkinode.filename = malloc(sizeof(char) * 8);
	strcpy(mkinode.filename, filename);
	mkinode.time_ = malloc(sizeof(char) * 20);
	mkinode.time_ = set_time();

	fwrite((void*)&mkinode, sizeof(inode), 1, fp);
	fclose(fp);
}

void mkfirstinode(void) // 루트디렉터리 생성;
{
	FILE * fp;

	fp = fopen("inode.bin", "wb");

	inode root;
	root.inode_num = 1;
	root.type = 0;
	root.filename = malloc (sizeof(char) * 8); // root 이름 저장을 위한 메모리 할당
	strcpy(root.filename, "root"); // root 이름 저장
	root.time_ = malloc(sizeof(char) * 20);
	root.time_ = set_time();

	fwrite((void*)&root, sizeof(inode), 1, fp);
	fclose(fp);
}

int main () {
	mkfirst_sblock();
	mkfirstinode();
	mkinode(1, 1, "test");
	save_file_data (1, "test.txt");
	load_file(1);
}

inode load_inode (int inum) {
	FILE *fp;
	fp = fopen("inode.bin", "rb");
	rewind(fp);
	inode tmp;
	while (1) {
		fread(&tmp, sizeof(inode), 1, fp);
		if(tmp.inode_num == inum) 
			break;
	}
	fclose (fp);
	return tmp;
}

void save_file_data (int i_num, char * filename){
	char ch;
	char * temp;
	inode tmp = load_inode(i_num);
	int num = 1;
	FILE * data_b;
	FILE * file = fopen(filename, "r");
	temp = malloc(256);
	data_b = fopen("datablock", "ab");
	
	while (num < 9) {
		int e_num = find_empty_datab();
		fseek(data_b, 256*e_num, 0);
		while ((ch = getc(file)) != EOF && ftell(file) != 256*num) {
			fwrite (&ch, sizeof(char), 1, data_b);
		}
		if (ch == EOF)
			fwrite ("\0", sizeof(char), 1, data_b);
		add_sblock_inode(e_num);
		switch (num) {
			case 1 :
				tmp.data1 = e_num;
				break;
			case 2 :
				tmp.data2 = e_num;
				break;
			case 3 :
				tmp.data3 = e_num;
				break;
			case 4 :
				tmp.data4 = e_num;
				break;
			case 5 :
				tmp.data5 = e_num;
				break;
			case 6 :
				tmp.data6 = e_num;
				break;
			case 7 :
				tmp.data7 = e_num;
				break;
			case 8 :
				tmp.data8 = e_num;
				break;
		}
		num++;
		if (ch == EOF)
			break;
	}
	FILE * fp;
	fp = fopen("inode.bin", "ab");
	fseek(fp, sizeof(inode) * i_num, 0);
	fwrite((void*)&tmp, sizeof(inode), 1, fp);
	fclose(fp);
}

void make_dir_data (inode * i) {
	char * temp;
	FILE * data_b;
	FILE * file = fopen(i->filename, "rb+");
	temp = malloc(256);
	data_b = fopen("datablock", "ab");
	
}

void load_file (int i_num) {
	FILE * data_b;
	inode tmp = load_inode(i_num);
	int num = 0;
	char ch;
	_Bool b = 0;

	data_b = fopen("datablock", "rb");
	printf("%d", tmp.data1);
	if (b==0) {
		fseek(data_b, (256 * tmp.data1)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			printf("%c", ch);
			if (ch == '\0') {
				b = 1;
				break;
			}
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data2 != 0) {
		fseek(data_b, (256 * tmp.data2)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data3 != 0) {
		fseek(data_b, (256 * tmp.data3)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data4 != 0) {
		fseek(data_b, (256 * tmp.data4)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data5 != 0) {
		fseek(data_b, (256 * tmp.data5)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data6 != 0) {
		fseek(data_b, (256 * tmp.data6)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data7 != 0) {
		fseek(data_b, (256 * tmp.data7)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
	if (b==0 && tmp.data8 != 0) {
		fseek(data_b, (256 * tmp.data8)-1, 0);
		do {
			fread (&ch, 1, 1, data_b);
			if (ch == '\0') {
				b = 1;
				break;
			}
			printf("%c", ch);
			num++;
		} while (num<256);
	}
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