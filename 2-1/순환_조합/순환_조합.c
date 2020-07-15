#include <stdio.h>
#include <stdlib.h>
int pick(int n, int* bucket, int bucketSize, int k) //오름차순
{
	int lastIndex, i, smallest;
	int count = 0;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return 1;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for(i = smallest; i < n; i++) {
		bucket[lastIndex + 1] = i;
		count += pick(n, bucket, bucketSize, k - 1);
	}
	return count;
}

int pick2(int n, int* bucket, int bucketSize, int k) //내림차순
{
	int lastIndex, i, largest;
	int count = 0;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return 1;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		largest = n - 1;
	else
		largest = bucket[lastIndex] - 1;

	for(i = largest; i >= 0; i--) {
		bucket[lastIndex + 1] = i;
		count += pick2(n, bucket, bucketSize, k - 1);
	}
	return count;
}

int main(void)
{
	int n, m;
	int *bucket;

	scanf("%d %d", &n, &m);

	bucket = (int*) malloc(sizeof(int) * m);

	printf("오름차순\n");
	printf("%d\n", pick(n, bucket, m, m));
	printf("\n내림차순\n");
	printf("%d\n", pick2(n, bucket, m, m));
}