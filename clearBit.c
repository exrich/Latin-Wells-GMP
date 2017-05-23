#include "latin.h"
/*#define NUM_TYPE unsigned short int
#define BITS_PER_NUM 16
#define VNum(k,i,j) (BitNum(k,i,j) >> 4)
#define VBit(k,i,j) (BitNum(k,i,j)-(VNum(k,i,j)<<4))
#define BitNum(k,i,j) (k*i+j)*/

void clearBit(NUM_TYPE *LSVector,int k,int i,int j)
{
	int y,z;
	NUM_TYPE Mask=1;
	y = VNum(k,i,j);
	z = VBit(k,i,j);
	LSVector[y] = (LSVector[y] & ~(Mask << (BITS_PER_NUM-z-1)));
}