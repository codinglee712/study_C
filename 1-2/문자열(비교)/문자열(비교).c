#include <stdio.h>
#include <string.h>
#define SIZE 10
int main(void)
{
	char s1[SIZE] = "apple";
	char s2[SIZE] = "apple";
	char password[SIZE];

	if(s1 == s2)
		printf("same address\n"); // �� ���ڿ��� �ּҸ� ��

	if(strcmp(s1, s2) == 0)
		printf("same string\n"); // �� ���ڿ��� ������ ��

	printf("�н�����? ");
	scanf("%s", password);
	if(strcmp(password, "abcd1234") == 0) //���ڿ� ���ͷ��� ��
		printf("login succeeded\n");
	else
		printf("login failed\n");
}