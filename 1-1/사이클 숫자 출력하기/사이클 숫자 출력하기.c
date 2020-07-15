#include <stdio.h>
int main(void)
{
	int num;
	int count = 0;

	printf("Enter a number: ");
	scanf("%d", &num);

	while (num > 0)
	{
		printf("%d ", num);
		if (num == 1)
			num = 0;
		else if(num % 2 == 0) 
			num /= 2;
		else
			num = num * 3 + 1; 

		count++;
	}

	printf("\n±æÀÌ´Â %d\n", count);
}
