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

void bubbleSort(int* A, int n) //��������, ū ���� ã�� ����������, i�� 0����
{
	int i, j, temp;
	int sorted;

	for(i = 0; i < n-1; i++) {
		sorted = 0;
		for(j = 0; j < n-i-1; j++) {
			if(A[j] > A[j+1]) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				sorted = 1;
			}
		}
		if(!sorted) //������ �̹� �Ϸ�Ǿ� sorted�� 1�� �ٲ��� ������ ����
			return;
		printf("i = %d: ", i);
		printArray(A, n);
	}
}

void bubbleSort2(int* A, int n) //��������, ���� ���� ã�� ����������, i�� 0����
{
	int i, j, temp;

	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			if(A[j] < A[j+1]) {
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
		printf("i = %d: ", i);
		printArray(A, n);
	}
}

void bubbleSort3(int* A, int n) //��������, ���� ���� ã�� ��������, j�� n����
{
	int i, j, temp;
	int sorted;

	for(i = 0; i < n-1; i++) {
		sorted = 0;
		for(j = n-1; j > i; j--) {
			if(A[j] < A[j-1]) {
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				sorted = 1;
			}
		}
		if(!sorted) //������ �̹� �Ϸ�Ǿ� sorted�� 1�� �ٲ��� ������ ����
			return;
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

	printf("���� ��: ");
	printArray(arr, n);

	//bubbleSort(arr, n);
	//bubbleSort2(arr, n);
	bubbleSort3(arr, n);

	printf("���� ��: ");
	printArray(arr, n);

	free(arr);
}
