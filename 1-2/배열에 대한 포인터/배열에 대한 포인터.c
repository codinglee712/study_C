#include <stdio.h>
int main(void)
{
	int data[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
	int (*p)[5] = data; //data전체의 주소를 가리킴
	int i, j;

	for(i = 0; i < 3; i++) {
		for(j = 0; j < 5; j++) 
			printf("%2d ", p[i][j]); //포인터 배열처럼 쓰임
		printf("\n");
	}
}
