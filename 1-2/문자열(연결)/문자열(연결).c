#include <stdio.h>
#include <string.h>
int main(void)
{
	char sentence[100] = "";
	char word[20];

	do {
		printf("�ܾ�? ");
		scanf("%s", word);
		strcat(sentence, word); //�Է� ���� �ܾ� ���̱�
		strcat(sentence, " "); //�������� �ܾ� ����
	} while (strcmp(word, ".") != 0); // ������ �Է��ϸ� ����, ���� ��µ�

	printf("%s\n", sentence);
}