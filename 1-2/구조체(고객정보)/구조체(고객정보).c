#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
    char name[20];
    char gender;
    int height;
    int weight;
    int idealWeight;
} Member;

void printMember(Member *m)
{
     // 코드 정의
	printf("%s %c ", m->name, m->gender);
	printf("%d %d\n", m->height, m->weight);
}

void readNewMember(Member *m, int *mnPtr)
{
    // 코드 정의
    int i;
	scanf("%s %c", m[*mnPtr].name, &m[*mnPtr].gender);
	scanf("%d %d", &m[*mnPtr].height, &m[*mnPtr].weight);
   (*mnPtr)++;
}

void calculateIdealWeight(Member *m, int size)
{
    // 코드 정의
    int i;
	for(i = 0; i < size; i++) {
		if(m->gender == 'F')
			m->idealWeight = m->height - 110;
		else
			m->idealWeight = m->height - 105;
	}
}

Member *needDietMost(Member *m, int size)
{
     // 코드 정의
    Member *DM = m;
	int i;
	for(i = 0; i < size; i++) {
		if((m->weight - m->idealWeight) < ((m+1)->weight - (m+1)->idealWeight))
			DM = m+1;
		m++;
	}
	return DM;
}

int needDietMost2(Member *m, int size)
{
     // 코드 정의
	int i;
	int maxIdx;
	for(i = 0; i < size; i++) {
		if((m[i].weight - m[i].idealWeight) > (m[i+1].weight - m[i+1].idealWeight))
			maxIdx = i;
	}
	return maxIdx;
}

// main은 변경하지 마라(변경시 0점 처리)
int main(void) {

    Member members[MAX] = {{"aaa", 'F', 160, 50}, {"BBB", 'M', 180, 70}};
	Member tempMembers;
    int i;
    int memberNum = 2;
    int choice;
	int idx;

    scanf("%d", &choice);
    while (choice != -1) {
        readNewMember(members, &memberNum); // 
        scanf("%d", &choice);
    }

    calculateIdealWeight(members, memberNum); // 

    for (i = 0; i < memberNum; i++)
         printMember(&members[i]); 

	tempMembers = *needDietMost(members, memberNum);
	printMember(&tempMembers);

	idx = needDietMost2(members, memberNum);
	printMember(&members[idx]);
}