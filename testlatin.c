
#include "latin.h"
/*#include <stdlib.h>
#include <stdio.h>

#define NUM_TYPE unsigned short int

int Isbit(NUM_TYPE *LSVector,int k,int i,int j);*/

int testlatin(NUM_TYPE *M, int row, int col, int n, int stage)
{
	int i,x=0,y=0;
	/*Tests whether a particular element violates the conditions for being
	a latin square*/

	if (Isbit(M,n,row,col)==1) return(0);

	for (i=0;i<=n-1;i++)
	{
		x += Isbit(M,n,row,i); 
		y += Isbit(M,n,i,col);
	}
	if (x>=stage || y>=stage) return(0);
	return(1);
}
