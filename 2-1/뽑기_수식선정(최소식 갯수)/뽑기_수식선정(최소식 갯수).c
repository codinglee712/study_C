#include <stdio.h>
#include <stdlib.h>
int pick(int* items, int itemsSize, int* bucket, int bucketSize, int k, int target) //중복순열
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
	//최소 개수에 해당하는 수식들 전부
	for(i = smallest; i < itemsSize; i++) { 
			bucket[lastIndex + 1] = items[i];
			count += pick(items, itemsSize, bucket, bucketSize, k - 1, target); //둘 중 하나라도 참이면 true이므로 한번 true가 나오면 끝까지 true
		}

	return count; //i가 끝까지 for문을 돌았을 때 반환, true가 한번이라도 나오면 true로 반환
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

	for(i = 1; sum <= target; i++) //1부터 더한 값이 target 미만일 때는 구할 필요 없으므로 시작 index를 구함 
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