#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;

struct cClass {
	int num;
	Student s[40];
};
typedef struct cClass CClass;

void readStudentScore(Student *sp)
{
	printf("Enter student name: ");
	scanf("%s", sp->name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &sp->midterm, &sp->final);
}

void readClass(CClass *sp)
{
	int i;
	for(i = 0; i < sp->num; i++) {
		printf("Enter student name: ");
		scanf("%s", sp->s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &sp->s[i].midterm, &sp->s[i].final);
	}
}

void calculateStudentAverage(Student *sp)
{
	sp->average = (sp->midterm + sp->final) / 2;
}

void calculateClassAverage(CClass *sp)
{
	int i;

	for(i = 0; i < sp->num; i++)
		sp->s[i].average = (sp->s[i].midterm + sp->s[i].final) / 2;
}

void calculateAll(CClass *cp, Student *all)
{
	int i;

	for(i = 0; i < cp->num; i++) {
		all->midterm += cp->s[i].midterm;
		all->final += cp->s[i].final;
		all->average += cp->s[i].average;
	}
	all->midterm /= cp->num;	
	all->final /= cp->num;
	all->average /= cp->num;
}

Student calculateAll2(CClass *cp)
{
	Student pAll = {"All", 0, 0, 0};
	int i;

	for(i = 0; i < cp->num; i++) {
		pAll.midterm += cp->s[i].midterm;
		pAll.final += cp->s[i].final;
		pAll.average += cp->s[i].average;
	}
	pAll.midterm /= cp->num;	
	pAll.final /= cp->num;
	pAll.average /= cp->num;

	return pAll;
}

void printStudent(Student *sp)
{
	printf("%s\t%d\t%d\t%d\n", sp->name, sp->midterm, sp->final, sp->average);
}

void printClass(CClass *sp)
{
	int i;

	for(i = 0; i < sp->num; i++)
		printf("%s\t%d\t%d\t%d\n", sp->s[i].name, sp->s[i].midterm, sp->s[i].final, sp->s[i].average);
}
int main(void)
{
	CClass c2;
	int i;

	Student all = {"All", 0, 0, 0};

	printf("Enter a number of student: ");
	scanf("%d", &c2.num);

	readClass(&c2);

	calculateClassAverage(&c2);

	printf("\n이름\t중간\t학기말\t평균\n");
	printClass(&c2);

	calculateAll(&c2, &all);
	printf("----------------------------------\n");
	printStudent(&all);

	all = calculateAll2(&c2);
	printf("----------------------------------\n");
	printStudent(&all);
}