#define MAX_SIZE 5
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
#include <stdio.h>
int hasElement(int set[], int size, int element)
{
	int i;

	for(i = 0; i < size; i++)
		if(set[i] == element)
			return HAVE_ELEMENT;
	return DO_NOT_HAVE_ELEMENT;
}

void printSet(int set[], int size)
{
	int i;

	printf("{ ");
	for(i = 0; i < size; i++)
	{
		if(i < size-1)
			printf("%d, ", set[i]);
		else
			printf("%d", set[i]);
	}
	printf(" }\n");
}

int main(void)
{
	int setA[MAX_SIZE];
	int element, found;
	int i;

	i = 0;
	while(i <= 5)
	{
		printf("다중집합에 추가할 원소: ");
		scanf("%d", &element);

		found = hasElement(setA, MAX_SIZE, element);

		if(found)
			printf("%d는 이미 집합에 있음\n", element);
		else
		{
			setA[i] = element;
			printSet(setA, i + 1);
			i++;
		}
	}
}