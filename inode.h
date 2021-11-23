#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct inode{
	_Bool kind;//디럭터리인지 파일인지 구분
	time_t t;//만들어진 시간을 확인
	int  * p;//사용되는 데이터 블록 확인
}inode; // inode를 위한 구조체 선언
