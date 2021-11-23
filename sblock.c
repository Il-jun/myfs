#include <stdio.h>
#include "func.h"
#include "struct.h"

static sblock super;

int set_sblock (_Bool kind, int num){ //0이면 데이터, 1이면 inode
	unsigned int mask = 1;
	int di32 = num/32;
	int di32_rest = (num%32)-1;
	
	if (kind){ // inode면 실행
		if (di32 == 0){
			if (super.inode1 & mask<<di32_rest)
				return -1;//자리가 이미 채워져 있음
			else {
				super.inode1 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 1){
			if (super.inode2 & mask<<di32_rest)
				return -1;//자리가 이미 채워져 있음
			else {
				super.inode2 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 2){
			if (super.inode3 & mask<<di32_rest)
				return -1;//자리가 이미 채워져 있음
			else {
				super.inode3 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 3){
			if (super.inode4 & mask<<di32_rest)
				return -1;//자리가 이미 채워져 있음
			else {
				super.inode4 |= mask<<di32_rest;
				return 0;
			}
		}
	}
	else{
		if (di32 == 0) {
			if (super.data1 & mask<<di32_rest)
		   		return -1;
			else{
				super.data1 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 1) {
			if (super.data2 & mask<<di32_rest)
		   		return -1;
			else{
				super.data2 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 2) {
			if (super.data3 & mask<<di32_rest)
		   		return -1;
			else{
				super.data3 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 3) {
			if (super.data4 & mask<<di32_rest)
		   		return -1;
			else{
				super.data4 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 4) {
			if (super.data5 & mask<<di32_rest)
		   		return -1;
			else{
				super.data5 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 5) {
			if (super.data6 & mask<<di32_rest)
		   		return -1;
			else{
				super.data6 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 6) {
			if (super.data7 & mask<<di32_rest)
		   		return -1;
			else{
				super.data7 |= mask<<di32_rest;
				return 0;
			}
		}
		if (di32 == 7) {
			if (super.data8 & mask<<di32_rest)
		   		return -1;
			else{
				super.data8 |= mask<<di32_rest;
				return 0;
			}
		}
	}
}

int main(){
	int num, kind, s;
	printf("inode = %d, datablock = %d\n", super.inode1, super.data1);
	scanf ("%d %d", &num, &kind);
	s = set_sblock(kind, num);
	if (s == -1)
		printf("error");
	else
		printf("inode = %d, datablock = %d", super.inode1, super.data1);	
}
