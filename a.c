#include "header.h"
#include "func.h"

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
	root.filename = malloc (sizeof(char) * 8); // root 이름 저장을 위한 메모리 할당
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
	

void myls_0(int num) //myls 인자 없을떄, 인자 디렉터리 내의 파일 수
{

}

void myls_1(char * file_name) // myls로 파일이름 인자로 있을떄
{
	FILE * fp;
	fp = fopen("inode.bin", "rb");

	inode tmp;

	rewind(fp);

	while(1)
	{
		fread(&tmp, sizeof(inode), 1, fp);
		if(!strcmp(tmp.filename, file_name))
			break;
	}
	
	if(tmp.type == 0)
		printf("%s directory %5d %dbyte\n", tmp.time_, tmp.inode_num, get_size(file_name));
	
	else if(tmp.type = 1)
		printf("%s file      %5d %dbyte\n", tmp.time_, tmp.inode_num, get_size(file_name));
	
	fclose(fp);	
}

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

	printf("\n");

	char *b = malloc(sizeof(char)*8);
	printf("myls로 확인할 파일 이름 : ");
	scanf("%s", b);
	myls_1(b);

//	printf("myls인자 없을떄\n");
//	myls_0(3);

}

