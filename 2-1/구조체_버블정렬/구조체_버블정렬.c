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

void swap(Student* s, int i, int j)
{
	Student temp;
	temp = s[j];
	s[j] = s[i];
	s[i] = temp;
}

void bubbleSort(Student* s, int n, int order) //오름차순, 큰 값을 찾아 오른쪽으로, i가 0부터
{
	int i, j, temp;
	int sorted;

	switch(order) {
		case 1:
			for(i = 0; i < n-1; i++) 
				for(j = 0; j < n-i-1; j++) 
					if(s[j].korean < s[j+1].korean) 
						swap(s, j, j+1);
			return;
		case 2:
			for(i = 0; i < n-1; i++) 
				for(j = 0; j < n-i-1; j++) 
					if(s[j].english < s[j+1].english) 
						swap(s, j, j+1);
			return;
		case 3:
			for(i = 0; i < n-1; i++) 
				for(j = 0; j < n-i-1; j++) 
					if(s[j].math < s[j+1].math) 
						swap(s, j, j+1);
			return;
		case 4:
			for(i = 0; i < n-1; i++) 
				for(j = 0; j < n-i-1; j++) 
					if(s[j].id > s[j+1].id) 
						swap(s, j, j+1);
			return;
		default:
			return;
	}
}

int main(void)
{
	int n;
	int order;
	Student *s;

	scanf("%d", &n);

	s = (Student*) malloc (sizeof(Student) * n); 

	initInfo(s, n);
	printInfo(s, n);

	printf("정렬 기준 선택(1:국어, 2:영어, 3:수학, 4:id(오름차순), 0:끝내기): ");
	scanf("%d", &order);
	while(order != 0) {
		bubbleSort(s, n, order);

		printInfo(s, n);
		printf("\n");

		printf("정렬 기준 선택(1:국어, 2:영어, 3:수학, 4:id(오름차순), 0:끝내기): ");
		scanf("%d", &order);
	}
	
	free(s);
}