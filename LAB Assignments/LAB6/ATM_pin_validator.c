#include <stdio.h>
int main()
{
	int pin, i;
	printf("Enter the PIN: ");
	scanf("%d", &pin);
	if(pin == 5678)
	{
		printf("\nYour entered PIN is correct.");
	}
	else
	{
		for(i = 0; i < 2; i = i + 1) 
		{
			printf("\nYour entered PIN is wrong. kinldy re-enter the PIN: ");
			scanf("%d", &pin);
			if(i == 1)
			{
				printf("\nYour ATM card is blocked.");
				break;
			}
		}
	}
	return 0;
}
