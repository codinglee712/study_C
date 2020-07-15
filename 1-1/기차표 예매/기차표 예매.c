#define SIZE 10
#include <stdio.h>
char askReservation()
{
	int choiceNumber;
	printf("�¼��� �����Ͻðڽ��ϱ�?(���) ");
	scanf("%d", &choiceNumber);

	return choiceNumber;
}

void processReservation(int s[], int seatsNum, int total)
{
	int i;

	for(i = total - seatsNum; i < total; i++)
		s[i] = 1;
}

void printSeats(int s[], int size)
{
	int i;

	printf("-----------------------\n");
	printf(" 1 2 3 4 5 6 7 8 9 10\n");
	printf("-----------------------\n");

	for(i = 0; i < size; i++)
		printf("%2d", s[i]);
	printf("\n");
}

int main(void)
{
	int seatsNumber;
	int seats[20] = {0};
	int sum = 0;

	printf("******�¼� ���� �ý���******\n");

	while(seats[9] != 1)
	{
		printSeats(seats, SIZE);

		seatsNumber = askReservation();

		sum += seatsNumber;

		processReservation(seats, seatsNumber, sum);

		if(sum > SIZE)
			printf(">>>%d���� ���� �ȵ�\n", sum - SIZE);
	}
	printSeats(seats, SIZE);
}

