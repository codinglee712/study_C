#define NUM_OF_MEMBERS 15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void init_links(int data[][NUM_OF_MEMBERS])//�ʱ� 1�� ����
{
	int i, j;

	for(i = 0; i < NUM_OF_MEMBERS; i++)
		data[i][i] = 1; //i�� i�� ����� 1��

	for(i = 0; i < NUM_OF_MEMBERS; i++)
	{
		j = 0;
		while(j < 2)//j�� 0 �Ǵ� 1 �϶�
		{
			int new_link = rand() % NUM_OF_MEMBERS;
			if(new_link != i)//i�� �� ���� ��ũ�� �����ϰ� i�� �ƴ� �ٸ� user�� i�� ����
			{
				data[i][new_link] = 1;//i�� new_link�� 1���̸�
				data[new_link][i] = 1;//new_link�� i�� 1��
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

	printf("�ʱ� 1�� ����:\n");
	print_links(link_data);
	
	matrix_copy(link_data2, link_data);

	while(1)
	{
		num_of_steps++;//�� �ܰ辿 ����

		matrix_multiplication(link_data, link_data2, link_result);

		printf("\n%d steps:\n", num_of_steps);
		print_links(link_result);

		ALL_ONES = check_links(link_result);
		if(ALL_ONES)
			break;

		matrix_copy(link_data2, link_result);// ������� link_data2�� �־�� �ٽ� link_data�� ����� �� �ִ�
	}
	printf("It takes %d steps.\n", num_of_steps);
}
