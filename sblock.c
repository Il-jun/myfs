#include <stdio.h>
#include "func.h"
#include "struct.h"
#define INODE 1
#define DBLOCK 0

void print_sblock (){
	FILE * sb;
	sb = fopen("superblock", "rb");
	rewind(sb);
	unsigned ch;
	for (char i = 0; i<12; i++){
		fread (&ch, sizeof(unsigned), 1, sb);
		printf ("%d ", ch);
	}
	printf ("\n");
	fclose(sb);
}

void set_sblock (_Bool kind, int num){ //0이면 데이터, 1이면 inode
	FILE * sb;
	unsigned mask = 1 << (sizeof(unsigned) * 8) - (num%32) - 1;
	print_sblock();
	sb = fopen("superblock", "rb+"); // 이진파일 열기
	rewind(sb); // 파일위치 지시자 맨앞으로
	fseek (sb, (num/32) * 4, SEEK_CUR);
	if (kind == INODE){ // inode면 맨앞부터 쓰기
		fwrite (&mask, sizeof(unsigned), 1, sb);
		fclose(sb);	
	}
	else { // 데이터블록 차지한거 표시
		fseek(sb, 16, SEEK_CUR);
		fwrite(&mask, sizeof(unsigned), 1, sb);
		fclose(sb);
		printf("yes\n");
	}
	print_sblock();
}

void make_sblock (){
	static sblock super;
	FILE * sb;
	if ((sb = fopen("superblock", "rb")) == NULL){
		sb = fopen("superblock", "wb");
		rewind(sb);
		unsigned zero = 0;
		for (char i = 0; i<12; i++)
			fwrite(&zero, sizeof(unsigned), 1, sb);
	}
	else{
		remove("superblock");
		make_sblock();
	}
	fclose (sb);
}

