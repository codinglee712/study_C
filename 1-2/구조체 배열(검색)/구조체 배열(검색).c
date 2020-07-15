#include <stdio.h>
#include <string.h>
#define SIZE 20
typedef struct contact {
	char name[SIZE];
	char phone[SIZE];
	int rightone;
} Contact;

int main(void)
{
	Contact arr[] = {
		{"김석진", "01011112222", 0},
		{"전정국", "01012345678", 1},
		{"박지민", "01077778888", 2},
		{"김남준", "01098765432", 9},
		{"민윤기", "01011335577", 5},
		{"정호석", "01024682468", 7},
		{"김태형", "01099991111", 3} 
	};
	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	char name[SIZE]; //입력받은 이름을 저장할 문자 배열
	int index;
	Contact *recent = NULL; //마지막으로 검색한 연락처를 가리키는 포인터

	printf("이름(.입력시 종료)? ");
	scanf("%s", name);
	while(strcmp(name, ".") != 0) {
		index = -1;
		for(i = 0; i < size; i++)
		{
			if(strcmp(arr[i].name, name) == 0)
			{
				index = i;
				break;
			}
		}
		if(index >= 0) {
			printf("%s의 전화번호 %s로 전화를 겁니다....\n", arr[index].name, arr[index].phone);
			recent = &arr[index];
		}
		else
			printf("연락처를 찾을 수 없습니다.\n");

		printf("이름(.입력시 종료)? ");
		scanf("%s", name);
	}
	if(recent)
		printf("최근 통화: %s %s\n", recent->name, recent->phone);
}	