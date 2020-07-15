#include <stdio.h>
void split(char s[], char s1[], char s2[])
{
	int i;
	int p1 = 0, p2 = 0;

	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			s1[p1] = s[i];
			p1++;
		}
		else if(s[i] >= 'A' && s[i] <= 'Z'|| s[i] >= 'a' && s[i] <= 'z')
		{
			s2[p2] = s[i];
			p2++;
		}
	}
	s1[p1] = '\0';
	s2[p2] = '\0';
}

int main(void)
{
	char str[20];
	char str1[20], str2[20];
	int i;
    
    printf("Enter a word: ");
	scanf("%s", str);

	split(str, str1, str2);
    
	printf("%s\n", str1);
	printf("%s\n", str2);
}