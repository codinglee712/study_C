#include <stdio.h>
int main(void)
{
	int binary[8];
	int num, i;
	int bIndex = 0;

	printf("Enter ¾ç¼ö(<265): ");
	scanf("%d", &num);

	while(num != 0)
	{
		binary[bIndex] = num % 2;
		num /= 2;
		bIndex++;
	}

	for(i = bIndex-1; i >= 0; i--)
		printf("%d ", binary[i]);
	printf("\n");
}
	
