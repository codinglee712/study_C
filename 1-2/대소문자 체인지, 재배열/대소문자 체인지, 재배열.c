#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char string[50];
	char alphaString1[50];
	char alphaString2[50];
	char digitString[50];
	char convertedString[50];
	int i;
	int alp = 0, dig = 0;

	printf("문자열을 입력하세요: ");
	gets(string);

	for(i = 0; string[i] != '\0'; i++) {
		if(isalpha(string[i]))
			alphaString1[alp++] = string[i];
		else if(isdigit(string[i]))
			digitString[dig++] = string[i];
	}
	alphaString1[alp] = '\0';
	digitString[dig] = '\0';

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);

	for(i = 0; alphaString1[i] != '\0'; i++) {
		if(isupper(alphaString1[i]))
			alphaString2[i] = tolower(alphaString1[i]);
		else if(islower(alphaString1[i]))
			alphaString2[i] = toupper(alphaString1[i]);
	}
	alphaString2[i] = '\0';

	strcpy(convertedString, alphaString1);
	strcat(convertedString, digitString);

	printf("대소문자를 바꾼 문자들은 %s\n", alphaString2);
	printf("문자들과 숫자들로 재배열한 문자열은 %s\n", convertedString);
}