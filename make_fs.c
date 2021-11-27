#include <stdio.h>
#include "struct.h"

void make_fs(){
	FILE * myfs;
	if ((myfs = fopen("myfs", "rb")) == NULL) { //myfs가 존재하지 않음
		printf("파일시스템이 없습니다. 파일시스템을 만듭니다.\n");
		myfs = fopen("myfs", "wb");
		//make_dir("root");
	}
	else {
		char ch;
		printf("파일시스템이 있습니다. 다시 만들겠습니까? (y/n)");
		do {
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'n' || ch == 'Y' || ch == 'N')
			break;
		} while (1);
		if (ch == 'y' || ch == 'Y'){
			fclose(myfs);
			remove("myfs");
			myfs = fopen("myfs", "wb");
			//make_dir("root");
		}
	}
}
int main (){
	make_fs();
}
