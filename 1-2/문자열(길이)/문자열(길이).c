#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "hello";
	char s2[] = "";
	int len = 0;

	printf("s1�� ����: %d\n", strlen(s1)); //�� ���� ������ <���ڿ��� ����>
	printf("s2�� ����: %d\n", strlen(s2)); //�� ���ڿ��� ����->0
	printf("s3�� ����: %d\n", strlen("bye bye")); //���ڿ� ���ͷ��� ����
	printf("s1�� ũ��: %d\n", sizeof(s1)); //�� ���� ������ <�迭�� ũ��>

	len = strlen(s1);
	if(len > 0)
		s1[len - 1] = '\0'; //������ �� ���� ����
	printf("s1 = %s\n", s1);
}
