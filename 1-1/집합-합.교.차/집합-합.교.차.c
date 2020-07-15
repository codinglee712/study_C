#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0

int hasElement(int set[], int size, int element)
{
	int i;

	for(i = 0; i < size; i++)
		if(set[i] == element)
			return HAVE_ELEMENT;
	return DO_NOT_HAVE_ELEMENT;
}

int addOneElement(int set[], int size, int element)
{
	if(hasElement(set, size, element))//for문 쓸 필요 없음
		printf("It is redundant. Please retry.\n");
	else
	{
		set[size] = element;
		size++;
	}
	return size;
}

void printSet(int set[], int size)
{
	int i;

	printf("< ");
	for(i = 0; i < size; i++)
	{
		if(i < size-1)
			printf("%d, ", set[i]);
		else
			printf("%d", set[i]);
	}
	printf(" >\n");
}

int setUnion(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i;
	int size3 = 0;

	for(i = 0; i < size1; i++)
	{
		setResult[i] = set1[i];
		size3++;
	}

	for(i = 0; i < size2; i++)
		if(!hasElement(set2, size2, set2[i]))//Result배열에 set2[i]가 없으면 넣기
		{
			setResult[size3] = set2[i];
			size3++;
		}
	return size3;
}

int setIntersection(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i, j;
	int size3 = 0;

	for(i = 0; i < size1; i++)
		for(j = 0; j < size2; j++)//set1[i]를 set2의 원소와 모두 비교
			if(set1[i] == set2[j])
			{
				setResult[size3] = set1[i];//set1의 한 원소가 set2의 원소와 맞는게 있으면 Result배열에 넣기
				size3++;
			}
	return size3;
}

int setComplements(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i, j;
	int size3 = 0;
	int result;

	for(i = 0; i < size1; i++)
	{
		result = 0;

		for(j = 0; j < size2; j++)
			if(set1[i] == set2[j])//set1[i]를 set2의 원소와 모두 비교
				result = 1;

		if(result != 1)//set1의 한 원소가 set2의 원소와 맞는게 아닐 때
		{
			setResult[size3] = set1[i];//Result배열에 넣기
			size3++;
		}
	}

	return size3;
}

int main(int argc, char *argv[])
{
	int i;
	int setA[MAX_SIZE];
	int setB[MAX_SIZE];
	int setC[MAX_SIZE*2];

	int sizeA;
	int sizeB;
	int sizeC;

	printf("Enter the size od Set A: ");
	scanf("%d", &sizeA);

	i = 0;
	while(i < sizeA)
	{
		printf("Enter the number for(%d/%d):", i+1, sizeA);
		scanf("%d", &setA[i]);
		i = addOneElement(setA, i, setA[i]);
	}

	printf("Enter the size od Set B: ");
	scanf("%d", &sizeB);

	i = 0;
	while(i < sizeB)
	{
		printf("Enter the number for(%d/%d):", i+1, sizeB);
		scanf("%d", &setB[i]);
		i = addOneElement(setB, i, setB[i]);
	}

	printf("Set A: ");
	printSet(setA, sizeA);
	printf("Set B: ");
	printSet(setB, sizeB);

	sizeC = setUnion(setA, sizeA, setB, sizeB, setC);
	printf("Union of setA and setB: ");
	printSet(setC, sizeC);

	sizeC = setIntersection(setA, sizeA, setB, sizeB, setC);
	printf("Intersection of setA and setB: ");
	printSet(setC, sizeC);

	sizeC = setComplements(setA, sizeA, setB, sizeB, setC);
	printf("Set-theoretic difference of setA and setB <setA - setB>: ");
	printSet(setC, sizeC);
}