#include<stdio.h>

#define dist(x) ((x >> 2) <<1)+1

int shell_sort_long(unsigned long long int *A, int size)
{
	unsigned long long int swap;
	int d = size, i, j, k;
	do {
		d = dist(d);
		for (i = 1; i <= d; i++)
		{
			for (j = i; j + d <= size; j++)
			{
				for (k = j; k >= i; k--)
				{
					while (A[k - 1]>A[k + d - 1])
					{
						swap = A[k - 1];
						A[k - 1] = A[k + d - 1];
						A[k + d - 1] = swap;
					}
				}
			}
		}
	} while (d>1);
	if (d == 1) return(1); else return(0);
}