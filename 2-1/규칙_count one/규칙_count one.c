#include <stdio.h>
int main(void)
{
	int num, one = 0, cnt = 0;
	int i = 1;

	scanf("%d", &num);

	// // one�� 1, 11, 111, 1111, ���� num���� ����������,  cnt�� ����
	do {
		one += i;
		cnt++;
		i *= 10;
	} while (one % num != 0);

	printf("%d\n", cnt);
}