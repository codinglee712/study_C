#include <stdio.h>
#define SIZE 20
int sumWord(char *s)
{
	int total = 0;

	if(*s == '\0')
		return 0;
	else if(*s >= '0' && *s <= '9')//연속된 숫자가 아닌 숫자 각각의 합
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

	printf("글자 안의 수의 합은 %d\n", sumWord(word));
}