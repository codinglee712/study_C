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
		if(i == len1 + len2 + 1)//���� NULL����
			c[i] ='\0';
		else if(aId == len1)//���Ϸ��� �ε����� ���̰� ������
			c[i] = b[bId++];//�ε����� �ش��ϴ� ���� �� �߰�
		else if(bId == len2)
			c[i] = a[aId++];
		else if(a[aId] >= b[bId])//�迭�� ���� ������
			c[i] = b[bId++];//���� ���� ���� �� �߰�
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