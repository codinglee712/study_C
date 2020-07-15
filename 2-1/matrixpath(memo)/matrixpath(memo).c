#include <stdio.h>
#include <stdlib.h>
int matrixPath(int** m, int r, int c, int i, int j, int** M)
{
	if(i == 0 && j == 0)
		return m[i][j];
	else if(i == 0) {
		if(M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M);
		return M[i][j - 1] + m[i][j];
	}
	else if(j == 0) {
		if(M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M);
		return M[i - 1][j] + m[i][j];
	}
	else {
		if(M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M);
		if(M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M);
		return ((M[i - 1][j] < M[i][j - 1]) ? M[i - 1][j] : M[i][j - 1]) + m[i][j];
	}
}
int main(void)
{
	int **m;
	int **M;
	int i, j, r, c;

	r = c = 4;
	m = (int**) malloc(sizeof(int*) * r);
	M = (int**) malloc(sizeof(int*) * r);
	for(i = 0; i < r; i++) {
		m[i] = (int*) malloc(sizeof(int) * c);
		M[i] = (int*) malloc(sizeof(int) * c);
	}

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
		}
	}

	printf("%d\n", matrixPath(m, r, c, 3, 3, M));

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}

	for(i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
}