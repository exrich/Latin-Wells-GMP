#include "latin.h"
/*#include <stdio.h>
#include <stdlib.h>

#define NUM_TYPE unsigned short int
#define BITS_PER_NUM 16
void setBit(NUM_TYPE *LSVector,int n,int i,int j);
int Isbit(NUM_TYPE *LSVector,int n,int i,int j);
void clearBit(NUM_TYPE *LSVector,int n,int i,int j);
NUM_TYPE *LatinMemAllo(int n,int k);
void printLMatrix(NUM_TYPE *M,int k,int n);
void print_m(int **M, int row, int col);*/

int permMatrixTest(NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,int **rowPermute,int **colPermute,int n)
{
NUM_TYPE *newMatrix,*newMatrix2;
int i,j,array_size,test=0;
newMatrix = LatinMemAllo(n,n);newMatrix2 = LatinMemAllo(n,n);
for (i=0;i<=n-1;i++)
{
	for (j=0;j<=n-1;j++)
	{
	if (Isbit(LSVector1,n,rowPermute[0][i],j)==1)
	{
	setBit(newMatrix,n,rowPermute[1][i],j);
	}
	}
}
for (i=0;i<=n-1;i++)
{
	for (j=0;j<=n-1;j++)
	{
	if (Isbit(newMatrix,n,j,colPermute[0][i])==1)
	{
	setBit(newMatrix2,n,j,colPermute[1][i]);
	}
	}
}
free(newMatrix);
array_size = ((n*n) >> 4)+1;
for (i=0;i<=n-1;i++)
{
	for (j=0;j<=n-1;j++)
	{
	if (Isbit(newMatrix2,n,i,j)!=Isbit(LSVector2,n,i,j))
	{
		test=1;break;
	}
	}
}
if (test==1) 
{
free(newMatrix2);
//printf("No ");
//printLMatrix(LSVector1,n,n);printLMatrix(LSVector2,n,n);
//print_m(rowPermute,2,n);print_m(colPermute,2,n);
return(0);
}
free(newMatrix2);
//else {printf("Yes ");}
return(1);
}










