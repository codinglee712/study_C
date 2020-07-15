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
	int aRow, aCol, bRow, bCol; //��İ��� �� ����� ���� �� ����� ���� ���ƾ� ��
	int i, j;

	printf("��� A�� ��� ���� ����: ");
	scanf("%d %d", &aRow, &aCol);
	printf("��� B�� ��� ���� ����(C�� ���� %d�̾��): ", aCol);
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
		

	printf("<%d x %d> ��� A�Է�:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("<%d x %d> ��� B�Է�:\n", bRow, bCol);
	readMatrix(B, bRow, bCol);
	for(i = 0; i < aRow; i++)
		for(j = 0; j < bCol; j++)
			X[i][j] = 0;

	matrixAdd(A, B, X, aRow, aCol, bCol);

	printf("��İ�:\n");
	printMatrix(X, aRow, bCol);

	printf("��ġ���:\n");
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