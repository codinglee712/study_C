#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemsSize, int* bucket, int bucketSize, int k, int target) //�ߺ�����
{
	int smallest, lastIndex, i;
	int sum = 0;
	int count = 0;
	
	if(k == 0) {
		for(i = 0; i < bucketSize; i++) 
			sum += bucket[i] * (i + 1);
		if(sum == target) {
			for(i = 0; i < bucketSize; i++) {
				if(bucket[i] == 1)
					printf(" + %d", i + 1);
				else
					printf(" - %d", i + 1);
			}
			printf(" = %d\n", sum);
			return 1;
		}
		return 0;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;
	//�ּ� ������ �ش��ϴ� ���ĵ� ����
	for(i = smallest; i < itemsSize; i++) { 
			bucket[lastIndex + 1] = items[i];
			count += pick(items, itemsSize, bucket, bucketSize, k - 1, target); //�� �� �ϳ��� ���̸� true�̹Ƿ� �ѹ� true�� ������ ������ true
		}

	return count; //i�� ������ for���� ������ �� ��ȯ, true�� �ѹ��̶� ������ true�� ��ȯ
}

int main(void)
{
	int target, i;
	int *bucket;
	int items[2] = {1, -1};
	int found = 0;
	int sum = 0;
	int cnt = 0;
	int minBucketSize;

	scanf("%d", &target);

	bucket = (int*) malloc(sizeof(int*) * target);

	for(i = 1; sum <= target; i++) //1���� ���� ���� target �̸��� ���� ���� �ʿ� �����Ƿ� ���� index�� ���� 
		sum += i;
	minBucketSize = i - 2;

	i = minBucketSize;
	while(cnt == 0) { 
		cnt = pick(items ,2, bucket, i, i, target); 
		i++;
	}
	printf("%d\n", cnt);

	free(bucket);
}