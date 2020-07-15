#include <stdio.h>
#include <string.h>

// word의 뒷부분의 palindrome이 되는 substring의 크기를 반환
// 예1) 인수가 word는 abcb이고 left가 1이고 right는 3일 때 3 반환
// 예2) 인수가 word는 abc이고 left가 2이고 right는 2일 때 1 반환
// 예3) 인수가 word는 abcbmmb이고 left가 1이고 right가 6일때는 0 반환 
//                                  left가 3이고 right는 6일 때 4 반환
// 예4) 인수가 word는 aa이고 left가 0이고 right가 1일 때 2 반환
int calSameCount(char *word, int left, int right) 
{
	int cnt = 0;
	int size = (right - left) + 1;

	while(left <= right) {
		if(word[left++] == word[right--])
			cnt++;
		else
			return 0;
	}

	if(size % 2 == 0)
		return cnt * 2;
	else
		return cnt * 2 - 1;
}

int main(void)
{
	char word[80];
	int leftPoint, rightPoint;
	int sameCount;
	int len;
	int i, j;
	
	scanf("%s", word);
	
	len = strlen(word);
	leftPoint = 0;
	rightPoint = len - 1;

	while (leftPoint <= rightPoint) { // 문자열의 처음에서 뒤로 스캔하며 마지막 문자를 찾는다
		while (!(word[leftPoint] == word[rightPoint]))
			leftPoint++;

		// sameCount 계산
		sameCount = calSameCount(word, leftPoint, rightPoint);
		
		if (sameCount != 0) break;
		leftPoint++;
	}

	printf("sameCount는 %d\n", sameCount); // sameCount가 제대로 계산되었나 확인
	// word뒤에 문자를 붙인다.
	// 예: word가 abcdc라면 sameCount는 3으로 계산되었겠고
  	// 뒤에 ba를 붙여서 abcdcba
	for(i = 0; i < leftPoint; i++)
		word[len + i] = word[leftPoint - i - 1];
	word[len + i] = '\0';

	printf("%s\n", word);
}
