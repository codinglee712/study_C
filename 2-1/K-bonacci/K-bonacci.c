#include <stdio.h>
int k_bo(int n, int k)
{
	int i, result = 0;

	if(n <= k)
		return 1;
	else {
		for(i = 1; i <= k; i++)
		 result += k_bo(n - i, k);  
	}
	return result;
}

int main(void)
{
	int k, n;
	int i;

	scanf("%d %d", &k, &n);
	for(i = 1; i <= n; i++)
		printf("%d ", k_bo(i, k));
	printf("\n");
}