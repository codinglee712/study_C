#include <stdio.h>
#include <string.h>
int main(void)
{
	char phone[] = "02-123-4567";
	char *p = NULL;

	p = strtok(phone, "-"); //�����Ͱ� '02'���� 0�� ����Ŵ
	printf("area code: %s\n", p); //�����Ͱ� ����Ű�� �迭 ���
	p = strtok(NULL, "-");
	printf("prefix: %s\n", p);
	p = strtok(NULL, "-");
	printf("line number: %s\n", p);
}