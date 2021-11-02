#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct inode{
	_Bool kind;//디럭터리인지 파일인지 구분
	time_t t;//만들어진 시간을 확인
	int  p[8];//사용되는 데이터 블록 확인
	short n;//어디까지 사용했는지 확인
}inode; // inode를 위한 구조체 선언

int makeinode (inode * i, _Bool k, int num, int use){//만들고자 하는 inode, 종류, 저장될 데이터블록 시작점, 몇개 사용할 것인지
	i -> kind = (k ? true : false); //종류 저장
	i->t = time(NULL);//현재시간
	for (int j = 0; j<use; j++){
		i->p[j] = (num+1+j);//data블록에 순차적으로 저장
	}
	i->n = use;
	return (num+use+1);//다음 저장될 곳 리턴
}

int main(){
	int start = 0;
	int next;
	inode i1;
	next = makeinode(&i1, false, start, 4);
	printf ("kind : %s\ntime : %ld\ndata : 1-%d 2-%d 3-%d\nn : %d\nnext : %d\n", i1.kind ? "true" : "false", i1.t, i1.p[0], i1.p[1], i1.p[2], i1.n, next);
}
