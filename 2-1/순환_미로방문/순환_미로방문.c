#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10
int screen[WIDTH][HEIGHT] = {
	0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
	-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
	-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
	-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
	-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
	-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
	-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
	-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};

 int flood_fill(int x, int y)
 {
	 int static count = 0;

	 if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
		 if(screen[x][y] == 0) {
			 screen[x][y] = ++count;

			 flood_fill(x, y + 1); //오른쪽, 3시방향
			 flood_fill(x + 1, y); //아래쪽, 6시방향
			 flood_fill(x, y - 1); //왼쪽, 9시방향
			 flood_fill(x - 1, y); //위쪽, 12시방향
		 }
	 }
 }

 void display()
 {
	 int i, j;
	 for(i = 0; i < WIDTH; i++) {
		 for(j = 0; j < HEIGHT; j++) 
			 printf("%3d", screen[i][j]);
		 printf("\n");
	 }
	 printf("\n");
 }

 int main(void)
 {
	 int x, y;	scanf("%d %d", &x, &y);	display();	flood_fill(x, y);	display();
 }