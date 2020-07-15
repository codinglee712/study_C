#include <stdio.h>
void split(char *s, char *s1, char *s2)
{
	while(*s)
	{
		if(*s >= '0' && *s <= '9')
			*s1++ = *s;
		else if(*s >= 'A' && *s <= 'Z'|| *s >= 'a' && *s <= 'z')
			*s2++ = *s;
		*s++;
	}
	*s1 = '\0';
	*s2 = '\0';
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