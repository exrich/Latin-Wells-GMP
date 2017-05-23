int findperm(int **S,int **P,int **rowPermute,int **colPermute,int *rcount,int *ccount,int lev)
{
int i=0,j=0;
for (i=0;i<=lev-1;i++)
			{
				if ((i % 2)==0)
				{
				while (S[i][j]!=-1)
				{
					rowPermute[0][rcount[0]]=S[i][j];
					rowPermute[1][rcount[0]]=P[i][j];
					rcount[0]++;
					j++;
				}
				}
				else
				{
				while (S[i][j]!=-1)
				{
					colPermute[0][ccount[0]]=S[i][j];
					colPermute[1][ccount[0]]=P[i][j];
					ccount[0]++;
					j++;
				}
				}
				j=0;
			}
return(0);
}