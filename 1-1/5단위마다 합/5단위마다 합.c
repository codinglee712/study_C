#include <stdio.h>
int main(void)
{
	int i, num, sum, count;

	num = 1;
	for(i = 0; i < 30/5; i++) {
		sum = 0;
		count = 0;
		while(count < 5)
		{
			sum += num;
			num++;
			count++;
		}
		printf("%d - %d±îÁö ÇÕ = %d\n", num-5, num-1, sum);
	}
}
