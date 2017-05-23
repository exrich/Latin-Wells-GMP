#include <stdio.h>
#include "latin.h"
/*#define NUM_TYPE unsigned short int
#define BITS_PER_NUM 16


NUM_TYPE *makeVector(int N);*/

NUM_TYPE *LatinMemAllo(int n,int k)

{

int i,bits_req = n*k,array_size;

NUM_TYPE *LSVector;

array_size = (bits_req >> 4)+1;
LSVector = makeVector(array_size);
for (i=0;i<=array_size;i++)
{LSVector[i]=0;}
return(LSVector);

}


