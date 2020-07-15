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

int partition(int *A, int low, int high) //i, j를 왼쪽에서부터 시작, pivot이 오른쪽 끝
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

int partition2(int *A, int low, int high) //i는 왼쪽에서, j는 오른쪽에서 시작, pivot이 오른쪽 끝
{	
	int i, j;

	i = low;
	j = high - 1;
	while(i < j) {
		while(A[j] > A[high])
			j--;
		while(A[i] < A[high])
			i++;
		if(i > j)
			break;
		swap(A, i, j);
	}
	if(A[i] > A[high])
		swap(A, i, high);

	return i;
}

int partition3(int *A, int low, int high) //i, j를 왼쪽에서부터 시작, pivot이 왼쪽 끝
{	
	int i, j;

	i = low;
	for(j = low+1; j <= high; j++) {
		if(A[low] > A[j]) 
			swap(A, ++i, j);
	}
	swap(A, i, low);

	return i;
}

int partition4(int *A, int low, int high) //i는 왼쪽에서, j는 오른쪽에서 시작, pivot이 왼쪽 끝
{	
	int i, j;

	i = low + 1;
	j = high;
	while(i < j) {
		while(A[j] > A[low]) 
			j--;
		while(A[i] < A[low]) 
			i++;
		if(i > j)
			break;
		swap(A, i, j);
	}
	if(A[j] < A[low])
		swap(A, j, low);

	return j;
}

void quickSort(int* A, int low, int high, int n)
{
	int pivot;

	if(low < high) {
		pivot = partition(A, low, high);
		//pivot = partition2(A, low, high);
		//pivot = partition3(A, low, high);
		//pivot = partition4(A, low, high);
		printf("i = ?: ");
		printArray(A, n);
		quickSort(A, low, pivot - 1, n);
		quickSort(A, pivot + 1, high, n);
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

	quickSort(arr, 0, n-1, n);

	printf("정렬 후: ");
	printArray(arr, n);

	free(arr);
}