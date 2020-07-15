#include <stdio.h>
#define SIZE 10
int main(void)
{
	int odd[SIZE], even[SIZE];
	int num, i;
	int oddIndex = 0, evenIndex = 0; 

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter a number: ");
		scanf("%d", &num);

		if(num % 2 == 0)
			even[evenIndex++] = num;
		else
			odd[oddIndex++] = num;
	}

	printf("\nÈ¦¼ö Ãâ·Â: ");
	for(i = 0; i < oddIndex; i++)
		printf("%d ", odd[i]);

	printf("\nÂ¦¼ö Ãâ·Â: ");
	for(i = 0; i < evenIndex; i++)
		printf("%d ", even[i]);
	printf("\n");
}


