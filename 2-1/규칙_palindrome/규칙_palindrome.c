#include <stdio.h>
int calculateReverse(int n)
{
	int result = 0, last;

	while(n != 0) {
		last = n % 10;
		result = result * 10 + last; // *= 연산자 쓰면 답 안나옴
		n /= 10;
	}
	return result;
}

int main(void)
{
	int n, rn;
	int count = 0;

	scanf("%d", &n);
	
	rn = calculateReverse(n);
	while(n != rn) {
		if(rn < 0)
			break;
		n += rn;
		count++;
		rn = calculateReverse(n);
	}

	if(rn < 0)
		printf("Overflow\n");
	else
		printf("%d %d\n", count, n);
}