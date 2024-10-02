#include <stdio.h>
int main()
{
	int a, i;
	char c;

// Input
	printf("\nEnter the Age: ");
	scanf("%d", &a);
	if(a < 1)
	{
	    printf("\nInvalid Input");
	    return 0;
	}
	printf("\nEnter your Monthly Income in Rs: ");
	scanf("%d", &i);
	if(i < 0)
	{
	    printf("\nInvalid Input");
	    return 0;
	}
	printf("\nEnter the Credit score (g for good and b for bad) : ");
	scanf(" %c", &c);
	if(c != 'g' || c != 'n')
	{
	    printf("\nInvalid Input");
	    return 0;
	}

// Process and Output
	if(a >= 18 && a <= 65 && i >= 50000 && c == 'g')
	{
		printf("\nYou are elligible to take the loan.");
	} else 
	{
		printf("\nYou are not elligible to take the loan.");
	}
	return 0;
}