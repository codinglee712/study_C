#include <stdio.h>
int main(void)
{
	int test[4][3] = { {8, 7}, {6, 5}, {1, 2}, {3, 4}};
	int i, j;
	int total = 0;
	double average;
	int best;

	printf("�迭 test�� ������Ʈ�� ����մϴ�.\n");
	for(i = 0; i < 4; i++)
	{
		printf("%d��° row: ", i + 1);
		for(j = 0; j < 3; j++)
			printf("%2d ", test[i][j]);
		printf("\n");
	}

	printf("��)\n");
	printf("�迭 test�� ������Ʈ�� ����մϴ�.\n");
	for(i = 0; i < 4; i++)
	{
		printf("%d��° row: ", i + 1);
		for(j = 0; j < 3; j++)
		{
			test[i][2] = -1;
			printf("%2d ", test[i][j]);
		}
		printf("\n");
	}

	printf("��)\n");
	for(i = 0; i < 4; i++)
		for(j = 0; j < 3; j++)
			total += test[i][j];
	printf("Total is %d\n", total);
	average = (double)total / 12;
	printf("Average is %.2f\n", average);

	total = 0;
	printf("��)\n");
	for(i = 0; i < 4; i++)
	{
		best = 0;
		printf("%d��° row������ �ִ밪: ", i + 1);
		for(j = 0; j < 3; j++)
		{
			if(test[i][j] > best)
				best = test[i][j];
		}
		printf("%d\n", best);
		total += best;
	}
	printf("�ִ밪�� ��: %d", total);
}