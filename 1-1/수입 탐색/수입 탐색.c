#include <stdio.h>
int isKey(int incomes[], int k)
{
	int i;
	for(i = 0; i < 12; i++)
		if(incomes[i] == k)
			return i;
	return -1;
}
int main(void)
{
	int incomes[12] = {11, 22, 33, 44, 55, 66, 11, 22, 33, 44, 55, 66};
	int i, key;

	printf("Ž���� ������? ");
	scanf("%d", &key);

	if(isKey(incomes, key) == -1)
		printf("���� %d�� ���� ���� �����ϴ�\n", key);
	else
		printf("���� %d�� ���� ���� %d�� �Դϴ�\n", key, isKey(incomes, key)+1);			
}