
#include "latin.h"

int associate(int **S,int *lev,NUM_TYPE *Er,NUM_TYPE *Ec,NUM_TYPE *Jx,NUM_TYPE *Jy,NUM_TYPE *Bx,NUM_TYPE *By,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,int **P,int n,int **pointP,int **rowPermute,int **colPermute,int *rcount,int *ccount)
{

int i,it1,it2,it3,count1,count2,count3,test1=0,count5=0,count6=0,count7=0,z,prevrcount=0,prevccount=0;
NUM_TYPE *tempcolsx,*tempcolsy,*x,*y,*E;
tempcolsx = LatinMemAllo(1,n);tempcolsy = LatinMemAllo(1,n);

count1=0;count2=0;count3=0;
//If all rows are filled return equivalent
while (S[lev[0]-1][count1]!=-1){count1++;}
//if (Eqtest(Bx,Jx,By,Jy,n)==1) return(1);

if (lev[0] % 2 ==1)
{
for (it2=0;it2<=count1-1;it2++)
	{
	for (it1=0;it1<=n-1;it1++)
				{
					if (Isbit(LSVector2,n,P[lev[0]-1][it2],it1)==1 && Isbit(Jy,n,0,it1)==0 && Isbit(tempcolsy,n,0,it1)==0)
					{
						setBit(tempcolsy,n,0,it1);
						count6++;
					}
				}
	for (it3=0;it3<=n-1;it3++)
				{
					if (Isbit(LSVector1,n,S[lev[0]-1][it2],it3)==1 && Isbit(Jx,n,0,it3)==0 && Isbit(tempcolsx,n,0,it3)==0)
					{
						setBit(tempcolsx,n,0,it3);
						count7++;
					}
				}
	if (count6!=count7) break;
}

if (count6==count7 && count6!=0)
{
	for (it2=0;it2<=count1-1;it2++)
	{
		for(it1=0;it1<=n-1;it1++){/*Decides whether x columns in rows contain 1's*/
			if (Isbit(LSVector1,n,S[lev[0]-1][it2],it1)==1 && Isbit(Jx,n,0,it1)==0)
			{
				count3++;
				for (it3=0;it3<=n-1;it3++)
				{
					if ((Isbit(LSVector2,n,P[lev[0]-1][it2],it3)==1 && Isbit(Jy,n,0,it3)==0)  && Isbit(Ec,n,it1,it3)==1)
					{
						setBit(Jx,n,0,it1);setBit(Jy,n,0,it3);
						S[lev[0]][count2]=it1;P[lev[0]][count2]=it3;pointP[lev[0]][count2]=P[lev[0]-1][it2];
						count2++;break;
					}
				}
				if (count3!=count2) break;
			}
		}
	if (count3!=count2) break;
	}
}
}

else
{
for (it2=0;it2<=count1-1;it2++)
	{
	for (it3=0;it3<=n-1;it3++)
				{
					if (Isbit(LSVector2,n,it3,P[lev[0]-1][it2])==1 && Isbit(Jy,n,0,it3)==0 && Isbit(tempcolsy,n,0,it3)==0)
					{
						setBit(tempcolsy,n,0,it3);
						count6++;
					}
				}
	for (it1=0;it1<=n-1;it1++)
				{
					if ((Isbit(LSVector1,n,it1,S[lev[0]-1][it2])==1 && Isbit(Jx,n,0,it1)==0) && Isbit(tempcolsx,n,0,it1)==0)
					{
						setBit(tempcolsx,n,0,it1);
						count7++;
					}
				}
	if (count6!=count7) {break;}
}

if (count6==count7 && count6!=0)
{
	for (it2=0;it2<=count1-1;it2++)
	{
		for(it1=0;it1<=n-1;it1++){/*Decides whether x columns in rows contain 1's*/
			if (Isbit(LSVector1,n,it1,S[lev[0]-1][it2])==1 && Isbit(Jx,n,0,it1)==0)
			{
				count3++;
				for (it3=0;it3<=n-1;it3++)
				{
					if ((Isbit(LSVector2,n,it3,P[lev[0]-1][it2])==1 && Isbit(Jy,n,0,it3)==0) && Isbit(Ec,n,it1,it3)==1)
					{
					setBit(Jx,n,0,it1);setBit(Jy,n,0,it3);
					S[lev[0]][count2]=it1;P[lev[0]][count2]=it3;pointP[lev[0]][count2]=P[lev[0]-1][it2];
					count2++;break;
					}
				}
				if (count3!=count2) break;
			}
		}
		if (count3!=count2) break;
	}
}
}

if ((count3==0 && count6==0) && count7==0)
{	
	return(-2);
}


/*May need to change*/
//If two counts are unequal backtrack to previous stage
if (count3!=count2 || count6!=count7)
{		
		for(it1=0;it1<=count2-1;it1++)
			{
			clearBit(Jx,n,0,S[lev[0]][it1]);clearBit(Jy,n,0,P[lev[0]][it1]);
			S[lev[0]][it1]=-1;P[lev[0]][it1]=-1;pointP[lev[0]][it1]=-1;
			}
		lev[0]--;
		it1=0;it2=0;
		if (lev[0]!=0)
		{
		while (S[lev[0]][it1]!=-1){it1++;}
		clearBit(By,n,0,P[lev[0]][it1-1]);
		//printLMatrix(LSVector1,n,n);
		//printLMatrix(LSVector2,n,n);
		z = eleback(S,P,lev,LSVector2,Er,By,it1-1,n,pointP);
		if (z==1) {lev[0]++;free(tempcolsx);free(tempcolsy);return(0);}
		x=Bx;y=By;
		while (z==0) 
		{
		it1=0;
		while(S[lev[0]][it1]!=-1)
			{
			clearBit(x,n,0,S[lev[0]][it1]);clearBit(y,n,0,P[lev[0]][it1]);
			S[lev[0]][it1]=-1;P[lev[0]][it1]=-1;pointP[lev[0]][it1]=-1;
			it1++;
			}
		lev[0]--;it1=0;
		if (x==Bx) {y=Jy;x=Jx;E=Ec;}
		else {y=By;x=Bx;E=Er;}
		if (lev[0]==0) {clearBit(y,n,0,P[0][0]);P[0][0]=-1;free(tempcolsx);free(tempcolsy);return(-3);}
		while(S[lev[0]][it1]!=-1){it1++;}
		clearBit(y,n,0,P[lev[0]][it1-1]);
		z = eleback(S,P,lev,LSVector2,E,y,it1-1,n,pointP);
		}
		lev[0]++;free(tempcolsx);free(tempcolsy);return(0);
		}
		else
		{
		clearBit(By,n,0,P[0][0]);P[0][0]=-1;
		free(tempcolsx);free(tempcolsy);
		return(-3);
		}
}
//Move to next stage of interation
while (Eqtest(Bx,Jx,By,Jy,n)==1) 
{
prevrcount=rcount[0];prevccount=ccount[0];
findperm(S,P,rowPermute,colPermute,rcount,ccount,lev[0]+1);
ccount[0]=prevccount;rcount[0]=prevrcount;
z = permMatrixTest(LSVector1,LSVector2,rowPermute,colPermute,n);
if (z==1) {return(1);}
x=Jx;y=Jy;
while (z==0)
	{
it1=0;
		while(S[lev[0]][it1]!=-1)
			{
			clearBit(x,n,0,S[lev[0]][it1]);clearBit(y,n,0,P[lev[0]][it1]);
			S[lev[0]][it1]=-1;P[lev[0]][it1]=-1;pointP[lev[0]][it1]=-1;
			it1++;
			}
		lev[0]--;it1=0;
		if (x==Bx) {y=Jy;x=Jx;E=Ec;}
		else {y=By;x=Bx;E=Er;}
		if (lev[0]==0) {clearBit(y,n,0,P[0][0]);P[0][0]=-1;free(tempcolsx);free(tempcolsy);return(-3);}
		while(S[lev[0]][it1]!=-1){it1++;}
		clearBit(y,n,0,P[lev[0]][it1-1]);
		z = eleback(S,P,lev,LSVector2,E,y,it1-1,n,pointP);
	}
}
free(tempcolsx);free(tempcolsy);
lev[0]++;
return(0);
}

