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

void selectionSort(int* A, int n) //오름차순, 큰 값을 찾아 오른쪽으로, i가 0부터
{
	int i, j, temp;
	int maxIdx;

	for(i = 0; i < n-1; i++) {
		maxIdx = 0;
		for(j = 1; j <= n-i-1; j++) {
			if(A[maxIdx] < A[j])
				maxIdx = j;
		}
		temp = A[maxIdx];
		A[maxIdx] = A[n-i-1];
		A[n-i-1] = temp;

		printf("i = %d: ", i);
		printArray(A, n);
	}
}

void selectionSort2(int* A, int n) //오름차순, 큰 값을 찾아 오른쪽으로, i가 n부터
{
	int i, j, temp;
	int maxIdx;

	for(i = n; i > 1; i--) {
		maxIdx = 0;
		for(j = 1; j <= i-1; j++) {
			if(A[maxIdx] < A[j])
				maxIdx = j;
		}
		temp = A[maxIdx];
		A[maxIdx] = A[i-1];
		A[i-1] = temp;

		printf("i = %d: ", n-i+1); 
		printArray(A, n);
	}
}

void selectionSort3(int* A, int n) //오름차순, 작은 값을 찾아 왼쪽으로, i가 0부터
{
	int i, j, temp;
	int minIdx;

	for(i = 0; i < n-1; i++) {
		minIdx = i;
		for(j = i; j < n; j++) {
			if(A[minIdx] > A[j])
				minIdx = j;
		}
		temp = A[minIdx];
		A[minIdx] = A[i];
		A[i] = temp;

		printf("i = %d: ", i+1); 
		printArray(A, n);
	}
}

void selectionSort4(int* A, int n) //내림차순, 큰 값을 찾아 왼쪽으로, i가 0부터
{
	int i, j, temp;
	int maxIdx;

	for(i = 0; i < n-1; i++) {
		maxIdx = i;
		for(j = i; j < n; j++) {
			if(A[maxIdx] < A[j])
				maxIdx = j;
		}
		temp = A[maxIdx];
		A[maxIdx] = A[i];
		A[i] = temp;

		printf("i = %d: ", i+1); 
		printArray(A, n);
	}
}

void selectionSort5(int* A, int n) //내림차순, 작은 값을 찾아 오른쪽으로, i가 0부터
{
	int i, j, temp;
	int minIdx;

	for(i = 0; i < n-1; i++) {
		minIdx = 0;
		for(j = 1; j <= n-i-1; j++) {
			if(A[minIdx] > A[j])
				minIdx = j;
		}
		temp = A[minIdx];
		A[minIdx] = A[n-i-1];
		A[n-i-1] = temp;

		printf("i = %d: ", i+1); 
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

	selectionSort(arr, n);
	//selectionSort2(arr, n);
	//selectionSort3(arr, n);
	//selectionSort4(arr, n);
	//selectionSort5(arr, n);

	printf("정렬 후: ");
	printArray(arr, n);

	free(arr);
}
