#include <stdio.h>
#include <string.h> //���ڿ� ó�� �Լ��� ���
#include <stdlib.h> // atoi�Լ��� ���
int main(void)
{
	char str1[15] = "ABCDED";
	char str2[15] = "abcde";
	char str3[15] = "1234";
	int n;

	char s[] = "Life is short,but art is long";
	char delimiters[] = " ,\n\0"; //��ū�и��� ����
	char *token; //������

	printf("��)str1�� ���� = %d\n", strlen(str1)); //6
	printf("   str2�� ���� = %d\n", strlen(str2)); //5

	strcpy(str1, str2); //str2->str1
	printf("��)str1 = %s\t\tstr2 = %s\n", str1, str2); //abcde, abcde

	strncpy(str1, str3, 2); //str3�� 1,2->str1
	printf("��)str1 = %s\t\tstr3 = %s\n", str1, str3); //12cde('\0'�� �־����� ����), 1234

	strcat(str1, str2); // str1+str2
	printf("��)str1 = %s\t\tstr2 = %s\n", str1, str2); //12cdeabcde, abcde

	strncat(str1, str3, 2); //str1+str3
	printf("��)str1 = %s\t\tstr3 = %s\n", str1, str3); //12cdeabcd12('\0'�� �ڵ����� �־���), 1234

	printf("��)%d %d %d\n", strcmp("aaa", "abc"), strcmp("aaa", "aaa"), strcmp("ddd", "ccc")); //-1, 0, 1

	strcpy(str1, "111"); //111->str1(�̶�, '\0'�� �ڵ������ǹǷ� ���� �ִ� ���ڵ��� '\0'�� �������� ���ŵ�
	n = atoi(str1) * 7; //111�� ���������� �ٲ� �� 7�� ����
	printf("��)str1�� 7�� �� ���� %d\n", n); //777

	printf("��)\n");
	n = 1;
	token = strtok(s, delimiters); //ù ������ �迭�̸�
	while(token != NULL) {
		printf("%d��° ��ū�� %s\n", n++, token);
		token = strtok(NULL, delimiters); //�� �ڷδ� NULL�� ����� �� ����
	}
}

