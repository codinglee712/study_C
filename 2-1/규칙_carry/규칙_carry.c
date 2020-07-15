#include <stdio.h>
int main(void)
{
	int n1, n2;
	int carry = 0;
	int count = 0;

	scanf("%d %d", &n1, &n2);

	while(n1 != 0 || n2 != 0) {
		if(n1 % 10 + n2 % 10 + carry >= 10)
			carry = 1;
		else
			carry = 0;
		count += carry;
		n1 /= 10;
		n2 /= 10;
	}

	printf("%d\n", count);
}