#include <stdio.h>
#include <stdlib.h>
#define LE 1
#define UP 2
void print_path(int i, int j, int** BP)
{
	if(BP[i][j] == LE)
		print_path(i, j - 1, BP);
	if(BP[i][j] == UP)
		print_path(i - 1, j, BP);
	printf("<%d %d> ", i, j);
}
int matrixPath(int** m, int r, int c, int i, int j, int** M, int** BP)
{
	if(i == 0 && j == 0)
		return m[i][j];
	else if(i == 0) {
		BP[i][j] = LE;
		if(M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M, BP);
		return M[i][j - 1] + m[i][j];
	}
	else if(j == 0) {
		BP[i][j] = UP;
		if(M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M, BP);
		return M[i - 1][j] + m[i][j];
	}
	else {
		if(M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, r, c, i - 1, j, M, BP);
		if(M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, r, c, i, j - 1, M, BP);

		if(M[i - 1][j] < M[i][j - 1]) {
			BP[i][j] = UP;
			return M[i - 1][j] + m[i][j];
		} 
		else {
			BP[i][j] = LE;
			return M[i][j - 1] + m[i][j];
		}
	}
}
int main(void)
{
	int **m;
	int **M;
	int **BP;
	int i, j, r, c;

	r = c = 4;
	m = (int**) malloc(sizeof(int*) * r);
	M = (int**) malloc(sizeof(int*) * r);
	BP = (int**) malloc(sizeof(int*) * r);
	for(i = 0; i < r; i++) {
		m[i] = (int*) malloc(sizeof(int) * c);
		M[i] = (int*) malloc(sizeof(int) * c);
		BP[i] = (int*) malloc(sizeof(int) * c);
	}

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
			BP[i][j] = 0;
		}
	}

	printf("%d\n", matrixPath(m, r, c, 3, 3, M, BP));

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++)
			printf("%d ", BP[i][j]);
		printf("\n");
	}
	print_path(r - 1, c - 1, BP);

	for(i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
		free(BP[i]);
	}
	free(m);
	free(M);
	free(BP);
}