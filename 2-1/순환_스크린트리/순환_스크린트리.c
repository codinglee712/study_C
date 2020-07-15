#define MAX_LEVEL 5
#define MAX_WIDTH 70
#include <stdio.h>
int draw_tree(char s[][MAX_WIDTH], int row, int left, int right)
{
	int mid;
	int static count = 48; //�ƽ�Ű�ڵ� ���� '0'

	if(right - left < 2)
		return;
	else {
		mid = (left + right) / 2;
		s[row][mid] = ++count;
		draw_tree(s, row + 1, left, mid);
		draw_tree(s, row + 1, mid + 1, right); //row�� �� -> ���� ��ĭ�� ������
	}
}

void init(char s[][MAX_WIDTH]) //�迭 ä���
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width) //�迭 ���
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			printf(" %c", s[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char screen[MAX_LEVEL][MAX_WIDTH];
	int width;

	init(screen);

	printf("Enter a width(<= 70) of a screen:");
	scanf("%d", &width);

	draw_tree(screen, 0, 0, width - 1);

	display(screen, width);
}
