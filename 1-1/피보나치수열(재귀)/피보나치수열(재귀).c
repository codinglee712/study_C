#include <stdio.h>
int printFibo(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return printFibo(n - 1) + printFibo(n - 2);
}

int main(void)
{
	int num, i;

	printf("�� �ױ��� ����Ϸ��°�<3�̻��� ��>: ");
	scanf("%d", &num);

	for(i = 0; i < num; i++)
	{
		printf("%10d ", printFibo(i));
		if(i % 5 == 4)
			printf("\n");
	}
	printf("\n");
}