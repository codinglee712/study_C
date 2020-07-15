#include <stdio.h>
int sum(int n)
{
	int total = 0;

	if(n == 0)
		return 0;
	else
	{
		total = n * 10 + 2 + sum(n-1);
		printf("%d ", n * 10 + 2);
		return total;
	}
}

int main(void)
{
	int num;

	scanf("%d", &num);

	printf("\n%d\n", sum(num));
}