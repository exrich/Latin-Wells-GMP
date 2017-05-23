#include "latin.h"
/*#include <stdlib.h>

#define NUM_TYPE unsigned short int

void setBit(NUM_TYPE *LSVector,int k,int i,int j);
void clearBit(NUM_TYPE *LSVector,int k,int i,int j);
int *makeIntVector(int N);
int testlatin(NUM_TYPE *M, int row, int col, int n, int stage);*/

void LSCreate(int n, int k,NUM_TYPE *M,int stage)

{
	int i,*c;
	c = makeIntVector(n);
	setBit(M,n,0,stage-1);
	for (i=1;i<=n-1;i++) {
		for (c[i]=0;c[i]<=n-1;c[i]++) 
		{
			if (testlatin(M,i,c[i],n,stage)==1)
			{
			setBit(M,n,i,c[i]);
			break;
			}
			if (testlatin(M,i,c[i],n,stage)==0 && c[i]==n-1)
			{
			while (c[i]==n-1)
			{
			i--;
			clearBit(M,n,i,c[i]);
			}
			}
		}
	}
	free(c);
}