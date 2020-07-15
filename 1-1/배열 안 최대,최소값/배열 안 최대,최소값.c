#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inItArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void printArray(int arr[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void printMinMax(int arr[], int size)
{
	int i;
	int minIndex = 0, maxIndex = 0;

	for(i = 0; i < size; i++)
	{
		if(arr[i] > arr[maxIndex])
			maxIndex = i;
		if(arr[i] < arr[minIndex])
			minIndex = i;
	}

	printf("최대값: 인덱스 = %d, 값 = %d\n", maxIndex, arr[maxIndex]);
	printf("최소값: 인덱스 = %d, 값 = %d\n", minIndex, arr[minIndex]);
}

int main(void)
{
	int a[10];

	//srand(time(NULL));
	srand(100);

	inItArray(a, SIZE);
	printArray(a, SIZE);
	printMinMax(a, SIZE);
}