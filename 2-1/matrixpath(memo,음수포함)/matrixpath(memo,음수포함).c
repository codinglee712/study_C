#include <stdio.h>
#include <stdlib.h>
int matrixPath(int** m, int r, int c, int i, int j, int** M, int** M2)
{
	if(i == 0 && j == 0)
		return m[i][j];
	else if(i == 0) {
		if(M2[i][j - 1] == 0) {
			M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M, M2);
			M2[i][j - 1] = 1;
		}
		return M[i][j - 1] + m[i][j];
	}
	else if(j == 0) {
		if(M2[i - 1][j] == 0) {
			M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M, M2);
			M2[i - 1][j] = 1;
		}
		return M[i - 1][j] + m[i][j];
	}
	else {
		if(M2[i - 1][j] == 0) {
			M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M, M2);
			M2[i - 1][j] = 1;
		}
		if(M2[i][j - 1] == 0) {
			M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M, M2);
			M2[i][j - 1] = 1;
		}
		return ((M[i - 1][j] < M[i][j - 1]) ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
	}
}
int main(void)
{
	int **m;
	int **M, **M2;
	int i, j, r, c;

	r = c = 4;
	m = (int**) malloc(sizeof(int*) * r);
	M = (int**) malloc(sizeof(int*) * r);
	M2 = (int**) malloc(sizeof(int*) * r);
	for(i = 0; i < r; i++) {
		m[i] = (int*) malloc(sizeof(int) * c);
		M[i] = (int*) malloc(sizeof(int) * c);
		M2[i] = (int*) malloc(sizeof(int) * c); 
	}

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
			M2[i][j] = 0;
		}
	}

	printf("%d\n", matrixPath(m, r, c, 3, 3, M, M2));

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%d ", M2[i][j]);
		printf("\n");
	}

	for(i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(M2[i]);
	}
	free(m);
	free(M);
	free(M2);
}