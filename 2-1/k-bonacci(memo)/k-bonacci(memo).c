#include <stdio.h>
#include <stdlib.h>
int k_bo(int n, int k, int* K)
{
	int i;
	int result = 0;

	if(n <= k)
		return 1;
	else {
		for(i = 1; i <= k; i++) {
			if(K[n - i] == 0)
				K[n - i] = k_bo(n - i, k, K);
			result += K[n - i]; 
		}
		return result;
	}
}

int main(void)
{
	int k, n;
	int i, j;
	int *K;

	scanf("%d %d", &k, &n);

	K = (int*) malloc(sizeof(int) * (n + 1)); 
	for(i = 1; i <= n; i++) 
		K[i] = 0;

	for(i = 1; i <= n; i++)
		printf("%d ", k_bo(i, k, K));
	printf("\n");

	for(i = 1; i <= n; i++) 
		printf("%d ", K[i]);
	printf("\n");

	free(K);
}