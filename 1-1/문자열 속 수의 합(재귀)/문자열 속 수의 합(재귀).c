#include <stdio.h>
#define SIZE 20
int sumWord(char *s)
{
	int total = 0;

	if(*s == '\0')
		return 0;
	else if(*s >= '0' && *s <= '9')//���ӵ� ���ڰ� �ƴ� ���� ������ ��
	{
		total = *s - '0';
		return total + sumWord(++s);
	}
	else
	{
		s++;
		return sumWord(s);
	}
}

int main(void)
{
	char word[SIZE];

	printf("Enter a word: ");
	scanf("%s", word);

	printf("���� ���� ���� ���� %d\n", sumWord(word));
}