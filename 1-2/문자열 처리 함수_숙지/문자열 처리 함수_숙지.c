#include <stdio.h>
#include <string.h> //문자열 처리 함수에 사용
#include <stdlib.h> // atoi함수에 사용
int main(void)
{
	char str1[15] = "ABCDED";
	char str2[15] = "abcde";
	char str3[15] = "1234";
	int n;

	char s[] = "Life is short,but art is long";
	char delimiters[] = " ,\n\0"; //토큰분리자 설정
	char *token; //포인터

	printf("가)str1의 길이 = %d\n", strlen(str1)); //6
	printf("   str2의 길이 = %d\n", strlen(str2)); //5

	strcpy(str1, str2); //str2->str1
	printf("나)str1 = %s\t\tstr2 = %s\n", str1, str2); //abcde, abcde

	strncpy(str1, str3, 2); //str3의 1,2->str1
	printf("다)str1 = %s\t\tstr3 = %s\n", str1, str3); //12cde('\0'을 넣어주지 않음), 1234

	strcat(str1, str2); // str1+str2
	printf("라)str1 = %s\t\tstr2 = %s\n", str1, str2); //12cdeabcde, abcde

	strncat(str1, str3, 2); //str1+str3
	printf("마)str1 = %s\t\tstr3 = %s\n", str1, str3); //12cdeabcd12('\0'을 자동으로 넣어줌), 1234

	printf("바)%d %d %d\n", strcmp("aaa", "abc"), strcmp("aaa", "aaa"), strcmp("ddd", "ccc")); //-1, 0, 1

	strcpy(str1, "111"); //111->str1(이때, '\0'이 자동생성되므로 원래 있던 문자들은 '\0'을 기준으로 제거됨
	n = atoi(str1) * 7; //111을 정수형으로 바꾼 뒤 7을 곱함
	printf("사)str1를 7배 한 값은 %d\n", n); //777

	printf("아)\n");
	n = 1;
	token = strtok(s, delimiters); //첫 시작은 배열이름
	while(token != NULL) {
		printf("%d번째 토큰은 %s\n", n++, token);
		token = strtok(NULL, delimiters); //그 뒤로는 NULL로 계속할 수 있음
	}
}

