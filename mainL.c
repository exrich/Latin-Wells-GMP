#include "latin.h"
/*#include <stdio.h>
#include <time.h>
#include <gmp.h>

#define NUM_TYPE unsigned short int

void LSCreate(int n, int k,NUM_TYPE *M,int stage);
NUM_TYPE **LatinMatrix(int n, int k,int r);
void setBit(NUM_TYPE *LSVector,int k,int i,int j);
NUM_TYPE *LatinMemAllo(int n,int k);
NUM_TYPE **LSEquivGenerate(NUM_TYPE **M,int n,int rowsM,int stage,mpz_t *count);
int *makeIntVector(int N);
int equivalence(int n,int k,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2);*/

int main(void)
{
	int i,n;
	unsigned long int initcount=1;
	mpz_t count[5000];
	mpz_array_init (count[0], 5000, 512);
	double start,finish,dur;
	NUM_TYPE **M;
	printf("Latin Squares Wells 1.1 Bit Based\n");
	printf("Name: Richard Crampton\nYear: 4\nEmail Address: richard.crampton@ic.ac.uk");
	printf("\nTime: %s ",__TIME__);
	printf("\nDate: %s\n",__DATE__);
	printf("\nThis program finds the number of nxn latin squares of order n!!\n\n");
	printf("Please enter the size n x n of your latin square:");
	scanf("%d",&n);
	start = (double)clock();
	M = LatinMatrix(n,n,5000);
	for (i=0;i<=n-1;i++)
	{
	setBit(M[0],n,i,i);
	}
	mpz_set_ui(count[0],initcount);
	LSEquivGenerate(M,n,0,2,count);
	finish = (double)clock();
	dur = (finish-start)/CLOCKS_PER_SEC;
	printf("Number of %d x %d Latin Squares in %lf seconds\n\n",n,n,dur);
	scanf_s("%d", &n);
	return(0);
}
