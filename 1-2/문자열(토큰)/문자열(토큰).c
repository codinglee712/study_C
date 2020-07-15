#include <stdio.h>
#include <string.h>
int main(void)
{
	char phone[] = "02-123-4567";
	char *p = NULL;

	p = strtok(phone, "-"); //포인터가 '02'에서 0을 가리킴
	printf("area code: %s\n", p); //포인터가 가리키는 배열 출력
	p = strtok(NULL, "-");
	printf("prefix: %s\n", p);
	p = strtok(NULL, "-");
	printf("line number: %s\n", p);
}