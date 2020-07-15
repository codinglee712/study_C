#include <stdio.h>
#include <ctype.h>
void makeCode(char code[], int distance)
{
	int i, j;
	for(i = 0; i < 26 - distance; i++)
		code[i] = i + 'A' + distance;
	for(j = 0; j < distance; j++)
		code[i++] = j + 'A';
}

void printCode(char code[])
{
	int i;
	printf("---------------------------------------\n");
	printf("alphabet:\t");
	for(i = 0;i < 26; i++)
		printf("%c", i + 'A');
	printf("\n");

	printf("encoded:\t");
	for(i = 0; i < 26; i++)
		printf("%c", code[i]);
	printf("\n");
	printf("---------------------------------------\n");
}

void encode(char code[], char s[], char e[])
{
	int i;
	for(i = 0; s[i] != '\0'; i++) {
		if(isupper(s[i]))
			e[i] = code[s[i] - 'A'];
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
	char code[26]; // code[0]부터 'A'의 암호화문자를 넣음
	int distance;
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];

	printf("Enter a distance for encoding:");
	scanf("%d", &distance);

	makeCode(code, distance);
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
	puts(decodedSentence);}