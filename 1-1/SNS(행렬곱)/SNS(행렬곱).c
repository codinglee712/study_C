#define NUM_OF_MEMBERS 15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void init_links(int data[][NUM_OF_MEMBERS])//초기 1촌 상태
{
	int i, j;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
		data[i][i] = 1; //i와 i의 관계는 1촌

	for(i = 0; i < NUM_OF_MEMBERS; i++)
	{
		j = 0;
		while(j < 2)//j가 0 또는 1 일때
		{
			int new_link = rand() % NUM_OF_MEMBERS;
			if(new_link != i)//i가 두 개의 링크를 연결하고 i가 아닌 다른 user가 i와 연결
			{
				data[i][new_link] = 1;//i와 new_link가 1촌이면
				data[new_link][i] = 1;//new_link와 i도 1촌
				j++;
			}
		}
	}
}

void print_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
	{
		for(j = 0; j < NUM_OF_MEMBERS; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
}

void matrix_multiplication(int data[][NUM_OF_MEMBERS], int data2[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS])
{
	int i, j, k;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
		for(j = 0; j < NUM_OF_MEMBERS; j++)
			for(k = 0; k < NUM_OF_MEMBERS; k++)
				if(data[i][k] * data2[k][j] != 0)
					result[i][j] = 1;
}

void matrix_copy(int dest[][NUM_OF_MEMBERS], int src[][NUM_OF_MEMBERS])
{
	int i, j;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
		for(j = 0; j < NUM_OF_MEMBERS; j++)
			dest[i][j] = src[i][j];
}

int check_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
		for(j = 0; j < NUM_OF_MEMBERS; j++)
			if(data[i][j] == 0)
				return 0;
	return 1;
}

int main(void)
{
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};
	int link_data2[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = {0};

	int num_of_steps = 0;
	int ALL_ONES = 0;

	//srand((unsingned int)time(NULL));
	srand(100);

	init_links(link_data);

	printf("초기 1촌 상태:\n");
	print_links(link_data);
	
	matrix_copy(link_data2, link_data);

	while(1)
	{
		num_of_steps++;//한 단계씩 증가

		matrix_multiplication(link_data, link_data2, link_result);

		printf("\n%d steps:\n", num_of_steps);
		print_links(link_result);

		ALL_ONES = check_links(link_result);
		if(ALL_ONES)
			break;

		matrix_copy(link_data2, link_result);// 결과값을 link_data2에 넣어야 다시 link_data와 계산할 수 있다
	}
	printf("It takes %d steps.\n", num_of_steps);
}
