#include "latin.h"
/*#include <stdlib.h>

#define NUM_TYPE unsigned short int

void setBit(NUM_TYPE *LSVector,int n,int i,int j);
int Isbit(NUM_TYPE *LSVector,int n,int i,int j);
void clearBit(NUM_TYPE *LSVector,int n,int i,int j);
int *makeIntVector(int N);*/

int eleback(int **S, int **P, int *lev,NUM_TYPE *LSVector2,NUM_TYPE *Er,NUM_TYPE *By,int Scount,int n,int **pointP)
{
int *altarray,it2=0,it3,count1=Scount,count2=-1,count3=0,i=0,test=0,test2=0,j=0;

altarray=makeIntVector(Scount+1);for(i=0;i<=Scount;i++){altarray[i]=-1;}

if ((lev[0] % 2)==0)
{
//printLMatrix(By,1,n);
for (count1=Scount;count1>=0;count1--)
{
		for (it3=P[lev[0]][count1]+1;it3<=n-1;it3++)
		{
			if ((Isbit(LSVector2,n,it3,pointP[lev[0]][count1])==1 && Isbit(By,n,0,it3)==0) && Isbit(Er,n,S[lev[0]][count1],it3)==1)
			{
			altarray[count1]=it3;count2=count1;test=1;
			break;
			}
		}
		if (test==0) {if (count1>0){clearBit(By,n,0,P[lev[0]][count1-1]);}}
		else {break;}
}
if (count1==-1) {for (i=0;i<=Scount;i++) {pointP[lev[0]][i]=-1;}free(altarray);return(0);}

P[lev[0]][count2]=altarray[count2];setBit(By,n,0,P[lev[0]][count2]);

for (i=count2+1;i<=Scount;i++)
		{
			for (it3=0;it3<=n-1;it3++)
				{
					if ((Isbit(LSVector2,n,it3,pointP[lev[0]][i])==1 && Isbit(By,n,0,it3)==0) && Isbit(Er,n,S[lev[0]][i],it3)==1)
					{
					setBit(By,n,0,it3);P[lev[0]][i]=it3;count3++;test2=1;
					break;
					}
				}
		}
free(altarray);/*printLMatrix(By,1,n);*/return(1);
}


if ((lev[0] % 2)==1)
{
//printLMatrix(By,1,n);
for (count1=Scount;count1>=0;count1--)
{
		for (it3=P[lev[0]][count1]+1;it3<=n-1;it3++)
		{
			if ((Isbit(LSVector2,n,pointP[lev[0]][count1],it3)==1 && Isbit(By,n,0,it3)==0) && Isbit(Er,n,S[lev[0]][count1],it3)==1)
			{
			altarray[count1]=it3;count2=count1;test=1;
			break;
			}
		}
		if (test==0) {if (count1>0){clearBit(By,n,0,P[lev[0]][count1-1]);}}
		else {break;}
}

if (count1==-1) {for (i=0;i<=Scount;i++) {pointP[lev[0]][i]=-1;}free(altarray);return(0);}

P[lev[0]][count2]=altarray[count2];setBit(By,n,0,P[lev[0]][count2]);

for (i=count2+1;i<=Scount;i++)
		{
		for (it3=0;it3<=n-1;it3++)
				{
					if ((Isbit(LSVector2,n,pointP[lev[0]][i],it3)==1 && Isbit(By,n,0,it3)==0) && Isbit(Er,n,S[lev[0]][i],it3)==1)
					{
					setBit(By,n,0,it3);P[lev[0]][i]=it3;count3++;test2=1;
					break;
					}
				}
		}
free(altarray);/*printLMatrix(By,1,n);*/return(1);
}
	return(1);
}