#ifndef STRUCT_H
#include "struct.h"
#define STRUCT_H
#endif

int Make_fs ();
void print_shell();
char * scan_comm();
void op_comm(char *);
int make_inode (inode *, _Bool, int, int);
int set_sblock (_Bool, int);
