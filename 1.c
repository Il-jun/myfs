#include<stdio.h>

int file_byte(FILE *fp)
{
	int size;

	fseek(fp, 0, SEEK_END);

	size = ftell(fp);

	fclose(fp);

	return size;
}
