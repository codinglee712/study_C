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
		printf("�й� :%3d \t���� :%3d\t���� :%3d\t ���� :%3d\n", s->id, s->english, s->math, s->korean);
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

int partition(Student* s, int low, int high, int order) //i, j�� ���ʿ������� ����, pivot�� ������ ��
{	
	int i, j;

	i = low - 1;
	switch (order) {
		case 1:
			for(j = low; j < high; j++)
				if(s[high].korean < s[j].korean) 
					swap(s, ++i, j);
			swap(s, ++i, high);
			return i;
		case 2:
			for(j = low; j < high; j++)
				if(s[high].english < s[j].english) 
					swap(s, ++i, j);
			swap(s, ++i, high);
			return i;
		case 3:
			for(j = low; j < high; j++)
				if(s[high].math < s[j].math) 
					swap(s, ++i, j);
			swap(s, ++i, high);
			return i;
		case 4:
			for(j = low; j < high; j++)
				if(s[high].id > s[j].id) 
					swap(s, ++i, j);
			swap(s, ++i, high);
			return i;
		default:
			return;
	}
}

void quickSort(Student* s, int low, int high, int order)
{
	int pivot;

	if(low < high) {
		pivot = partition(s, low, high, order);
		quickSort(s, low, pivot - 1, order);
		quickSort(s, pivot + 1, high, order);
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

	printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������): ");
	scanf("%d", &order);
	while(order != 0) {
		quickSort(s, 0, n-1, order);

		printInfo(s, n);
		printf("\n");

		printf("���� ���� ����(1:����, 2:����, 3:����, 4:id(��������), 0:������): ");
		scanf("%d", &order);
	}
	
	free(s);
}