#include <stdio.h>
#include <string.h>
#define SIZE 32
void swap(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char temp[SIZE];

	if(len1 + 1 <= SIZE || len2 + 1 <= SIZE) {
		strcpy(temp, s1);
		strcpy(s1, s2);
		strcpy(s2, temp);
	}
}

int main(void)
{
	char str1[SIZE] = "";
	char str2[SIZE] = "";

	printf("2개의 문자열? ");
	scanf("%s %s", str1, str2);
	printf("str1 = %s, str2 = %s\n", str1, str2);

	swap(str1, str2);
	printf("str1 = %s, str2 = %s\n", str1, str2);
}