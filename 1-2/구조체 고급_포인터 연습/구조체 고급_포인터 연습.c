#include <stdio.h>
typedef struct {
	int midterm;
	int final;
} Score;

void printScore(Score *p)
{
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
}

Score totalScore1(Score *p1, Score *p2) //����ü�� ��ȯ������ ������ ���
{
	Score temp;
	temp.midterm = p1->midterm + p2->midterm;
	temp.final = p1->final + p2->final;
	return temp;
}

void totalScore2(Score *p1, Score *p2, Score *total) //����ü�� �Ű������� ������ ���
{
	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;
}

int main(void)
{
	Score s1 = {50, 100};
	Score s2 = {70, 100};
	Score tempScore;

	tempScore = totalScore1(&s1, &s2);
	printScore(&tempScore);

	totalScore2(&s1, &s2, &tempScore);
	printScore(&tempScore);
}