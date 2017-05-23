#include "latin.h"
/*#include <stdlib.h>

#define NUM_TYPE unsigned short int
#define BITS_PER_NUM 16
#define VNum(k,i,j) (BitNum(k,i,j) >> 4)
#define VBit(k,i,j) (BitNum(k,i,j)-(VNum(k,i,j)<<4))
#define BitNum(k,i,j) (k*i+j)*/

int Isbit(NUM_TYPE *LSVector,int k,int i,int j)
{
	int y,z,a;
	NUM_TYPE Mask=1,test;
	y = VNum(k,i,j);
	z = VBit(k,i,j);
	test = Mask << (BITS_PER_NUM-z-1);
	if (LSVector[y] & test) a=1; else a=0;	
	return(a);
}