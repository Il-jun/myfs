#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct direct_data{
	char * file_contents;
}direct_data;

typedef struct indirect_data{
	direct_data * ddata1;
	direct_data * ddata2;
	direct_data * ddata3;
	direct_data * ddata4;
	direct_data * ddata5;
	direct_data * ddata6;
	direct_data * ddata7;
	direct_data * ddata8;
}indirect_data;
	



typedef struct inode{
	int inode_num;
	_Bool type;//디럭터리인지 파일인지 구분(디렉터리 = 0, 파일 = 1)
	char * filename;   // 파일 이름 최대 7글자
	time_t time_;//만들어진 시간을 확인ㅑ
	direct_data * ddata1;
	direct_data * ddata2;
	direct_data * ddata3;
	direct_data * ddata4;
	direct_data * ddata5;
	direct_data * ddata6;
	direct_data * ddata7;
	direct_data * ddata8;
	indirect_data * idata;
	struct inode *iptr;

}inode; // inode를 위한 구조체 선언

inode mkfirstinode(void) // 루트디렉터리 생성;
{
	FILE * fp;

	fp = fopen("inode.bin", "wb");

	inode * root = (inode *)malloc(sizeof(inode));
	root -> inode_num = 1;
	root -> type = 0;
	root -> filename = "root";
	root -> time_ = time(NULL);
	root -> iptr = NULL;

	fwrite((void*)&root, sizeof(inode), 1, fp);
	fclose(fp);
}

int main(void)
{
	inode check;

	check = mkfirstinode();
	
	printf("%d %d %s %ld", check.inode_num, check.type, check.filename, check.time_);

}



/*
int makeinode (inode * i, int num, int use){//만들고자 하는 inode, 종류, 저장될 데이터블록 시작점, 몇개 사용할 것인지
	i -> p = calloc(use, sizeof(int)); //사용되는 데이터블럭 동적 할당
	i->t = time(NULL);//현재시간
	for (int j = 0; j<use; j++){
		i->p[j] = (num+1+j);//data블록에 순차적으로 저장
	}
	return (num+use+1);//다음 저장될 곳 리턴
}

int find_empty_inode (){
*/
