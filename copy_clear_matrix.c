#include "latin.h"
/*#include <stdio.h>

#define NUM_TYPE unsigned short int

void setBit(NUM_TYPE *LSVector,int k,int i,int j);
int Isbit(NUM_TYPE *LSVector,int k,int i,int j);
void clearBit(NUM_TYPE *LSVector,int k,int i,int j);*/

void v_copy(NUM_TYPE *N,NUM_TYPE *M,int n)
{
	int i,j;
	for (i=0;i<=n-1;i++)
		{
			for (j=0;j<=n-1;j++)
			{
				clearBit(M,n,i,j);
				if (Isbit(N,n,i,j)==1)
				{
					setBit(M,n,i,j);
				}
			}
		}
}
