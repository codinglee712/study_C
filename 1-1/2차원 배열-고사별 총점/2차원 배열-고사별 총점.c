#include <stdio.h>
int main(void)
{
	int grade[5][4] = {{10, 15, 20}, {30, 35, 20}, {60, 65, 20}, {90, 95, 20}, {0}};
	int i, j;

	printf("a)\n");
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
			printf("%4d", grade[i][j]);
		printf("\n");
	}

	printf("b)\n");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 4; j++)
			grade[4][i] += grade[j][i];

	for(i = 0; i < 4; i++)
		for(j = 0; j < 3; j++)
			grade[i][3] += grade[i][j];
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
			printf("%4d", grade[i][j]);
		printf("\n");
	}
}


	



			

