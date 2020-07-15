#include <stdio.h>
#define BOARD_SIZE 10

void display(char b[][BOARD_SIZE])
{
	char ch;
	int i, j;

	printf(" ");

	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);

	printf("\n ---------------------\n");

	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++) 
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

int winCheck(char b[][BOARD_SIZE], int r, int c)
{
	int i;
	int sum;
	char player = b[r][c];
	int ri, ci;

	sum = 1;
	ri = r, ci = c - 1;
	while(ci != -1 && b[ri][ci] == player) { //가로(오->왼)
		sum++;
		ci--;
		if(sum == 5)
			return 1;
	}

	ri = r, ci = c + 1;
	while(ci != BOARD_SIZE && b[ri][ci] == player) { //가로(왼->오)
		sum++;
		ci++;
		if(sum == 5)
			return 1;
	}
	
	sum = 0;
	ri = 0, ci = c;
	while(ri != BOARD_SIZE && b[ri][ci] == player) { //세로(위->아래)
		sum++;
		ri++;
		if(sum == 5)
			return 1;
	}

	sum = 0;
	if(r > c) 
		ri = r - c, ci = 0;
	else if(r == c)
		ri = 0, ci = 0;
	else
		ri = 0, ci = c - r; 
	while(ri != BOARD_SIZE && ci != BOARD_SIZE && b[ri][ci] == player) { //대각선(위->아래)
		sum++;
		ri++;
		ci++;
		if(sum == 5)
			return 1;
	}
	
	sum = 0;
	if((r + c) < BOARD_SIZE)
		ri = 0, ci = r + c;
	else
		ri = (r + c) - (BOARD_SIZE - 1), ci = BOARD_SIZE - 1;
	while(ri != BOARD_SIZE && ci != -1 && b[ri][ci] == player) { //역대각선(위->아래)
		sum++;
		ri++;
		ci--;
		if(sum == 5)
			return 1;
	}

	return 0;
}

void main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';
	int win = 0;
	int r, c;
	int i, j;
	int count;

	for(i = 0; i < BOARD_SIZE; i++ ) 
		for(j = 0 ; j < BOARD_SIZE; j++ ) 
			board[i][j] = ' ';

	count = 1;
	display(board);
	do 
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);

		if(board[r][c] != ' ')
			continue;
		
		board[r][c] = turn;
		display(board);

		if(win = winCheck(board, r, c)) {
			printf("Player %c wins!\n", turn);
			break;
		}
		turn = (turn == 'X' ? 'O' : 'X');
		count++;
	} while(count <=  BOARD_SIZE * BOARD_SIZE);

	if(!win && count == BOARD_SIZE * BOARD_SIZE)
		printf("Nobody wins!\n");
}