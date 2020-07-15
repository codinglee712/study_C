#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char str[64] = "";
	char *p = str;
	int len;

	strcpy(p, "test string ok then");
	len = strlen(p);

	*p = toupper(*p);
	while(*p) {
		if(strchr(p+1, ' ') == NULL)
			break;
		p = strchr(p+1, ' ');
		*(p+1) = toupper(*(p+1));
	}
	printf("%s\n", str);
}