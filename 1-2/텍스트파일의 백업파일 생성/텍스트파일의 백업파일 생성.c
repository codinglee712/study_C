#include <stdio.h>
#include <string.h>
int main(void)
{
	char in_frame[128] = ""; //입력용 파일명
	char out_frame[128] = ""; //출력용 파일명
	char str[BUFSIZ];
	FILE *fin = NULL;
	FILE *fout = NULL;

	printf("파일 이름? ");
	gets(in_frame);

	fin = fopen(in_frame, "r");
	if(fin == NULL) {
		printf("%s 파일 열기 실패\n", in_frame);
		return 1;
	}
	strcpy(out_frame, in_frame);
	strcat(out_frame, ".bak");

	fout = fopen(out_frame, "w");
	if(fout == NULL) {
		printf("%s 파일 열기 실패\n", out_frame);
		fclose(fin); //출력스트림을 열 수 없는 경우, 입력스트림을 닫고 종료
		return 1;
	}

	while(fgets(str, sizeof(str), fin) != NULL) {
		fputs(str, stdout);
	}

	fclose(fin);
	fclose(fout);

	printf("파일 백업 성공\n");
}