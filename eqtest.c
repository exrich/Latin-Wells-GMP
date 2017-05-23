#include "latin.h"
/*#define NUM_TYPE unsigned short int

int Isbit(NUM_TYPE *LSVector,int k,int i,int j);*/

int Eqtest(NUM_TYPE *Bx,NUM_TYPE *Jx,NUM_TYPE *By,NUM_TYPE *Jy,int n)
{
	int count=0,count1=0,it1=0;
	for (it1=0;it1<=n-1;it1++)
	{
	if (Isbit(Jx,n,0,it1)==1 && Isbit(Jy,n,0,it1)==1){count++;}
	if (Isbit(Bx,n,0,it1)==1 && Isbit(By,n,0,it1)==1){count1++;}
	}
if (count==n && count1==n)
{return(1);}
else return(0);
}