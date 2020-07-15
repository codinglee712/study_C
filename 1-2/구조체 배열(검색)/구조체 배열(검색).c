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
		{"�輮��", "01011112222", 0},
		{"������", "01012345678", 1},
		{"������", "01077778888", 2},
		{"�賲��", "01098765432", 9},
		{"������", "01011335577", 5},
		{"��ȣ��", "01024682468", 7},
		{"������", "01099991111", 3} 
	};
	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	char name[SIZE]; //�Է¹��� �̸��� ������ ���� �迭
	int index;
	Contact *recent = NULL; //���������� �˻��� ����ó�� ����Ű�� ������

	printf("�̸�(.�Է½� ����)? ");
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
			printf("%s�� ��ȭ��ȣ %s�� ��ȭ�� �̴ϴ�....\n", arr[index].name, arr[index].phone);
			recent = &arr[index];
		}
		else
			printf("����ó�� ã�� �� �����ϴ�.\n");

		printf("�̸�(.�Է½� ����)? ");
		scanf("%s", name);
	}
	if(recent)
		printf("�ֱ� ��ȭ: %s %s\n", recent->name, recent->phone);
}	