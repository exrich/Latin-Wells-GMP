#include "latin.h"

unsigned long long int combtonum(int *vec,int n)
{
	int mult=1,j,i;
	unsigned long long int r,z=1, serial=0, bico;
	for (j=0;j<=n-1;j++)
	{
		if (vec[j]!=0)
		{
			for (i=vec[j]-1+n-j;i>=n-j+1;i--)
			{
				z*=i;
			}
		r=fact(vec[j]-1);
		bico=(z/r);
		serial += bico;
		}
	}
	return(serial);
}