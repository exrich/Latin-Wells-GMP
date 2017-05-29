#include "latin.h"

int equivalence(int n, int k, NUM_TYPE *LSVector1, NUM_TYPE *LSVector2)
{
	int it2, it1, it3, i, j, ass = 0, lev = 0, **S, **P, **pointP, z, **rowPermute, **colPermute, rcount = 0, ccount = 0;
	NUM_TYPE *Er, *Ec, *Bx, *By, *Jx, *Jy;

	Er = LatinMemAllo(n, n); Ec = LatinMemAllo(n, n); Bx = LatinMemAllo(1, n); By = LatinMemAllo(1, n); Jx = LatinMemAllo(1, n); Jy = LatinMemAllo(1, n);
	S = make_m(2 * n, n); P = make_m(2 * n, n); pointP = make_m(2 * n, n);
	rowPermute = make_m(2, n); colPermute = make_m(2, n);
	for (i = 0; i <= 2 * n - 1; i++) { for (j = 0; j <= n - 1; j++) { S[i][j] = -1; P[i][j] = -1; pointP[i][j] = -1; } }

	z = invar(n, LSVector1, LSVector2, Er, Ec);
	if (z == 0) { free(S[0]); free(S); free(P[0]); free(P); free(pointP[0]); free(pointP); free(Er); free(Ec); free(Bx); free(By); free(Jx); free(Jy); free(rowPermute[0]); free(colPermute[0]); free(rowPermute); free(colPermute); return(0); }

	/*printLMatrix(LSVector1,n,n);printLMatrix(LSVector2,n,n);
	printLMatrix(Er,n,n);printLMatrix(Ec,n,n);*/
	for (it1 = 0; it1 <= n - 1; it1++)
	{
		if (Isbit(Bx, n, 0, it1) == 0)
		{
			setBit(Bx, n, 0, it1); S[0][0] = it1;
			for (it2 = 0; it2 <= n - 1; it2++)
			{
				if (Isbit(Er, n, S[lev][0], it2) == 1 && Isbit(By, n, 0, it2) == 0)
				{
					setBit(By, n, 0, it2); P[0][0] = it2;
					lev++;
					for (it3 = 0; it3 <= 2000; it3++)
					{
						if ((lev % 2) == 1)
						{
							ass = associate(S, &lev, Er, Ec, Jx, Jy, Bx, By, LSVector1, LSVector2, P, n, pointP, rowPermute, colPermute, &rcount, &ccount);
							if (ass == 1)
							{
								free(S[0]); free(S); free(P[0]); free(P); free(pointP[0]); free(pointP); free(Er); free(Ec); free(Bx); free(By); free(Jx); free(Jy); free(rowPermute[0]); free(colPermute[0]); free(rowPermute); free(colPermute); return(1);
							}
							if (ass == -2) { break; }
							if (ass == -3) { break; }
						}

						else if ((lev % 2) == 0)
						{
							ass = associate(S, &lev, Ec, Er, Bx, By, Jx, Jy, LSVector1, LSVector2, P, n, pointP, rowPermute, colPermute, &rcount, &ccount);
							if (ass == 1)
							{
								free(S[0]); free(S); free(P[0]); free(P); free(pointP[0]); free(pointP); free(Er); free(Ec); free(Bx); free(By); free(Jx); free(Jy); free(rowPermute[0]); free(colPermute[0]); free(rowPermute); free(colPermute); return(1);
							}
							if (ass == -2) { break; }
							if (ass == -3) { break; }
						}
					}
				}
				if (ass == -3)
				{
					if (it2 == n - 1 && lev == 0)
					{
						free(S[0]); free(S); free(P[0]); free(P); free(pointP[0]); free(pointP); free(Er); free(Ec); free(Bx); free(By); free(Jx); free(Jy); free(rowPermute[0]); free(colPermute[0]); free(rowPermute); free(colPermute); return(0);
					}
				}
				if (ass == -2)
				{
					findperm(S, P, rowPermute, colPermute, &rcount, &ccount, lev);
					lev = 0;
					ass = 0;
					break;
				}
			}
		}
	}
	free(S[0]); free(S); free(P[0]); free(P); free(pointP[0]); free(pointP); free(Er); free(Ec); free(Bx); free(By); free(Jx); free(Jy); free(rowPermute[0]); free(colPermute[0]); free(rowPermute); free(colPermute); return(0);
}

