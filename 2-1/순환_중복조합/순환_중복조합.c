#include <stdio.h>
#include <stdlib.h>
void pick(int n, int* bucket, int bucketSize, int k) //��������
{
	int lastIndex, i, smallest;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for(i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, k - 1);
	}
}

void pick2(int n, int* bucket, int bucketSize, int k) //��������
{
	int lastIndex, i, largest;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		largest = n - 1;
	else
		largest = bucket[lastIndex];

	for(i = largest; i >= 0; i--) {
		bucket[lastIndex + 1] = i;
		pick2(n, bucket, bucketSize, k - 1);
	}
}

int main(void)
{
	int n, m;
	int *bucket;

	scanf("%d %d", &n, &m);

	bucket = (int*) malloc(sizeof(int) * m);

	printf("��������\n");
	pick(n, bucket, m, m);
	printf("\n��������\n");
	pick2(n, bucket, m, m);
}