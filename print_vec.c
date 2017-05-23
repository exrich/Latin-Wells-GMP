#include <stdio.h>
#include "gmp.h"

void print_vec(mpz_t *M, int size)
{
	/*Prints the matrix to the screen*/
	int i;
	printf("\nSize %d vec :\n",size+1);
	for (i=0;i<=size;i++)
	{gmp_printf("%Zd ",M[i]);}
	printf("\n\n");
}