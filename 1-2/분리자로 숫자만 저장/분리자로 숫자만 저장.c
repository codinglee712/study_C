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
    return 1; // A-1���� ������ �Լ� solution�� ������ ���⿡
}

int main(void)
{
    char sentence[50]; // �� 49������ ���ڵ�� ���� ����
    char delimiters[] = " ,\n\0"; // �� ���� �и� ���ڵ�(����,�޸�,�ٹٲ�,�ι���) �����Ѵ�
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