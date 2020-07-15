#include <stdio.h>
#include <ctype.h>
int solution(char *s)
{
    // 코드 정의
    while (*s)
    {
        if (isalpha(*s))
            return 0;
        s++;
    }
    return 1;
}
int main(void)
{
	char s[10];
	scanf("%s", s);

	printf("%d\n", solution(s));
}