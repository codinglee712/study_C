#include <stdio.h>
#define SIZE 50
int main(void)
{
	char str[SIZE];
	char newStr[SIZE];
	int i;
	int j = 0;

	printf("Enter one word: ");
	scanf("%s", str);

	for(i = 0; str[i] != '\0'; i++)
		if(str[i] >= 'A' && str[i] <= 'Z')
			newStr[j++] = str[i];
	newStr[j] = '\0';

	printf("%s\n", newStr);
}