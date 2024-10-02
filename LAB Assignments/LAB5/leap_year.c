#include <stdio.h>
int main()
{
	int y;
	printf("Enter the year: ");
	scanf("%d", &y);
	if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
	{
		printf("It's a leap year.");
	} else
	{
		printf("It's not a leap year.");
	}
	return 0;
}