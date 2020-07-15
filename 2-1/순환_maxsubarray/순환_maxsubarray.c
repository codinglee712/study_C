#include <stdio.h>
int right_max_sum(int A[], int left, int right)
{
	int i;
	int max = A[left];
	int sum = 0;

	for(i = left; i <= right; i++) {
		sum += A[i];
		if(max < sum)
			max = sum;
	}
	return max;
}

int left_max_sum(int A[], int left, int right)
{
	int i;
	int max = A[right];
	int sum = 0;

	for(i = right; i >= left; i--) {
		sum += A[i];
		if(max < sum)
			max = sum;
	}
	return max;
}

int max_subarray(int A[], int left, int right)
{
	int v1 = 0, v2 = 0, v3 = 0;
	int mid;

	if(left == right)
		return A[left];
	else {
		mid = (left + right) / 2;
		v1 = max_subarray(A, left, mid);
		v2 = max_subarray(A, mid + 1, right);
		v3 = left_max_sum(A, left, mid) + right_max_sum(A, mid + 1, right);

		return (v1 < v2) ? ((v2 < v3) ? v3 : v2) : ((v1 < v3) ? v3 : v1);
	}
}

int main(void)
{
	//int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // tc #1: max는 6
	//int A[] = {2, -1, 5, -2, 2, -3, 1}; // tc #2: max는 6
	//int A[] = {3, -1, 1, 2, 3, 1, -1, 5}; // tc #3: max는 13
	//int A[] = {1, 2, 3}; // tc #4: max는 6
	int A[] = {-1, -2, -3, -4}; //tc #5: max는 -1
	//int A[] = {5}; // tc #6: max는 5
	int lastIndex = sizeof(A) / sizeof(int) - 1;
	int max = max_subarray(A, 0, lastIndex);
	printf("max value = %d\n", max );
}