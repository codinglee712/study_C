#include <stdio.h>
#include <stdlib.h>
int fi_bo(int n, int* F)
{
	int i;
	int result = 0;

	if(n == 1 || n == 2)
		return 1;
	if(F[n - 1] == 0)
		F[n - 1] = fi_bo(n - 1, F);
	if(F[n - 2] == 0)
		F[n - 2] = fi_bo(n - 2, F);
	return F[n - 1] + F[n - 2];
}

int main(void)
{
	int n, i;
	int *F;

	scanf("%d", &n);

	F = (int*) malloc(sizeof(int) * (n + 1)); 
	for(i = 1; i <= n; i++) 
		F[i] = 0;

	for(i = 1; i <= n; i++)
		printf("%d ", fi_bo(i, F));
	printf("\n");

	for(i = 1; i <= n; i++) 
		printf("%d ", F[i]);
	printf("\n");

	free(F);
}