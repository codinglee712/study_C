#include <stdio.h>
#include <string.h>
int main(void)
{
	char filename[] = "readme.txt";
	char *p = NULL;

	p = strchr(filename, '.'); //포인터의 위치를 '.'으로 변경
	if(p != NULL)
		printf("fil extension: %s\n", p+1); //'.'다음부터 출력

	p = strstr(filename, ".txt"); //확장자가 txt인지 확인
	if(p != NULL)
		printf("fil type: TEXT file\n");
}