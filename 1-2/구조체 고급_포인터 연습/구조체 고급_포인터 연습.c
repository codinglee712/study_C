#include <stdio.h>
typedef struct {
	int midterm;
	int final;
} Score;

void printScore(Score *p)
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
}

Score totalScore1(Score *p1, Score *p2) //구조체를 반환값으로 설정한 경우
{
	Score temp;
	temp.midterm = p1->midterm + p2->midterm;
	temp.final = p1->final + p2->final;
	return temp;
}

void totalScore2(Score *p1, Score *p2, Score *total) //구조체를 매개변수로 가져온 경우
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