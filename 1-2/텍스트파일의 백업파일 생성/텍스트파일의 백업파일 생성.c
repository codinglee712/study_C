#include <stdio.h>
#include <string.h>
int main(void)
{
	char in_frame[128] = ""; //�Է¿� ���ϸ�
	char out_frame[128] = ""; //��¿� ���ϸ�
	char str[BUFSIZ];
	FILE *fin = NULL;
	FILE *fout = NULL;

	printf("���� �̸�? ");
	gets(in_frame);

	fin = fopen(in_frame, "r");
	if(fin == NULL) {
		printf("%s ���� ���� ����\n", in_frame);
		return 1;
	}
	strcpy(out_frame, in_frame);
	strcat(out_frame, ".bak");

	fout = fopen(out_frame, "w");
	if(fout == NULL) {
		printf("%s ���� ���� ����\n", out_frame);
		fclose(fin); //��½�Ʈ���� �� �� ���� ���, �Է½�Ʈ���� �ݰ� ����
		return 1;
	}

	while(fgets(str, sizeof(str), fin) != NULL) {
		fputs(str, stdout);
	}

	fclose(fin);
	fclose(fout);

	printf("���� ��� ����\n");
}