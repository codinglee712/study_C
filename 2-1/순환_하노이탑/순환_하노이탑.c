#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to)
{
	if(n == 1)
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to); //제일 위에 있으므로 자유롭게 이동 가능
	else {
		hanoi_tower(n-1, from, to, tmp); //B(중간)으로 원판을 옮김
		printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n-1, tmp, from, to); //B(중간)에 있는 원판을 옮김
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);

	hanoi_tower(n, 'A', 'B', 'C');
}