#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "gmp.h"

#define NUM_TYPE unsigned short int
#define BITS_PER_NUM 16
#define VNum(k,i,j) (BitNum(k,i,j) >> 4)
#define VBit(k,i,j) (BitNum(k,i,j)-(VNum(k,i,j)<<4))
#define BitNum(k,i,j) (k*i+j)

NUM_TYPE *LatinMemAllo(int n,int k);

void setBit(NUM_TYPE *LSVector,int n,int i,int j);
int Isbit(NUM_TYPE *LSVector,int n,int i,int j);
void clearBit(NUM_TYPE *LSVector,int n,int i,int j);


unsigned long int fact(int j);

int Eqtest(NUM_TYPE *Bx,NUM_TYPE *Jx,NUM_TYPE *By,NUM_TYPE *Jy,int n);
int eleback(int **S, int **P, int *lev,NUM_TYPE *LSVector2,NUM_TYPE *Er,NUM_TYPE *By,int Scount,int n,int **pointP);
int findperm(int **S,int **P,int **rowPermute,int **colPermute,int *rcount,int *ccount,int lev);
int permMatrixTest(NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,int **rowPermute,int **colPermute,int n);
void printLMatrix(NUM_TYPE *M,int k,int n);
void LSCreate(int n, int k,NUM_TYPE *M,int stage);
NUM_TYPE **LatinMatrix(int n, int k,int r);
NUM_TYPE **LSEquivGenerate(NUM_TYPE **M,int n,int rowsM,int stage,mpz_t *count);
int *makeIntVector(int N);
int equivalence(int n,int k,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2);
void print_m(int **M, int row, int col);
int shell_sort(int *A,int size);
long long int sig(int *Wt_vec,int n);
int *row_wt(NUM_TYPE *LSVector,int n,int k);
int *col_wt(NUM_TYPE *LSVector,int n,int k);
int **make_m(int row, int col);
int combtonum(int *vec,int n);
int associate(int **S,int *lev,NUM_TYPE *Er,NUM_TYPE *Ec,NUM_TYPE *Jx,NUM_TYPE *Jy,NUM_TYPE *Bx,NUM_TYPE *By,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,int **P,int n,int **pointP,int **rowPermute,int **colPermute,int *rcount,int *ccount);
int invar(int n,NUM_TYPE *LSVector1,NUM_TYPE *LSVector2,NUM_TYPE *Er,NUM_TYPE *Ec);
int findperm(int **S,int **P,int **rowPermute,int **colPermute,int *rcount,int *ccount,int lev);
NUM_TYPE *makeVector(int N);
int testlatin(NUM_TYPE *M, int row, int col, int n, int stage);
void print_vec(mpz_t *M, int size);
void v_copy(NUM_TYPE *N,NUM_TYPE *M,int n);
void printLMatrix(NUM_TYPE *M,int k,int n);
