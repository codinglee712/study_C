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

	printf("���ڿ��� �Է��ϼ���: ");
	gets(string);

	for(i = 0; string[i] != '\0'; i++) {
		if(isalpha(string[i]))
			alphaString1[alp++] = string[i];
		else if(isdigit(string[i]))
			digitString[dig++] = string[i];
	}
	alphaString1[alp] = '\0';
	digitString[dig] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	for(i = 0; alphaString1[i] != '\0'; i++) {
		if(isupper(alphaString1[i]))
			alphaString2[i] = tolower(alphaString1[i]);
		else if(islower(alphaString1[i]))
			alphaString2[i] = toupper(alphaString1[i]);
	}
	alphaString2[i] = '\0';

	strcpy(convertedString, alphaString1);
	strcat(convertedString, digitString);

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}