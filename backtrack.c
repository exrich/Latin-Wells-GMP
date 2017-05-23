#include "latin.h"
/*#include <stdlib.h>

#define NUM_TYPE unsigned short int

void setBit(NUM_TYPE *LSVector,int n,int i,int j);
int Isbit(NUM_TYPE *LSVector,int n,int i,int j);
void clearBit(NUM_TYPE *LSVector,int n,int i,int j);
int *makeIntVector(int N);
void print_vec(int *M, int size);
long long int fact(int j);*/

int backtrackfunc(NUM_TYPE *Ec,NUM_TYPE *tempcolsx,NUM_TYPE *tempcolsy,NUM_TYPE *Jx,NUM_TYPE *Jy,NUM_TYPE *S,NUM_TYPE *P,int *lev,int n,int *backtrack,int count1)
{ 
int it2,it3,count3=0,count2=0,back=0,count4,*matchvec;

if (backtrack[lev[0]]==fact(count1)) return(0);

matchvec=makeIntVector(count1);

count4=0;

for (it2=0;it2<=n-1;it2++)
{
if (Isbit(tempcolsx,n,0,it2)==1) 
	{
	for (it3=0;it3<=n-1;it3++) 
	{
	if (Isbit(tempcolsy,n,0,it3)==1) 
		{
			if (Isbit(Ec,n,it2,it3)==1)
			{
				matchvec[count4]++;
			}
	}
	}
count4++;
}
}
//print_vec(matchvec,count1);
for (it2=0;it2<=n-1;it2++)
{
	if (Isbit(tempcolsx,n,0,it2)==1) 
	{
	back = (backtrack[lev[0]] % (count1-count3));
	for (it3=0;it3<=n-1;it3++) 
	{
		if (Isbit(tempcolsy,n,0,it3)==1) 
		{
			if (Isbit(Ec,n,it2,it3)==1) 
			{
			if (back > 0)
			{	
			back--;
			}
			else
			{
			clearBit(tempcolsx,n,0,it2);clearBit(tempcolsy,n,0,it3);
			setBit(Jy,n,0,it3);setBit(P,n,lev[0],it3);
			setBit(Jx,n,0,it2);setBit(S,n,lev[0],it2);
			count2++;count3++;
			break;
			}
			}
		}
	}
}
}
free(matchvec);
return(count2);
}

