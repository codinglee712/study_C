//20190993 ��ǻ���а� ������
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int is_in(char* w[], int size, char ch) // �ʿ��ϸ� ����Ѵ�
{
	int i;
	for (i = 0; w[i] != '\0'; i++)
		if (w[i] == ch)
			return 1;
	return 0;
}

void remove_duplicated_char(char* word) {
	int i, j;
	int len;
	int tail = 1; 

	if(word == NULL) return;

	len = strlen(word);
	for(i = 0; i < len; i++) {
		if(!is_in_word(word, tail, word[i])) {
			word[tail] = word[i];
			tail++;
		}
	}
	word[tail] = '\0';
}

void makeCode(char code[], int distance, char word[]) 
{
	int i, j;
	int rightIdx, leftIdx;

	for(i = distance; *word != '\0'; i++) //distance���� key�� ä���
		code[i] = *word++;

	j = 0;
	rightIdx = i; //key���� ���� ���� �ε���
	while(rightIdx < 26) { //key �������� ������ ���� ���ĺ� ä���
		if(is_in_word(code, i + j, j + 'A'))
			j++;
		else
			code[rightIdx++] = j++ + 'A'; 
	}

	j = 0;
	leftIdx = 0;
	while(leftIdx < distance) { //0���� distance���� ���� ���ĺ� ä���
		if(is_in_word(code, 26, j + 'A'))
			j++;
		else
			code[leftIdx++] = j++ + 'A'; 
	}
}

void printCode(char code[]) 
{
	int i;
	printf("-------------------------------------------------\n");
	printf("alpabet:\t");
	for(i = 0; i < 26; i++)
		printf("%c", i + 'A');

	printf("\nencoded:\t");
	for(i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n-------------------------------------------------\n");
}

void encode(char code[], char s[], char e[]) 
{
	int i;
	for(i = 0; s[i] != '\0'; i++) {
		if(isupper(s[i]))
			e[i] = code[s[i]-'A'];
		else
			e[i] = s[i];
	}
	e[i] = '\0';
}

void decode(char code[], char e[], char d[]) 
{
	int i, j;

	for(i = 0; e[i] != '\0'; i++) {
		if(isupper(e[i])) {
			j = 0;
			while(code[j] != e[i])
				j++;
			d[i] = j + 'A'; 
		}
		else
			d[i] = e[i];
	}
	d[i] = '\0';
}

int main(void)
{
	char code[26]; // code[0]���� 'A'�� ��ȣȭ���ڸ� ����
	int distance;
	char key[30];
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	printf("Enter a word to use for encoding(�빮�ڷε� �ܾ��Է�):");
	scanf("%s", key);

	remove_duplicated_char(key);
	makeCode(code, distance, key);
	printCode(code);

	fflush(stdin);
	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);

	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);

	printf("encoded sentence:\t");
	puts(encodedSentence);

	decode(code, encodedSentence, decodedSentence);
	printf("decoded sentence:\t");
	puts(decodedSentence);
}