#include <stdio.h>
#define MAX_STRING 81
int main(void)
{
	char str[MAX_STRING];
	int count[5] = {0};
	int i;

	printf("���ڿ� �Է�(���ڼ� 81 ����): ");
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
	
	printf("a or A: %d ��\n", count[0]);
	printf("e or E: %d ��\n", count[1]);
	printf("i or I: %d ��\n", count[2]);
	printf("o or O: %d ��\n", count[3]);
	printf("u or U: %d ��\n", count[4]);
}
