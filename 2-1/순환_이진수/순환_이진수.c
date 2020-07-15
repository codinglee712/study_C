#include <stdio.h>
void print_binary(int x)
{
	if(x > 0) {
		print_binary(x / 2);
		printf("%d", x % 2); //출력 순서가 역순
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);

	print_binary(n);
	printf("\n");
}