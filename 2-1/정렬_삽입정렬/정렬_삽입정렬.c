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

void insertionSort(int* A, int n)
{
	int i, j, k, temp;

	for(i = 1; i < n; i++) {
		for(j = 0; j < i; j++) {
			if(A[j] > A[i])
				break;
		}
		temp = A[i];
		for(k = i-1; k >= j; k--)
			A[k+1] = A[k];
		A[j] = temp;

		printf("i = %d: ", i);
		printArray(A, n);
	}
}

int main(void)
{
	int n;
	int *arr;

	srand(time(NULL));
	scanf("%d", &n);

	arr = (int*) malloc (sizeof(int) * n);

	initArray(arr, n);

	printf("정렬 전: ");
	printArray(arr, n);

	insertionSort(arr, n);

	printf("정렬 후: ");
	printArray(arr, n);

	free(arr);
}