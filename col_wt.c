#include "latin.h"
/*#include <stdlib.h>

#define NUM_TYPE unsigned short int
		
int shell_sort(int *A,int size);
int Isbit(NUM_TYPE *LSVector,int k,int i,int j);
int **make_m(int row, int col);
int *makeIntVector(int N);
int combtonum(int *vec,int n);*/

int *col_wt(NUM_TYPE *LSVector,int n,int k)
{
	int **Pmatrix,*Wvec,s,t,u,i;
	Pmatrix = make_m(n,n);
	Wvec = makeIntVector(n);
	for (s=0;s<=n-1;s++)
	{
		for (t=0;t<=n-1;t++)
		{
			for (u=0;u<=n-1;u++)
			{
				Pmatrix[s][t] += Isbit(LSVector,n,u,s) & Isbit(LSVector,n,u,t);
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