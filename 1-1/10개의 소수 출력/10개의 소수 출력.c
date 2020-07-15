#include <stdio.h>
int yesOrNo(int n)
{
	int i;

	for(i = 2; i < n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}
int main(void)
{
	int num = 2;
	int i = 0;

	do
	{
		if(yesOrNo(num) == 1)
		{
			printf("%d번째 소수는 %d\n", i+1, num);
			i++;
		}
		num++;	
	} while(i < 10);
}
