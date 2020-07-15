#include <stdio.h>
int main(void)
{
	int coins[4] = {500, 100, 50, 10};
	int change, i;

	printf("Enter the amount of change: ");
	scanf("%d", &change);

	for(i = 0; i < 4; i++)
	{
		printf("%d coin: %d\n", coins[i], change / coins[i]);
		change %= coins[i];
	}
}