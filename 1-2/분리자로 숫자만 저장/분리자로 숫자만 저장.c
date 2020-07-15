#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int solution(char *s)
{
   while (*s)
    {
        if (isalpha(*s))
            return 0;
        s++;
    }
    return 1; // A-1에서 정의한 함수 solution의 내용을 여기에
}

int main(void)
{
    char sentence[50]; // 총 49이하의 문자들로 문장 구성
    char delimiters[] = " ,\n\0"; // 네 개의 분리 문자들(공백,콤마,줄바꿈,널문자) 지정한다
    char *token;
    int i = 0;

    gets(sentence);

    token = strtok(sentence, delimiters);
    while (token != NULL)
	{
		if(solution(token)) {
			while(*token) {
				sentence[i++] = *token;
				token++;
			}
		}
		token = strtok(NULL, delimiters);
	}
	sentence[i] = '\0';

	puts(sentence);
}