#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int money) //bucket�� �ε����� ����
{
	int lastIndex, i, smallest;
	int sum = 0;
	int count = 0;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];

		if(sum == money) {
			for(i = 0; i < bucketSize; i++)
				if(bucket[i] != 0)
					printf("%d ",items[bucket[i]]);
			printf("\n");
			return 1;
		}
		return 0;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for(i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		count += pick(items, itemSize, bucket, bucketSize, k - 1, money);
	}

	return count;
}

int pick2(int* items, int itemSize, int* bucket, int bucketSize, int k, int money) //bucket�� ���� ����
{
	int lastIndex, i, smallest;
	int sum = 0;
	int count = 0;

	//Trivial Case
	if(k == 0) { 
		for(i = 0; i < bucketSize; i++)
			sum += bucket[i];

		if(sum == money) {
			for(i = 0; i < bucketSize; i++)
				if(bucket[i] != 0)
					printf("%d ",bucket[i]);
			printf("\n");
			return 1;
		}
		return 0;
	}

	//Recursive Case
	lastIndex = bucketSize - k - 1;

	if(k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; //������ �� ��

	for(i = 0; i < itemSize; i++) {
		if(smallest <= items[i]) { //������ �� ���� items�� i�ε��� ������ �۰ų� ���� ��
			bucket[lastIndex + 1] = items[i];
			count += pick2(items, itemSize, bucket, bucketSize, k - 1, money);
		}
	}

	return count;
}

int pick3(int* items, int itemSize, int* bucket, int bucketSize, int k, int money) //bucket�� ���� ����
{
	int lastIndex, i, smallest;
	int sum = 0;
	int count = 0;

	lastIndex = bucketSize - k - 1;

	for(i = 0; i <= lastIndex; i++)
			sum += bucket[i];

	if(money == sum) { 
		for(i = 0; i <= lastIndex; i++)
			printf("%d ",bucket[i]);
		printf("\n");
		return 1;
	}
	else if(money < sum) //sum�� money�� ���� ��� �� �̻� �� �ʿ����
		return 0;

	if(k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; //������ �� ��

	for(i = 0; i < itemSize; i++) {
		if(smallest <= items[i]) { //������ �� ���� items�� i�ε��� ������ �۰ų� ���� ��
			bucket[lastIndex + 1] = items[i];
			count += pick3(items, itemSize, bucket, bucketSize, k - 1, money);
		}
	}

	return count;
}

int main(void)
{
	int money, n;
	//int items[4] = {0, 1000, 5000, 10000};
	int items[3] = {1000, 5000, 10000};
	int *bucket;

	scanf("%d", &money);

	n = money / 1000;
	bucket = (int*) malloc(sizeof(int) * n);

	//printf("%d\n", pick(items, 4, bucket, n, n, money));
	//printf("%d\n", pick2(items, 4, bucket, n, n, money));
	printf("%d\n", pick3(items, 3, bucket, n, n, money));
}