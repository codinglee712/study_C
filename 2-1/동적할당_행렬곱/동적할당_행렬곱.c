#include<stdio.h>
#include<stdlib.h>
void matrixAdd(int **a, int **b, int **x, int ar, int xc, int bc)
{
	int i, j, k;
	for(i = 0; i < ar; i++) {
		for(j = 0; j < bc; j++) {
			x[i][j] = 0;
			for(k = 0; k < xc; k++)
				x[i][j] += a[i][k] * b[k][j];
		}
	}
}

void printMatrix(int **a, int r, int c)
{
	int i, j;
	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}

void readMatrix(int **a, int r, int c)
{
	int i, j;
	for(i = 0; i < r; i++) 
		for(j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}

void transMatrix(int **a, int r, int c)
{
	int i, j;
	int **tmp;

	tmp = (int**) malloc(sizeof(int*) * c);
	for(i = 0; i < c; i++)
		tmp[i] = (int*) malloc(sizeof(int*) * r);

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			tmp[j][i] = a[i][j];

	printMatrix(tmp, c, r);

	for(i = 0; i < c; i++)
		free(tmp[i]);
	free(tmp);
}

int main(void)
{
	int **A, **B;
	int **X;
	int aRow, aCol, bRow, bCol; //행렬곱은 앞 행렬의 열과 뒤 행렬의 행이 같아야 함
	int i, j;

	printf("행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);
	printf("행렬 B의 행과 열의 개수(C의 행은 %d이어야): ", aCol);
	scanf("%d %d", &bRow, &bCol);
	A = (int**) malloc(sizeof(int*) * aRow);
	B = (int**) malloc(sizeof(int*) * bRow);
	X = (int**) malloc(sizeof(int*) * aRow);
	for(i = 0; i < aRow; i++) {
		A[i] = (int*) malloc(sizeof(int*) * aCol);
		X[i] = (int*) malloc(sizeof(int*) * bCol);
	}
	for(i = 0; i < bRow; i++) 
		B[i] = (int*) malloc(sizeof(int*) * bCol);
		

	printf("<%d x %d> 행렬 A입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("<%d x %d> 행렬 B입력:\n", bRow, bCol);
	readMatrix(B, bRow, bCol);
	for(i = 0; i < aRow; i++)
		for(j = 0; j < bCol; j++)
			X[i][j] = 0;

	matrixAdd(A, B, X, aRow, aCol, bCol);

	printf("행렬곱:\n");
	printMatrix(X, aRow, bCol);

	printf("전치행렬:\n");
	transMatrix(B, bRow, bCol);

	for(i = 0; i < aRow; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}