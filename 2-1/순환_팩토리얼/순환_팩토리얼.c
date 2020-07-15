#include <stdio.h>
int factorial(int n)
{
	if(n <= 1) {
		printf("%d ", n);
		return 1;
	} 
	else {
		printf("%d * ", n);
		return n * factorial(n-1);
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("%d! = ", n);
	printf("= %d\n", factorial(n)); //재귀를 돌고난 후 출력
}