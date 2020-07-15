#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
	char grade;
};
typedef struct student Student;

int main(void)
{
	int i;
	Student s[3];
	int midTotal = 0;
	int finTotal = 0;
	
	for(i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &s[i].midterm, &s[i].final);
		s[i].average = (s[i].midterm + s[i].final) / 2;
	}

	printf("\n이름\t중간\t학기말\t평균\n");
	for(i = 0; i < 3; i++)
		printf("%s\t%d\t%d\t%d\n", s[i].name, s[i].midterm, s[i].final, s[i].average);

	printf("\n이름\t학점\n");
	for(i = 0; i < 3; i++) {
		if(s[i].average >= 80)
			s[i].grade = 'A';
		else if(s[i].average >= 50)
			s[i].grade = 'B';
		else
			s[i].grade = 'F';
		printf("%s\t%c\n", s[i].name, s[i].grade);
	}

	for(i = 0; i < 3; i++) {
		midTotal += s[i].midterm;
		finTotal += s[i].final;
	}
	printf("\n중간고사의 평균 = %d\n", midTotal / 3);
	printf("학기말고사의 평균 = %d\n", finTotal / 3);
}