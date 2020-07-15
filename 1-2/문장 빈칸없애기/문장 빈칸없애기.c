#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void deleteBlank(char *s)
{
	int i;
	char *p = '\0';
    for(i = 0; *s != '\0'; i++) {
		if(isspace(*s)) {
			for(p = s + 1; *p != '\0'; p++)
				*(p - 1) = *p;
			*(p - 1) = 0;
		}
		s++;
	}// 코드 정의
}

int main(void)  
{
    char word1[81];

    printf("Enter a word: ");
    gets(word1);

    deleteBlank(word1);

    printf("%s\n", word1);

    return 0;
}