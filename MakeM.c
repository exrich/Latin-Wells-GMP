#include <stdio.h>
#include <stdlib.h>

int **make_m(int row, int col)
{
	int **M; 
	int n,i,j; 
	int zero=0;

M = (int **)malloc((row+1)*sizeof(int *));/*Creates the pointer-to pointer*/
M[0]=(int *)malloc((row*col+1)*sizeof(int));/*Creates a pointer*/
for (n=1;n<=row-1;n++) M[n]=M[n-1]+col;/*Creates an array of pointers, array indices start from 1 and go to n*/
if( M == NULL)
		{	printf( "Insufficient memory available\n" );
			return(0);
		}
else
{
	for (i=0;i<=row-1;i++)
	{
		for (j=0;j<=col-1;j++)
		{M[i][j] = 0;}/*Sets the matrix values equal to 0*/
	}
	return(M);}
}