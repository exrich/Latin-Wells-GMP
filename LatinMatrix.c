#include <stdio.h>
#include <stdlib.h>
#include "latin.h"
/*#define NUM_TYPE unsigned short int*/

NUM_TYPE **LatinMatrix(int n, int k,int r)
{
	NUM_TYPE **M; 
	int i,j,bits_req = n*k,array_size;

	array_size = (bits_req >> 4)+1;

	M = (NUM_TYPE **)malloc((r+1)*sizeof(NUM_TYPE *));/*Creates the pointer-to pointer*/
	M[0]=(NUM_TYPE *)malloc((r*array_size+1)*sizeof(NUM_TYPE));/*Creates a pointer*/
	for (i=1;i<=r;i++) M[i]=M[i-1]+array_size;/*Creates an array of pointers, array indices start from 0 and go to n-1*/
	if( M == NULL)
		{	printf( "Insufficient memory available\n" );
			return(0);
		}
else
{
	for (i=0;i<=r-1;i++)
	{
		for (j=0;j<=array_size;j++)
		{M[i][j] = 0;}/*Sets the matrix values equal to 0*/
	}
	return(M);}
}