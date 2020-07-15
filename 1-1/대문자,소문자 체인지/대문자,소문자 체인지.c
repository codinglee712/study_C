#define SIZE 80
#include <stdio.h>
int main(void)
{
	char word[SIZE];
	char newWord[SIZE];
	int i;

	printf("Enter one word: ");
	scanf("%s", word);

	for(i = 0; word[i] != '\0'; i++)
	{
		if(word[i] >= 'a' && word[i] <= 'z')
			newWord[i] = word[i] - 32;
		else if(word[i] >= 'A' && word[i] <= 'Z')
			newWord[i] = word[i] + 32;
		else
			newWord[i] = word[i];
	}
	newWord[i] = '\0';

	printf("word given: %s\n", word);
	printf("new word: %s\n", newWord);
}