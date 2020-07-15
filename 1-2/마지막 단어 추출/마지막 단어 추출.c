#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char str[20];
    char lastWord[20];
    int i, j;
    int len = strlen(str);
    int lastId = 0;

    scanf("%s", str);

    for(j = len - 1; j >= 0; j--)
    {
        if(!islower(str[j]))
            continue;
        else
        {
            lastWord[lastId++] = str[j];
            if(str[j] != str[j - 1])
                break;
        }
    }
    lastWord[lastId] = '\0';

    printf("%s\n", lastWord);
}