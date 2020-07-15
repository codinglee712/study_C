#include <stdio.h>
int mergeString(char c[], char a[], char b[])
{
	int i;
	int len1 = 0, len2 = 0;
	int aId = 0, bId = 0;

	for(i = 0 ; a[i] != '\0'; i++);
	len1 = i;

	for(i = 0; b[i] != '\0'; i++);
	len2 = i;

	for(i = 0; i < len1 + len2 + 1; i++)
	{
		if(i == len1 + len2 + 1)//끝은 NULL문자
			c[i] ='\0';
		else if(aId == len1)//비교하려는 인덱스와 길이가 같으면
			c[i] = b[bId++];//인덱스에 해당하는 원소 값 추가
		else if(bId == len2)
			c[i] = a[aId++];
		else if(a[aId] >= b[bId])//배열의 값이 작으면
			c[i] = b[bId++];//작은 쪽의 원소 값 추가
		else if(a[aId] < b[bId])
			c[i] = a[aId++];
	}
}

int main(void)
{
	char word1[10], word2[10];
	char mergeWord[20];

	scanf("%s", word1);
	scanf("%s", word2);
	mergeString(mergeWord, word1, word2);
	printf("%s\n", mergeWord);
}