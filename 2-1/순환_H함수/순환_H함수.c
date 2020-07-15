#include <stdio.h>
int H(int n)
{
	int i;
	int sum = 0;

	if(n == 0 || n == 1)
		return 1;
	else {
		for(i = 0; i < n; i++)
			sum += H(i) * H(n-i-1);
		return sum;
	}
}

int main(void)
{
	int n, i;

	scanf("%d", &n);

	for(i = 0; i <= n; i++) //1부터 n까지 H함수 각각 호출한 값 출력
		printf("%d ", H(i));
	printf("\n");
}