#include "latin.h"
#include "gmp.h"

NUM_TYPE **LSEquivGenerate(NUM_TYPE **M,int n,int rowsM,int stage,mpz_t *count)
{
	NUM_TYPE **N;
	int i,j,*c,x=0,test=0,k,**countMN,it1=0,ns=0;
	N = LatinMatrix(n,n,5000);c = makeIntVector(n);countMN=make_m(5000,5000);mpz_t count2[5000];
	/*Set M[0]=N[0]*/
	mpz_array_init (count2[0],5000,512);
	for (it1=0;it1<=rowsM;it1++)
	{
		for (i=0;i<=n-1;i++)
		{
			for (j=0;j<=n-1;j++)
			{
			if (Isbit(M[it1],n,i,j)==1) setBit(N[it1],n,i,j);
			}
		}
	}
	LSCreate(n,n,M[0],stage);

	for (i=0;i<=rowsM;i++)
	{
		setBit(N[i],n,0,stage-1);
	}

	for (it1=0;it1<=rowsM;it1++)
	{
	for (i=1;i<=n-1;i++) {
		for (c[i]=0;c[i]<=n-1;c[i]++) 
		{
			if (testlatin(N[it1],i,c[i],n,stage)==1)
			{
			setBit(N[it1],n,i,c[i]);
				if (i==n-1)
				{
					for (k=0;k<=ns;k++)
					{
						x = equivalence(n,n,M[k],N[it1]);
						if (x==1) 
						{
						//v_copy(N[it1],M[k],n);
						countMN[it1][k]++;break;
						}
					}
						if (x==0)
						{
						ns++;countMN[it1][ns]++;
						v_copy(N[it1],M[ns],n);
						}
					x=0;
					clearBit(N[it1],n,i,c[i]);
					i--;
					clearBit(N[it1],n,i,c[i]);
					test=1;
				}
			if (test==0) break;
			}
			while (c[i]==n-1)
			{
			i--;
			if (i<=0) break;
			clearBit(N[it1],n,i,c[i]);
			}
			test=0;
			if (i<=0) break;
		}
		if (i<=0) break;
	}
	}
	/*for (i=0;i<=rowsM;i++)
	{
		print_vec(countMN[i],ns);
		printf("\n");
	}*/
	for(j=0;j<=ns;j++)
			{
			for (i=0;i<=rowsM;i++)
			{
			mpz_addmul_ui(count2[j],count[i],countMN[i][j]);
			}
	}

	count=count2;
	rowsM=ns;
	print_vec(count,ns);
	if (stage==n-1) return(M);
	stage++;
	free(c);free(countMN[0]);free(countMN);free(N[0]);free(N);
	LSEquivGenerate(M,n,rowsM,stage,count);
	return(M);
}
