#include <stdio.h>
#define sinode(N) super.inode##N
#define sdata(N) super.data##N

typedef struct sblock{
	unsigned inode1 : 32, inode2 : 32, inode3 : 32, inode4 : 32;
	unsigned data1 : 32, data2 : 32, data3 : 32, data4 : 32, data5 : 32, data6 : 32, data7 : 32, data8 : 32;
}sblock;

static sblock super;

int set_sblock (_Bool kind, int num){ //0이면 데이터, 1이면 inode
	unsigned int mask = 1;
	int di32 = num/32;
	int di32_rest = num%32;
	if (kind){ // inode면 실행
		if (sinode(di32) & mask<<di32_rest)
			return -1;//자리가 이미 채워져 있음
		else {
			sinode(di32) |= mask<<di32_rest;
			return 0;
		}
	}
	else{
		if (sdata(di32) & mask<<di32_rest)
		   return -1;
		else{
			sdata(di32) |= mask<<di32_rest;
			return 0;
		}
	}
}

int main(){
	int num, kind, s;
	printf("inode = %d, datablock = %d", super.inode1, super.data1);
	scanf ("%d %d", &num, &kind);
	s = set_sblock(kind, num);
	if (s == -1)
		printf("error");
	else
		printf("inode = %d, datablock = %d", super.inode1, super.data1);	
}
