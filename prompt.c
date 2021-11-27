#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "struct.h"

pwd_list * path_list;
pwd_list * b_path;

void print_prompt (){ // 프롬프트 출력
	pwd_list * pre_path = path_list -> next;
	printf("[/");
	while (1) {
		if (pre_path == NULL)
			break;
		printf("%s", pre_path ->name);
		pre_path = pre_path -> next;
		if (pre_path != NULL)
			printf("/");
	}
	printf(" ]$ ");
}

void set_root_path (){ // 루트디렉토리 지정
	path_list = malloc(sizeof(pwd_list));
	path_list -> name = malloc(sizeof(char)*2);
	strcpy(path_list -> name, "/");
	b_path = path_list;
}

void set_next_path (char * name){ // 다음 디렉토리 지정
	pwd_list * n_path;
	n_path = malloc(sizeof(pwd_list));
	n_path -> name = malloc (sizeof(char)*7);
	strcpy(n_path -> name, name);
	b_path -> next = n_path;
	b_path = n_path;
}

int main (){
	char name[7];
	set_root_path();
	print_prompt();
	for (int i = 0; i<3; i++){
		scanf("%s", &name);
		set_next_path (name);
		print_prompt();
	}
}