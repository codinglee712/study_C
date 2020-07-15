#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initArray(int* A, int size)
{
	int i;
	for(i = 0; i < size; i++)
		A[i] = rand() % 100;
}

void printArray(int* A, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void swap(int* A, int i, int j)
{
	int temp;
	temp = A[j];
	A[j] = A[i];
	A[i] = temp;
}

int partition(int *A, int low, int high)
{	
	int i, j;

	i = low - 1;
	for(j = low; j < high; j++) {
		if(A[high] > A[j]) 
			swap(A, ++i, j);
	}
	swap(A, ++i, high);

	return i;
}

int find(int* A, int low, int high, int keyIdx)
{
	int pivot;

	if(low <= high) {
		pivot = partition(A, low, high);

		if(pivot == keyIdx)
			return A[keyIdx];
		else if(pivot > keyIdx)
			find(A, low, pivot - 1, keyIdx);
		else
			find(A, pivot + 1, high, keyIdx);
	}
}

int main(void)
{
	int n, key;
	int *arr;

	srand(time(NULL));
	scanf("%d", &n);

	arr = (int*) malloc (sizeof(int) * n);

	printf("몇번째로 작은 수: ");
	scanf("%d", &key);

	initArray(arr, n);
	printArray(arr, n);

	printf("%d번째 작은 수는 %d\n", key, find(arr, 0, n-1, key-1));

	free(arr);
}