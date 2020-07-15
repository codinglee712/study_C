#include <stdio.h>
int max1(int list[], int low, int high)
{
	int max = -1;

	while(low <= high) {
		if(list[low] > max)
			max = list[low]; //여기서 ++하면 안됨..
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
		left = max2(list, low, mid); //mid를 가지고 구하는게 아니고 경계구분하는 용도이므로 포함시켜야 함 
		right = max2(list, mid + 1, high);
		return (left > right ? left : right);
	}
}
int main(void) 
{
	int list[] = {10, 20, 100, 4, 5, 45, 3, 99, 11, 22};

	printf("가장 큰 수는 %d\n", max1(list, 0, 9));
	printf("가장 큰 수는 %d\n", max2(list, 0, 9));

	printf("가장 큰 수는 %d\n", max1(list, 5, 9));
	printf("가장 큰 수는 %d\n", max2(list, 5, 9));

	printf("가장 큰 수는 %d\n", max1(list, 3, 6));
	printf("가장 큰 수는 %d\n", max2(list, 3, 6));
}