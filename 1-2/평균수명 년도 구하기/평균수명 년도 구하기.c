#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char str[15];
	char  birthdayYear[5] = "19";
	int averageYear;

	printf("주민등록번호 입력<'-'포함>: ");
	gets(str);

	strncat(birthdayYear, str, 2);
	printf("당신은 %s년도 생이군요\n", birthdayYear);

	if(str[7] == '1') {
		averageYear = atoi(birthdayYear) + 77;
		printf("남자분이시군요.\n");
		printf("평균 수명 77를 더하면 %d까지 산다고 계산됩니다.\n", averageYear);
	}
	else {
		averageYear = atoi(birthdayYear) + 84;
		printf("여자분이시군요.\n");
		printf("평균 수명 84를 더하면 %d까지 산다고 계산됩니다.\n", averageYear);
	}
}