#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char str[15];
	char  birthdayYear[5] = "19";
	int averageYear;

	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>: ");
	gets(str);

	strncat(birthdayYear, str, 2);
	printf("����� %s�⵵ ���̱���\n", birthdayYear);

	if(str[7] == '1') {
		averageYear = atoi(birthdayYear) + 77;
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", averageYear);
	}
	else {
		averageYear = atoi(birthdayYear) + 84;
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", averageYear);
	}
}