unsigned long int fact(int j);

int combtonum(int *vec,int n)
{
	int serial=0,mult=1,bico,j,i;
	unsigned long int r,z=1;
	for (j=0;j<=n-1;j++)
	{
		if (vec[j]!=0)
		{
			for (i=vec[j]-1+n-j;i>=n-j+1;i--)
			{
				z*=i;
			}
		r=fact(vec[j]-1);
		bico=(z/r);
		serial += bico;
		}
	}
	return(serial);
}