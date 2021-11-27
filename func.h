#include <stdbool.h>
#ifndef STRUCT_H
#include "struct.h"
#define STRUCT_H
#endif

int make_fs ();
void print_shell();
char * scan_comm();
void op_comm(char *);
int make_inode (inode *, _Bool, int, int);
void set_sblock (_Bool, int);
// stack 구현 함수
void s_reset();
void s_push(char c);
char s_pop();
char s_top();
bool s_empty();
bool s_full();
//queue 구현 함수