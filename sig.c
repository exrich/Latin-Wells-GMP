#include <stdio.h>

unsigned long long int sig(unsigned long long int *Wt_vec,int n)
{
int a = 2, i, t = 1;
unsigned long long int max;
unsigned long long int val=Wt_vec[0];
max = Wt_vec[n-1];
while ( a < max)
{
	a = a << 1;
	t++;
}
for (i=1;i<=n-1;i++)
{
	val = val | (Wt_vec[i] << (t*i));
}
return(val);
}