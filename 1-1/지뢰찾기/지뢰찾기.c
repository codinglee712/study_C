#include<stdio.h>

#define X_VALUE 5
#define Y_VALUE 5 

void readBombInfo(char grid[][Y_VALUE+1])//���� ��ġ, +1�� �ϴ� ������ NULL���� ����
{
	int i;
	
	printf("Input Grid\n");
	for(i = 0 ; i < X_VALUE; i++ )
		scanf( "%s", grid[i] ); 
}
void countBomb(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE])
{
	int i, j, k, w;
	
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++) 
			if (grid[i][j] == '*') 
			{
				if(i-1 >= 0)
				{
					numOfBombs[i-1][j]++;
					if(j-1 >= 0)
						numOfBombs[i-1][j-1]++;
					if(j+1 >= 0)
						numOfBombs[i-1][j+1]++;
				}
				if(i >= 0)
				{
					if(j-1 >= 0)
						numOfBombs[i][j-1]++;
					if(j+1 >= 0)
						numOfBombs[i][j+1]++;
				}
				if(i+1 >= 0)
				{
					numOfBombs[i+1][j]++;
					if(j-1 >= 0)
						numOfBombs[i+1][j-1]++;
					if(j+1 >= 0)
						numOfBombs[i+1][j+1]++;
				}
			}
}
void display_numOfBombs(char grid[][Y_VALUE+1], int numOfBombs[][Y_VALUE])
{				
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++) 
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char grid[X_VALUE][Y_VALUE+1]; 
	int numOfBombs[X_VALUE][Y_VALUE] = {0}; //������ ������ �ִ� ������ 5X5 �迭

	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);
}