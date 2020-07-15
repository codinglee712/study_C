#include <stdio.h>
int main(void)
{
	int data[8][9];
	int i, j;
	int num;

	printf("--구구단 표는 다음과 같습니다.\n");
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 9; j++)
		{
			data[i][j] = (i + 2) * (j + 1);
			printf("%3d ", data[i][j]);
		}
		printf("\n");
	}

	printf("--원하는 구구단은? ");
	scanf("%d", &num);

	for(j = 0; j < 9; j++)
		printf("%3d ", data[num-2][j]);
	printf("\n");
}

