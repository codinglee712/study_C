#include <stdio.h>
int main(void)
{
	int num, i, result;

	scanf("%d",&num);

	for(i = 0; i<= num; i++)
		if(num == fibo(i))
		{
			result = fibo(i+1);
			break;
		}

	if(num <= 1)
		result = 2;

	printf("%d\n", result);
}
int fibo(int n)
{
	if(n <= 1)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}