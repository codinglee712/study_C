#include <stdio.h>
#include <string.h>

// word�� �޺κ��� palindrome�� �Ǵ� substring�� ũ�⸦ ��ȯ
// ��1) �μ��� word�� abcb�̰� left�� 1�̰� right�� 3�� �� 3 ��ȯ
// ��2) �μ��� word�� abc�̰� left�� 2�̰� right�� 2�� �� 1 ��ȯ
// ��3) �μ��� word�� abcbmmb�̰� left�� 1�̰� right�� 6�϶��� 0 ��ȯ 
//                                  left�� 3�̰� right�� 6�� �� 4 ��ȯ
// ��4) �μ��� word�� aa�̰� left�� 0�̰� right�� 1�� �� 2 ��ȯ
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

	while (leftPoint <= rightPoint) { // ���ڿ��� ó������ �ڷ� ��ĵ�ϸ� ������ ���ڸ� ã�´�
		while (!(word[leftPoint] == word[rightPoint]))
			leftPoint++;

		// sameCount ���
		sameCount = calSameCount(word, leftPoint, rightPoint);
		
		if (sameCount != 0) break;
		leftPoint++;
	}

	printf("sameCount�� %d\n", sameCount); // sameCount�� ����� ���Ǿ��� Ȯ��
	// word�ڿ� ���ڸ� ���δ�.
	// ��: word�� abcdc��� sameCount�� 3���� ���Ǿ��ڰ�
  	// �ڿ� ba�� �ٿ��� abcdcba
	for(i = 0; i < leftPoint; i++)
		word[len + i] = word[leftPoint - i - 1];
	word[len + i] = '\0';

	printf("%s\n", word);
}
