#include "latin.h"

int invar(int n,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,NUM_TYPE *Er,NUM_TYPE *Ec)
{
	int i, j, k;
	unsigned long long int *rwt1, *rwt2, *cwt1, *cwt2, valrwt1, valrwt2, valcwt1, valcwt2, asym1 = 0, asym2 = 0;

	rwt1 = row_wt(LSVector1,n,n);rwt2 = row_wt(LSVector2,n,n);
	cwt1 = col_wt(LSVector1,n,n);cwt2 = col_wt(LSVector2,n,n);

	for (i=0;i<=n-1;i++)
	{
		for (j=0;j<=n-1;j++)
		{
			if (rwt1[i]==rwt2[j]) 
			{
				for (k=0;k<=n-1;k++)
				{
				if(Isbit(LSVector1,n,i,k)==1){asym1 += cwt1[k];}
				if(Isbit(LSVector2,n,j,k)==1){asym2 += cwt2[k];}
				}
				if (asym1==asym2) {setBit(Er,n,i,j);}
				asym1=0;asym2=0;
			}
		}
	}
	for (i=0;i<=n-1;i++)
	{
		for (j=0;j<=n-1;j++)
		{
			if (cwt1[i]==cwt2[j])
			{
			for (k=0;k<=n-1;k++)
				{
				if(Isbit(LSVector1,n,k,i)==1){asym1 += rwt1[k];}
				if(Isbit(LSVector2,n,k,j)==1){asym2 += rwt2[k];}
				}
				if (asym1==asym2) {setBit(Ec,n,i,j);}
				asym1=0;asym2=0;
			}
		}
	}

	shell_sort_long(rwt1,n);shell_sort_long(rwt2,n);shell_sort_long(cwt1,n);shell_sort_long(cwt2,n);

	valrwt1 = sig(rwt1,n);valrwt2 = sig(rwt2,n);valcwt1 = sig(cwt1,n);valcwt2 = sig(cwt2,n);

	//printf("%d %d \n",valrwt1,valrwt2);
	//printf("%d %d \n",valcwt1,valcwt2);

	if ((valrwt1 != valrwt2) || (valcwt1 != valcwt2)) 
	{free(rwt1);free(rwt2);free(cwt1);free(cwt2);return(0);}
	else {free(rwt1);free(rwt2);free(cwt1);free(cwt2);return(1);}
}