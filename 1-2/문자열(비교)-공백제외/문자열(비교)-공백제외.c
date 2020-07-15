#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
	}// B-1의 함수 정의를 여기에
}

int strcmp_ic(char *s1, char *s2)
{
	while(*s1 || *s2) {
		if(tolower(*s1) != tolower(*s2))
			return 0;
		s1++;
		s2++;
	}
	return 1;
}

int main(void)  
{
    char word1[81];
    char word2[81];
    int i, j;
	int check = 1;

    //printf("Enter the first word: ");
    gets(word1);
    //printf("Enter the second word: ");
    gets(word2);

    //아래 주어진 for문의 헤더는 그대로 사용해도 되고 고쳐도 좋다
    for (i = 0, j = 0; word1[i] != '\0' || word2[j] != '\0';) { 
		if(word1[i] == ' ')
			 i++;
		 else if(word2[j] == ' ')
			 j++;
		 else {
			if(tolower(word1[i]) != tolower(word2[j])) {
				check = 0;
				break;
			}
			i++;
			j++;
		 }
    }

	if(check == 0)
		printf("%d", check);
	else
		printf("%d", check);

    return 0;
}