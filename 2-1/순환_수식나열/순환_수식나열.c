#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k) //오름차순
{
	int lastIndex, i, smallest;
	int sum = 0;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++) {
			printf("%+d ", bucket[i] * (i + 1));
			sum += bucket[i] * (i + 1);
		}
		printf(" = %d\n", sum);
		return;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for(i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = items[i];
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}

int main(void)
{
	int n;
	int items[2] = {1, -1};
	int *bucket;

	scanf("%d", &n);

	bucket = (int*) malloc(sizeof(int) * n);

	pick(items, 2, bucket, n, n);
}