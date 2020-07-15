#include <stdio.h>
int cycleNb(int n)
{
	printf("%d ", n);

	if(n == 1)
		return 0;
	else if(n % 2 == 0)
		return 1 + cycleNb(n / 2);
	else
		return 1 + cycleNb(n * 3 + 1);

}
int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);
	
	printf("\n±æÀÌ´Â %d\n", cycleNb(num));
}