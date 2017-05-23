#include <stdio.h>

long long int sig(int *Wt_vec,int n)
{
int max,a=2,i,t=1;
long long int val=Wt_vec[0];
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