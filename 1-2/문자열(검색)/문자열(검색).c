#include <stdio.h>
#include <string.h>
int main(void)
{
	char filename[] = "readme.txt";
	char *p = NULL;

	p = strchr(filename, '.'); //�������� ��ġ�� '.'���� ����
	if(p != NULL)
		printf("fil extension: %s\n", p+1); //'.'�������� ���

	p = strstr(filename, ".txt"); //Ȯ���ڰ� txt���� Ȯ��
	if(p != NULL)
		printf("fil type: TEXT file\n");
}