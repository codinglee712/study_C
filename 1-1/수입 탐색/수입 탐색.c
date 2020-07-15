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

	printf("탐색할 수입은? ");
	scanf("%d", &key);

	if(isKey(incomes, key) == -1)
		printf("수입 %d를 갖는 달은 없습니다\n", key);
	else
		printf("수입 %d를 갖는 달은 %d월 입니다\n", key, isKey(incomes, key)+1);			
}