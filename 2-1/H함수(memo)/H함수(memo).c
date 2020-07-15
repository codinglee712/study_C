#include <stdio.h>
#include <stdlib.h>
int H(int n, int* M) 
{
	if(n == 0 || n == 1)
		return 1;
	else {
		int i;
		int result = 0;

		for(i = 0; i < n; i++) {
			if(M[i] == 0)
				M[i] = H(i, M);
			if(M[n - i - 1] == 0)
				M[n - i - 1] = H(n - i - 1, M);
			result += M[i] * M[n - i - 1];
		}
		return result;
	}
}

int main(void)
{
	int n, i;
	int *M;

	scanf("%d", &n);
	M = (int*) malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		M[i] = 0;

	for(i = 0; i <= n; i++)
		printf("%d ", H(i, M));
	printf("\n");

	free(M);
}