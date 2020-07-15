#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initTable(int t[][5], int size)
{
	int i, j;

	for(i = 0; i < size; i++)
		for(j = 0; j < 5; j++)
			t[i][j] = rand() % 100;
}

int totalTable(int t[][5], int size)
{
	int i, j;
	int total = 0;

	for(i = 0; i < size; i++)
		for(j = 0; j < 5; j++)
			total += t[i][j];
	return total;
}

void printTable(int t[][5], int size)
{
	int i, j;

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < 5; j++)
			printf("%5d", t[i][j]);
		printf("\n");
	}
}

void sumTable(int t[][5], int size)
{
	int i, j;
	int sum;

	for(j = 0; j < 5; j++)
	{
		sum = 0;
		for(i = 0; i < size; i++)
			sum += t[i][j];
		printf("%5d", sum);
	}
	printf("\n");
}

int main(void)
{
	int table[3][5];
	int i, j;
	int total = 0;
	
	srand(time(NULL));

	initTable(table, 3);
	printf("발생된 난수의 평균은 %d입니다.\n", totalTable(table, 3) / 15);

	printTable(table, 3);

	printf("---각 열의 합\n");
	sumTable(table, 3);
}