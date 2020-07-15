#include <stdio.h>
#include <stdlib.h>
int comb(int n, int r, int** C)
{
	printf("comb(%d, %d)\n", n, r);

	if(r == 0 || r == n)
		return 1;
	else {
		if(C[n - 1][r - 1] == 0)
			C[n - 1][r - 1] = comb(n - 1, r - 1, C);
		if(C[n - 1][r] == 0)
			C[n - 1][r] = comb(n - 1, r, C);
		return C[n - 1][r - 1] + C[n - 1][r];
	}
}

int main(void)
{
	int n, r, i, j;
	int **C;

	scanf("%d %d", &n, &r);

	C = (int**) malloc(sizeof(int*) * n);
	for(i = 0; i < n; i++)
		C[i] = (int*) malloc(sizeof(int) * (r + 1));

	for(i = 0; i < n; i++)
		for(j = 0; j <= r; j++)
			C[i][j] = 0;

	printf("%d\n", comb(n, r, C));

	for(i = 0; i < n; i++)
		free(C[i]);
	free(C);
}