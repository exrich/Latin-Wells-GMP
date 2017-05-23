
#include <stdlib.h>

int *makeIntVector(int N)

{
	int *v,i;
	v = (int *)malloc(sizeof(int)*(N+2));
	for(i=0;i<=N;i++) v[i]=0;
	return(v);
}