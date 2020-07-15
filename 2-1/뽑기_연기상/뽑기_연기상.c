#include <stdio.h>
#include <stdlib.h>
int chosen(int* bucket, int lastIndex, int item)
{
	int i;
	for(i = 0; i <= lastIndex; i++)
		if(bucket[i] == item)
			return 1;
	return 0;
}

void pick(char* items[], int itemsSize, int* bucket, int bucketSize, int k) //��������
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
	smallest = 0;

	for(i = smallest; i < itemsSize; i++) {
		if(!chosen(bucket, lastIndex, i)) {
			bucket[lastIndex + 1] = i;
			pick(items, itemsSize, bucket, bucketSize, k - 1);
		}
	}
}

void pick2(char* items[], int itemsSize, int* bucket, int bucketSize, int k) //��������
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
	largest = itemsSize - 1;

	for(i = largest; i >= 0; i--) {
		if(!chosen(bucket, lastIndex, i)) {
			bucket[lastIndex + 1] = i;
			pick2(items, itemsSize, bucket, bucketSize, k - 1);
		}
	}
}

int main(void)
{
	int n, i;
	char *items[] = {"����", "�����", "���߱�", "����", "����"};
	int *bucket;

	scanf("%d", &n);

	bucket = (int*) malloc(sizeof(int) * n);

	for(i = 1; i <= n; i++)
		printf("\t�� %d", i);
	printf("\n");

	printf("��������\n");
	pick(items, 5, bucket, n, n);
	printf("\n��������\n");
	pick2(items, 5, bucket, n, n);
}