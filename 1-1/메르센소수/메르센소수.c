#include <stdio.h>
int twoToThePower(int n)
{
	int i;
	int pow = 1;

	for(i = 1; i <= n; i++)
		pow *= 2;

	return pow;
}
int isPrime(int x)
{
	int i;

	for(i = 2; i < x; i++)
		if(x % i == 0)
			return 0;

	return 1;
}
int main(void)
{
	int num, i;
	int result;

	printf("Enter a number(>1): ");
	scanf("%d", &num);

	for(i = 2; i <= num; i++)
	{
		result = twoToThePower(i) - 1;
		if(isPrime(result) == 1)
			printf("%d^%d - 1인 %d는 메르센 소수\n", 2, i, result);
	}
}
