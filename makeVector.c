#include <stdio.h>
#include <stdlib.h>

unsigned short int *makeVector(int N)

{
	unsigned short int *v;
	v = (unsigned short int *)malloc(sizeof(unsigned short int)*(N+1));
	return(v);
}