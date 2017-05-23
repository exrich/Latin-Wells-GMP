#include <stdio.h>

void print_m(int **M, int row, int col)
{
	/*Prints the matrix to the screen*/
	int i,j;
	printf("\n%d by %d Matrix :\n",row,col);
	for (i=0;i<=row-1;i++)
	{printf("\n");
	for (j=0;j<=col-1;j++)printf("%d ",M[i][j]);}
	printf("\n\n");}
