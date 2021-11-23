#include <stdio.h>
#include "func.h"

void make_fs(){
	
	FILE * sblock, * inode;
	sblock = fopen("sblock", "wb");
	inode = fopen ("inode", "wb");
	char ch = 0;									

	for (int i = 0; i<96; i++){
		fwrite(&ch, 1, 1, sblock);
	}
	fclose (sblock);
	sblock = fopen("sblock", "rb");
	char c;
	for (int i = 0; i<96; i++){
		fread(&c, 1, 1, sblock);
		printf ("%d ", c);
	}
	fclose (sblock);
}

int main (){
	make_fs();
}
