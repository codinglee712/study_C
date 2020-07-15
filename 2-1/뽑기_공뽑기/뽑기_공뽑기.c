#include <stdio.h>
#include <stdlib.h>
void pick(char* items, int itemsSize, int* bucket, int bucketSize, int k) //��������
{
	int lastIndex, i, smallest;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%c ", items[bucket[i]]);
		printf("\n");
		return;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for(i = smallest; i < itemsSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemsSize, bucket, bucketSize, k - 1);
	}
}

void pick2(char* items, int itemsSize, int* bucket, int bucketSize, int k) //��������
{
	int lastIndex, i, largest;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%c ", items[bucket[i]]);
		printf("\n");
		return;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		largest = itemsSize - 1;
	else
		largest = bucket[lastIndex] - 1;

	for(i = largest; i >= 0; i--) {
		bucket[lastIndex + 1] = i;
		pick2(items, itemsSize, bucket, bucketSize, k - 1);
	}
}

int main(void)
{
	int n;
	char items[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int *bucket;

	scanf("%d", &n);

	bucket = (int*) malloc(sizeof(int) * n);

	printf("��������\n");
	pick(items, 7, bucket, n, n);
	printf("\n��������\n");
	pick2(items, 7, bucket, n, n);
}