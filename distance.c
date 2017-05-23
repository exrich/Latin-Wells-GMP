#include "latin.h"
/*#include <stdlib.h>

#define NUM_TYPE unsigned short int

int **make_m(int row, int col);
void setBit(NUM_TYPE *LSVector,int k,int i,int j);
int Isbit(NUM_TYPE *LSVector,int k,int i,int j);
void clearBit(NUM_TYPE *LSVector,int k,int i,int j);*/

int distance(NUM_TYPE LSVector1, NUM_TYPE LSVector2,int n)
{
int **distMatr1,**distMatc1,**distMatr2,**distMatc2,i,j,k;

distMatr1 = make_m(n,n);distMatr2 = make_m(n,n);distMatc1 = make_m(n,n);distMatc2 = make_m(n,n);

for (i=0;i<=n-1;i++)
{
	for (j=0;j<=n-1;j++)
	{
		if (Isbit(LSVector1,n,i,j)==1)
		{
			distMatr1[i][0]++;
		}
	}
}

return(0);


}