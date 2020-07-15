#include <stdio.h>
#include <stdlib.h>
void pick(char* items[], int itemsSize, int* bucket, int bucketSize, int k) //오름차순
{
	int lastIndex, i, smallest;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%10s ", items[bucket[i]]);
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

void pick2(char* items[], int itemsSize, int* bucket, int bucketSize, int k) //내림차순
{
	int lastIndex, i, largest;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			printf("%10s ", items[bucket[i]]);
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
	char *items[] = {"공유", "김수현", "송중기", "지성", "현빈"};
	int *bucket;

	scanf("%d", &n);

	bucket = (int*) malloc(sizeof(int) * n);

	printf("오름차순\n");
	pick(items, 5, bucket, n, n);
	printf("\n내림차순\n");
	pick2(items, 5, bucket, n, n);
}