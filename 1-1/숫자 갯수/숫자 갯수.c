#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int data[100];
	int count[10] = {0};
	int i, size;

	printf("Enter the number of random numbers(<=100): ");
	scanf("%d", &size);

	srand(time(NULL));

	for(i = 0; i < size; i++)
	{
		data[i] = rand() % 10;
		count[data[i]]++;
	}

	for(i = 0; i < 10; i++)
		printf("%d의 개수는 %d\n", i, count[i]);

	printf("-----------------------------------------\n");
	printf("발생된 난수는\n");
	for(i = 0; i < size; i++)
	{
		printf("%5d ", data[i]);
		if(i % 5 == 4)
			printf("\n");
	}
}
