#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#ifndef STRUCT_H
#define STRUCT_H
typedef struct inode{
		_Bool kind;//디럭터리인지 파일인지 구분
			time_t t;//만들어진 시간을 확인
				int  * p;//사용되는 데이터 블록 확인
}inode; // inode를 위한 구조체 선언

typedef struct sblock{
		unsigned inode1 : 32, inode2 : 32, inode3 : 32, inode4 : 32;
			unsigned data1 : 32, data2 : 32, data3 : 32, data4 : 32, data5 : 32, data6 : 32, data7 : 32, data8 : 32;
}sblock;
#endif
