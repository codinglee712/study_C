#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct student
{
	int id;
	int korean, english, math;
}Student;

void printInfo(Student* s, int size)
{
	int i;
	for(i = 0; i < size; i++) {
		printf("학번 :%3d \t영어 :%3d\t수학 :%3d\t 국어 :%3d\n", s->id, s->english, s->math, s->korean);
		s++;
	}
}

void initInfo(Student* s, int size)
{
	int i;
	for(i = 0; i < size; i++) {
		s->id = i + 1;
		s->korean = rand() % 101;
		s->english = rand() % 101;
		s->math = rand() % 101;
		s++;
	}
}

void selectionSort(Student* s, int n) //내림차순
{
	int i, j;
	int maxIdx;
	Student temp;

	for(i = 0; i < n-1; i++) {
		maxIdx = i;
		for(j = i; j < n; j++) {
			if(s[maxIdx].korean < s[j].korean)
				maxIdx = j;
		}
		temp = s[maxIdx];
		s[maxIdx] = s[i];
		s[i] = temp;
	}

}

int main(void)
{
	int n;
	Student *s;

	scanf("%d", &n);

	s = (Student*) malloc (sizeof(Student) * n); 

	initInfo(s, n);

	printf("정렬 전:\n");
	printInfo(s, n);

	selectionSort(s, n);

	printf("정렬 후:\n");
	printInfo(s, n);

	free(s);
}