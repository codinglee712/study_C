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

void merge(int* A,int low, int mid, int high)
{
	int i;
	int idx1 = low, idx2 = mid + 1;
	int *temp;
	int size = high - low + 1;

	temp = (int*) malloc (sizeof(int) * size);

	for(i = 0; i < size; i++) { //temp가 찰 때까지
		if(idx1 > mid)
			temp[i] = A[idx2++]; //오른쪽 배열만 남았을 때
		else if(idx2 > high)
			temp[i] = A[idx1++]; //왼쪽 배열만 남았을 때
		else if(A[idx1] > A[idx2])
			temp[i] = A[idx2++];
		else if(A[idx1] <= A[idx2])
			temp[i] = A[idx1++];
	}

	for(i = low; i <= high; i++)
		A[i] = temp[i-low];

	free(temp);
}

void mergeSort(int* A, int low, int high, int n)
{
	int mid;

	if(low < high) {
		mid = (low + high) / 2;
		mergeSort(A, low, mid, n);
		mergeSort(A, mid + 1, high, n);
		merge(A, low, mid, high);

		printf("i = ?: ");
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

	mergeSort(arr, 0, n-1, n);

	printf("정렬 후: ");
	printArray(arr, n);

	free(arr);
}