#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int n[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", n[i]);
	printf("\n");
}

void selectionSort(int n[], int size)
{
	int i, j, temp, least;

	for(i = 0; i < size-1; i++)
	{
		least = i;
		for(j = i; j < size; j++)//i(정렬이 된 수 다음)부터 비교
			if(n[j] < n[least])
				least = j;

		temp = n[i];
		n[i] = n[least];
		n[least] = temp;
	}
	printArray(n, size);
}

int main(void)
{
	int num[SIZE];
	int i;

	//srand(time(NULL));

	for(i = 0; i < SIZE; i++)
		num[i] = rand() % 100;

	printf("발생된 난수: ");
	printArray(num, SIZE);

	printf("정렬 후: ");
	selectionSort(num, SIZE);
}