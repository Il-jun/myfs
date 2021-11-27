#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inode.h"

int makeinode (inode * i, int num, int use){//만들고자 하는 inode, 종류, 저장될 데이터블록 시작점, 몇개 사용할 것인지
	i -> p = calloc(use, sizeof(int)); //사용되는 데이터블럭 동적 할당
	i->t = time(NULL);//현재시간
	for (int j = 0; j<use; j++){
		i->p[j] = (num+1+j);//data블록에 순차적으로 저장
	}
	return (num+use+1);//다음 저장될 곳 리턴
}

int find_empty_inode (){

