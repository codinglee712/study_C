#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to)
{
	if(n == 1)
		printf("���� 1�� %c���� %c�� �ű��.\n", from, to); //���� ���� �����Ƿ� �����Ӱ� �̵� ����
	else {
		hanoi_tower(n-1, from, to, tmp); //B(�߰�)���� ������ �ű�
		printf("���� %d�� %c���� %c�� �ű��.\n", n, from, to);
		hanoi_tower(n-1, tmp, from, to); //B(�߰�)�� �ִ� ������ �ű�
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);

	hanoi_tower(n, 'A', 'B', 'C');
}