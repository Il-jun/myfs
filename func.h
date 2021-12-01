#include <stdbool.h>
#ifndef STRUCT_H
#include "struct.h"
#define STRUCT_H
#endif

void make_fs ();
void print_shell();
void op_comm(char *);
int make_inode (inode *, _Bool, int, int);
void set_sblock (_Bool, int);

void print_prompt ();
void print_pwd ();
void set_root_path ();
void set_next_path (char *);
void cd_path (char *);

void cmp_comm (char *, char *, char *);
void scan_comm (char **, char **, char **);

void show_ls ();

// stack 구현 함수
void s_reset();
void s_push(char c);
char s_pop();
char s_top();
bool s_empty();
bool s_full();
//queue 구현 함수