#include <stdio.h>
#define SIZE 81
int isPalindrome(char s[])
{
	int i, j;

	for(i = 0; s[i] != '\0'; i++);
		for(j = 0; j < i; j++)
			if(s[j] != s[i - j - 1])
				return 0;
	return 1;
}

int main(void)
{
	char str[SIZE];

	printf("* Palindrome üũ\n\n");
	printf("���ڿ� �Է�(���ڼ� %d ����): ",SIZE);
	scanf("%s", str);

	if(isPalindrome(str))
		printf("\"%s\" is a Palidrome\n\n", str);
	else
		printf("\"%s\" isn't a Palidrome\n\n", str);
}