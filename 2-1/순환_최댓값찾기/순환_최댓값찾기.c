#include <stdio.h>
int max1(int list[], int low, int high)
{
	int max = -1;

	while(low <= high) {
		if(list[low] > max)
			max = list[low]; //���⼭ ++�ϸ� �ȵ�..
		low++;
	}
	return max;
}

int max2(int list[], int low, int high)
{
	int mid;
	int left, right;

	if(low == high)
		return list[low];
	else {
		mid = (low + high) / 2;
		left = max2(list, low, mid); //mid�� ������ ���ϴ°� �ƴϰ� ��豸���ϴ� �뵵�̹Ƿ� ���Խ��Ѿ� �� 
		right = max2(list, mid + 1, high);
		return (left > right ? left : right);
	}
}
int main(void) 
{
	int list[] = {10, 20, 100, 4, 5, 45, 3, 99, 11, 22};

	printf("���� ū ���� %d\n", max1(list, 0, 9));
	printf("���� ū ���� %d\n", max2(list, 0, 9));

	printf("���� ū ���� %d\n", max1(list, 5, 9));
	printf("���� ū ���� %d\n", max2(list, 5, 9));

	printf("���� ū ���� %d\n", max1(list, 3, 6));
	printf("���� ū ���� %d\n", max2(list, 3, 6));
}