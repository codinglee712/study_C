#include <stdio.h>
void printFibo(int n)
{
	int fn = 0;
	int fn_1 = 0;
	int fn_2 = 1;
	int i = 1;

	while(i <= n)
	{
		fn = fn_1 + fn_2;

		fn_2 = fn_1;
		fn_1 = fn;
		i++;
	}
	printf("%10d ", fn);
}

int main(void)
{
	int num, i;

	printf("몇 항까지 출력하려는가<0이상의 수>: ");
	scanf("%d", &num);

	for(i = 0; i < num; i++)
	{
		printFibo(i);
		if(i % 5 == 4)
			printf("\n");
	}
	printf("\n");
}