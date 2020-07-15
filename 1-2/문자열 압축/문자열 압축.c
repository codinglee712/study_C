#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solution(char *s)
{
	char s1[3];
	char s2[3];
	char tmp[1001] = "";
	int strLen = strlen(s);
	int i, len;
	char nString[5] = "";

	len = 1;
	strncpy(s1, s, 2);
	s1[2] = '\0';
	i = 2;
	while(i < strLen) {
		s += 2;
		strncpy(s2, s, 2);
		s2[2] = '\0';
		if(strcmp(s1, s2) == 0)
			len++;
		else {
			if(len == 1) {
				printf("%s", s1);
				strcat(tmp, s1);
			}
			else {
				printf("%d%s", len, s1);
				sprintf(nString, "%d", len);
				strcat(tmp, s1);
				strcat(tmp, nString);
			}
			strcpy(s1, s2);
			len = 1;
		}
		i += 2;
	}
	if(len == 1) {
		printf("%s\n", s1);
		strcat(tmp, s1);
	}
	else {
		printf("%d%s\n", len, s1);
		sprintf(nString, "%d", len);
		strcat(tmp, s1);
		strcat(tmp, nString);
	}

	return strlen(tmp);
}

int main(void)
{
	char s[1001];

	scanf("%s", s);
	printf("%d\n", solution(s));
}