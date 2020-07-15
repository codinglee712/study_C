#define MAX_LEVEL 5
#define MAX_WIDTH 70
#include <stdio.h>
int draw_tree(char s[][MAX_WIDTH], int row, int left, int right)
{
	int mid;
	int static count = 48; //아스키코드 문자 '0'

	if(right - left < 2)
		return;
	else {
		mid = (left + right) / 2;
		s[row][mid] = ++count;
		draw_tree(s, row + 1, left, mid);
		draw_tree(s, row + 1, mid + 1, right); //row는 행 -> 행이 한칸씩 내려감
	}
}

void init(char s[][MAX_WIDTH]) //배열 채우기
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width) //배열 출력
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
