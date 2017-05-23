#include <stdio.h>
#include <stdlib.h>
#include "latin.h"

/*#define NUM_TYPE unsigned short int
#define BITS_PER_NUM 16

		
int shell_sort(int *A,int size);
int Isbit(NUM_TYPE *LSVector,int k,int i,int j);
int **make_m(int row, int col);
int *makeIntVector(int N);
int combtonum(int *vec,int n);*/

int *row_wt(NUM_TYPE *LSVector,int n,int k)
{
	int **Pmatrix,s,t,u,i,mask=1,*Wvec;
	Pmatrix = make_m(n,n);
	Wvec = makeIntVector(n);
	for (s=0;s<=n-1;s++)
	{
		for (t=0;t<=n-1;t++)
		{
			for (u=0;u<=n-1;u++)
			{
				Pmatrix[s][t] += Isbit(LSVector,n,s,u) & Isbit(LSVector,n,t,u);
			}
		}
	}
	//print_m(Pmatrix,n,k);
	for (i=0;i<=n-1;i++)
	{
	shell_sort(Pmatrix[i],n);
	}
	//print_m(Pmatrix,n,k);
	for (i=0;i<=n-1;i++)
	{
	Wvec[i]=combtonum(Pmatrix[i],n);
	}
	free(Pmatrix[0]);free(Pmatrix);
	return(Wvec);
}


