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
		for(j = i; j < size; j++)//i(������ �� �� ����)���� ��
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

	printf("�߻��� ����: ");
	printArray(num, SIZE);

	printf("���� ��: ");
	selectionSort(num, SIZE);
}