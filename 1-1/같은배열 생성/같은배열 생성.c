#define SIZE 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int a[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		a[i] = rand() % 2;
}

void printArray(int a[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int equalArray(int a[], int b[], int size)
{
	int i;
	
	for(i = 0; i < size; i++)
		if(a[i] != b[i])
			return 0;
	return 1;
}

int main(void)
{
	int arrayA[SIZE], arrayB[SIZE];
	int count = 1;

	srand(time(NULL));

	do
	{
		printf("\n%d 번째 시도\n", count++);
		generateArray(arrayA, SIZE);
		generateArray(arrayB, SIZE);

		printf("ArrayA: ");
		printArray(arrayA, SIZE);
		printf("ArrayB: ");
		printArray(arrayB, SIZE);

	} while(!equalArray(arrayA, arrayB, SIZE));
}