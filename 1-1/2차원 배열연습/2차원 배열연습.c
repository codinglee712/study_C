#include <stdio.h>
int main(void)
{
	int test[4][3] = { {8, 7}, {6, 5}, {1, 2}, {3, 4}};
	int i, j;
	int total = 0;
	double average;
	int best;

	printf("배열 test의 엘리먼트를 출력합니다.\n");
	for(i = 0; i < 4; i++)
	{
		printf("%d번째 row: ", i + 1);
		for(j = 0; j < 3; j++)
			printf("%2d ", test[i][j]);
		printf("\n");
	}

	printf("다)\n");
	printf("배열 test의 엘리먼트를 출력합니다.\n");
	for(i = 0; i < 4; i++)
	{
		printf("%d번째 row: ", i + 1);
		for(j = 0; j < 3; j++)
		{
			test[i][2] = -1;
			printf("%2d ", test[i][j]);
		}
		printf("\n");
	}

	printf("라)\n");
	for(i = 0; i < 4; i++)
		for(j = 0; j < 3; j++)
			total += test[i][j];
	printf("Total is %d\n", total);
	average = (double)total / 12;
	printf("Average is %.2f\n", average);

	total = 0;
	printf("마)\n");
	for(i = 0; i < 4; i++)
	{
		best = 0;
		printf("%d번째 row에서의 최대값: ", i + 1);
		for(j = 0; j < 3; j++)
		{
			if(test[i][j] > best)
				best = test[i][j];
		}
		printf("%d\n", best);
		total += best;
	}
	printf("최대값의 함: %d", total);
}