#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int pick(int* items, int itemsSize, int* bucket, int bucketSize, int k, int target) //중복순열
{
	int smallest, lastIndex, i;
	int sum = 0;
	int found = FALSE;
	
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
			return TRUE;
		}
		return FALSE;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	/*
		//최소 개수의 수식중 하나
		for(i = smallest; i < itemsSize && !found; i++) { //i가 itemsSize를 넘지 않거나 found가 FALSE일때
			bucket[lastIndex + 1] = items[i];
			found = pick(items, itemsSize, bucket, bucketSize, k - 1, target);
		}
		return found; //i가 끝까지 for문을 돌았거나, found가 TRUE일 때 반환
	*/

	//최소 개수에 해당하는 수식들 전부
	for(i = smallest; i < itemsSize; i++) { 
			bucket[lastIndex + 1] = items[i];
			found = pick(items, itemsSize, bucket, bucketSize, k - 1, target) || found; //둘 중 하나라도 참이면 true이므로 한번 true가 나오면 끝까지 true
		}

	return found; //i가 끝까지 for문을 돌았을 때 반환, true가 한번이라도 나오면 true로 반환
}

int main(void)
{
	int target, i;
	int *bucket;
	int items[2] = {1, -1};
	int found = 0;
	int sum = 0;
	int minBucketSize;

	scanf("%d", &target);

	bucket = (int*) malloc(sizeof(int*) * target);

	for(i = 1; sum <= target; i++) //1부터 더한 값이 target 미만일 때는 구할 필요 없으므로 시작 index를 구함 
		sum += i;
	minBucketSize = i - 2;

	for(i = minBucketSize; !found; i++)//found가 true일 때 벗어남
		found = pick(items ,2, bucket, i, i, target); 

	free(bucket);
}