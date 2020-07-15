#include <stdio.h>
#define MAX_STRING 81
int main(void)
{
	char str[MAX_STRING];
	int count[5] = {0};
	int i;

	printf("문자열 입력(문자수 81 이하): ");
	scanf("%s", str);

	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] =='a' || str[i] == 'A')
			count[0]++;
		else if(str[i] =='e' || str[i] == 'E')
			count[1]++;
		else if(str[i] =='i' || str[i] == 'I')
			count[2]++;
		else if(str[i] =='o' || str[i] == 'O')
			count[3]++;
		else if(str[i] =='u' || str[i] == 'U')
			count[4]++;
	}
	
	printf("a or A: %d 개\n", count[0]);
	printf("e or E: %d 개\n", count[1]);
	printf("i or I: %d 개\n", count[2]);
	printf("o or O: %d 개\n", count[3]);
	printf("u or U: %d 개\n", count[4]);
}
