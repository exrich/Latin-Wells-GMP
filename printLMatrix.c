#include <stdio.h>
#include "latin.h"

/*#define NUM_TYPE unsigned short int*/

int Isbit(NUM_TYPE *LSVector,int k,int i,int j);

void printLMatrix(NUM_TYPE *M,int k,int n)
{
	int x,i,j;
	printf("\n");
	for (i=0;i<=k-1;i++)
	{
		for (j=0;j<=n-1;j++)
		{
		x=Isbit(M,n,i,j);
		printf("%d ",x);
		}
		printf("\n");
	}
	printf("\n");
}