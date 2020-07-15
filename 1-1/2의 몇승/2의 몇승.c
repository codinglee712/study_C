#include <stdio.h>
int main(void)
{
	int n;
	int k = 0; 
	int temp = 2;

	printf("Enter a number: ");
	scanf("%d", &n);

	while(temp <= n)
	{
		temp *= 2;
		k++;
	}

	printf("%d\n", k);
}