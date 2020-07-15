#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "hello";
	char s2[] = "";
	int len = 0;

	printf("s1의 길이: %d\n", strlen(s1)); //널 문자 제외한 <문자열의 길이>
	printf("s2의 길이: %d\n", strlen(s2)); //널 문자열의 길이->0
	printf("s3의 길이: %d\n", strlen("bye bye")); //문자열 리터럴의 길이
	printf("s1의 크기: %d\n", sizeof(s1)); //널 문자 포함한 <배열의 크기>

	len = strlen(s1);
	if(len > 0)
		s1[len - 1] = '\0'; //마지막 한 글자 삭제
	printf("s1 = %s\n", s1);
}
