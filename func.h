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
