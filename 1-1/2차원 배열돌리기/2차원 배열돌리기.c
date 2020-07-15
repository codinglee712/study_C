#define SIZE 4
#include <stdio.h>
void initArray(int a[][SIZE], int size)
{
	int i, j;
	int num = 1;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			a[i][j] = num;
			num++;
		}
}

void printArray(int a[][SIZE], int size)
{
	int i, j;

	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
			printf("%3d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void initResultArray(int a[][SIZE], int b[][SIZE], int size)
{
	int i, j;

	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
			a[i][j] = b[i][j];
}

void rotate2dimArray(int a[][SIZE], int b[][SIZE], int size)
{
    int i, j;

	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
			b[i][j] = a[3 - j][i];

	initResultArray(a, b, size);
}

int main(void)
{
	int A[SIZE][SIZE];
	int B[SIZE][SIZE];
	int i;

	initArray(A, SIZE);
	printArray(A, SIZE);

	for(i = 0; i < SIZE; i++)
	{
		rotate2dimArray(A, B, SIZE);
		printArray(A, SIZE);
	}
}