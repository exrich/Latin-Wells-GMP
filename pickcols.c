#include "latin.h"
/*#define NUM_TYPE unsigned short int

void setBit(NUM_TYPE *LSVector,int n,int i,int j);
int Isbit(NUM_TYPE *LSVector,int n,int i,int j);*/

int pickcols(NUM_TYPE *tempcolsx,NUM_TYPE *tempcolsy,NUM_TYPE *S,NUM_TYPE *P,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,NUM_TYPE *Jx,NUM_TYPE *Jy,int *lev,int n)
{
int t,it1,count1=0;
for (t=0;t<=n-1;t++){/*Picks the x rows to look at*/
	if (Isbit(S,n,lev[0]-1,t)==1){
		for(it1=0;it1<=n-1;it1++){/*Decides whether x columns in rows contain 1's*/
			if (lev[0] % 2 ==1)
			{
			if (Isbit(LSVector1,n,t,it1)==1 && Isbit(tempcolsx,n,0,it1)==0 && Isbit(Jx,n,0,it1)==0)
				{
				setBit(tempcolsx,n,0,it1);
				count1++;
				}
			}
			else
			{
				if (Isbit(LSVector1,n,it1,t)==1 && Isbit(tempcolsx,n,0,it1)==0 && Isbit(Jx,n,0,it1)==0)
				{
				setBit(tempcolsx,n,0,it1);
				count1++;
				}
			}
		}
	}
}

/*No need to change*/
for (t=0;t<=n-1;t++){/*Finds the Y row index*/
	if (Isbit(P,n,lev[0]-1,t)==1){
		for (it1=0;it1<=n-1;it1++){/*Finds the y cols to look at*/
			if (lev[0] % 2 ==1)
			{
			if (Isbit(LSVector2,n,t,it1)==1 && Isbit(tempcolsy,n,0,it1)==0 && Isbit(Jy,n,0,it1)==0)
			{
				setBit(tempcolsy,n,0,it1);
			}
			}
			else
			{
			if (Isbit(LSVector2,n,it1,t)==1 && Isbit(tempcolsy,n,0,it1)==0 && Isbit(Jy,n,0,it1)==0)
			{
				setBit(tempcolsy,n,0,it1);

			}
			}
		}
	}
}
return(count1);
}
