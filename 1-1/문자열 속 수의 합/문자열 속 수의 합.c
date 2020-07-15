#include <stdio.h>
#define SIZE 20
int sumWord(char w[])
{
	int i;
	int sum = 0;
	int num = 0;

	for(i = 0; w[i] != '\0'; i++)
	{
		if(w[i] >= '0' && w[i] <= '9')
			num = num * 10 + w[i] - '0';
		else
		{
			sum += num;
			num = 0;
		}
	}
	sum += num;

	return sum;
}

int main(void)
{
	char word[SIZE];

	printf("Enter a word: ");
	scanf("%s", word);

	printf("글자 안의 수의 합은 %d\n", sumWord(word));
}