#include "header.h"

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
	char * time_;//만들어진 시간을 확인ㅑ
	direct_data * ddata1;
	direct_data * ddata2;
	direct_data * ddata3;
	direct_data * ddata4;
	direct_data * ddata5;
	direct_data * ddata6;
	direct_data * ddata7;
	direct_data * ddata8;
	indirect_data * idata;

}inode; // inode를 위한 구조체 선언

char * set_time(void) //시간설정함수
{
	char * time_ = malloc(sizeof(char) * 20);

	struct tm * date;
	const time_t t = time(NULL);
	date = localtime(&t);

	sprintf(time_, "%d/%d/%d %d:%d:%d", date -> tm_year + 1900, date -> tm_mon + 1, date -> tm_mday, date -> tm_hour, date -> tm_min, date -> tm_sec);
	return (time_);
}







void mkfirstinode(void) // 루트디렉터리 생성;
{
	FILE * fp;

	fp = fopen("inode.bin", "wb");

	inode root;
	root.inode_num = 1;
	root.type = 0;
	root.filename = malloc (sizeof(char) * 5); // root 이름 저장을 위한 메모리 할당
	strcpy(root.filename, "root"); // root 이름 저장
	root.time_ = malloc(sizeof(char) * 20);
	root.time_ = set_time();

	fwrite((void*)&root, sizeof(inode), 1, fp);
	fclose(fp);
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

void tmp_inode_2(void) //임시 inode 2개 생성;
{

	char * b_fname = "hi_b";
	char * c_fname = "hi_c";
	int inum = 3;

	mkinode(2, 1, b_fname);
	mkinode(3, 0, c_fname);


}

void myinode(int inum) 	//인자 출력할 inode 번호 
{
	FILE *fp;
	fp = fopen("inode.bin", "rb");

	rewind(fp);

	inode tmp;

	while(1)
	{
		fread(&tmp, sizeof(inode), 1, fp);
		if(tmp.inode_num == inum) 
			break;
	}
	
	if(tmp.type == 0)
		printf("파일종류 : 디렉터리\n");
	else if(tmp.type == 1)
		printf("파일종류 : 파일\n");
	
	printf("생성일자 : %s\n", tmp.time_);
	printf("직업 블록 목록 : \n");
	printf("    #0 직접 데이터 블록 : \n");
	printf("    #1 직접 데이터 블록 : \n");
	printf("    #2 직접 데이터 블록 : \n");
	printf("    #3 직접 데이터 블록 : \n");
	printf("    #4 직접 데이터 블록 : \n");
	printf("    #5 직접 데이터 블록 : \n");
	printf("간접 블록 번호 : \n");
}
	
/*
void myls_0() //myls 인자 없을떄
{
}

void myls_1(char * file_name) // myls로 파일이름 인자로 있을떄
{
	FILE * fp;
	fp = fopen("inode.bin", "wb");

	inode tmp;

	while(1)
	{
		fread(&tmp, sizeof(inode), 1, fp);
		if(strcmp(tmp.filename, file_name))
			break;
	}
	if(tmp.type = 0)
		printf("%s directory %5d []byte\n", tmp.time_, tmp.inode_num);
	
	else if(tmp.type = 1)
		printf("%s file      %5d []byte\n", tmp.time_, tmp.inode_num);
	
	fclose(fp);	
}
*/
int main(void)
{
	char * check_fname = "hi";  //생성할 파일 이름
	mkfirstinode();
	tmp_inode_2();		//2번, 3번 inode생성
	mkinode(4, 1, check_fname); //4번 inode생성

	FILE * fp;
	if ((fp = fopen("inode.bin","rb"))==NULL){
		fprintf(stderr, "파일 열 수 없음");
	}

	inode tmp;

	rewind(fp);


	fread(&tmp, sizeof(inode), 1, fp);
	printf(" root inode 정보 / inode번호 : %d inode type : %d 파일 이름 : %s 생성 시간 : %s\n", tmp.inode_num, tmp.type, tmp.filename, tmp.time_);

	fread(&tmp, sizeof(inode), 1, fp);
	printf(" 2번  inode 정보 / inode번호 : %d inode type : %d 파일 이름 : %s 생성 시간 : %s\n", tmp.inode_num, tmp.type, tmp.filename, tmp.time_);

	fread(&tmp, sizeof(inode), 1, fp);
	printf(" 3번  inode 정보 / inode번호 : %d inode type : %d 파일 이름 : %s 생성 시간 : %s\n", tmp.inode_num, tmp.type, tmp.filename, tmp.time_);

	fread(&tmp, sizeof(inode), 1, fp);
	printf(" 4번  inode 정보 / inode번호 : %d inode type : %d 파일 이름 : %s 생성 시간 : %s\n", tmp.inode_num, tmp.type, tmp.filename, tmp.time_);
	fclose(fp);

	printf("\n");

	int a;
	printf("myinode로 확인할 inode 번호 : ");
	scanf("%d", &a);
	myinode(a);
/*
	printf("\n");

	char *b;
	printf("myls로 확인할 파일 이름 : ");
	scanf("%s", b);
	myls_1(b);
*/

}

