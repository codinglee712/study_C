#include <stdio.h>
#include <string.h>
int main(void)
{
	char sentence[100] = "";
	char word[20];

	do {
		printf("단어? ");
		scanf("%s", word);
		strcat(sentence, word); //입력 받은 단어 붙이기
		strcat(sentence, " "); //공백으로 단어 구분
	} while (strcmp(word, ".") != 0); // 온점을 입력하면 종료, 같이 출력됨

	printf("%s\n", sentence);
}