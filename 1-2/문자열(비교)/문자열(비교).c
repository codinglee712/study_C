#include <stdio.h>
#include <string.h>
#define SIZE 10
int main(void)
{
	char s1[SIZE] = "apple";
	char s2[SIZE] = "apple";
	char password[SIZE];

	if(s1 == s2)
		printf("same address\n"); // 두 문자열의 주소를 비교

	if(strcmp(s1, s2) == 0)
		printf("same string\n"); // 두 문자열의 내용을 비교

	printf("패스워드? ");
	scanf("%s", password);
	if(strcmp(password, "abcd1234") == 0) //문자열 리터럴과 비교
		printf("login succeeded\n");
	else
		printf("login failed\n");
}