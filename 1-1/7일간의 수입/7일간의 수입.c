#include <stdio.h>
int main(void)
{
	int incomes[7];
	int size = sizeof(incomes) / sizeof(incomes[0]);
	int i;
	int best = 0, bestIndex = 0;
	int total = 0;
	double average;

	for(i = 0; i < size; i++)
	{
		printf("Enter the income of day %d: ", i+1);
		scanf("%d", &incomes[i]);
	}

	printf("----------------------------------------------------\n");

	for(i = 0; i < size; i++)
		if(incomes[i] > best)
		{
			best = incomes[i];
			bestIndex = i+1;
		}
	printf("The best income: %d in day %d\n", best, bestIndex);

	printf("----------------------------------------------------\n");

	for(i = 0; i < size; i++)
		total += incomes[i];
	average = (double) total / size;
	printf("The total is %d\n", total);
	printf("The average is %.1f\n", average);

	printf("The good days and their incomes are\n");

	for(i = 0; i < size; i++)
		if(incomes[i] > average)
			printf("day %d: %d\n", i+1, incomes[i]);
}