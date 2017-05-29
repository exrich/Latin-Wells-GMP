#include <stdlib.h>

unsigned long long int *makeLongIntVector(int N)

{
	unsigned long long int *v;
	int i;
	v = (unsigned long long int *)malloc(sizeof(unsigned long long int)*(N + 2));
	for (i = 0; i <= N; i++) v[i] = 0;
	return(v);
}