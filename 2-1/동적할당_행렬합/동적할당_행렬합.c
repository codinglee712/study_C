#include<stdio.h>
#include<stdlib.h>
void matrixAdd(int **a, int **b, int **x, int r, int c)
{
	int i, j;
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
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

int main(void)
{
	int **A, **B;
	int **X;
	int aRow, aCol; //행렬합은 행렬의 크기가 같은 두 행렬을 가지고 함
	int i, j;

	scanf("%d %d", &aRow, &aCol);
	A = (int**) malloc(sizeof(int*) * aRow);
	B = (int**) malloc(sizeof(int*) * aRow);
	X = (int**) malloc(sizeof(int*) * aRow);
	for(i = 0; i < aRow; i++) {
		A[i] = (int*) malloc(sizeof(int*) * aCol);
		B[i] = (int*) malloc(sizeof(int*) * aCol);
		X[i] = (int*) malloc(sizeof(int*) * aCol);
	}

	printf("<%d x %d> 행렬 A입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("<%d x %d> 행렬 B입력:\n", aRow, aCol);
	readMatrix(B, aRow, aCol);
	for(i = 0; i < aRow; i++)
		for(j = 0; j < aCol; j++)
			X[i][j] = 0;

	matrixAdd(A, B, X, aRow, aCol);

	printf("행렬합:\n");
	printMatrix(X, aRow, aCol);

	for(i = 0; i < aRow; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}
