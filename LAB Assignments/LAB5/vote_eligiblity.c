#include <stdio.h>
int main()
{
	int a;
	char c;

	//input
	printf("Enter your age: ");
	scanf("%d", &a);
	printf("Are you a Citizen (y for yes and n for no): ");
	scanf(" %c", &c);

	//process and output
	if(a >= 18 && (c == 'y' || c == 'Y'))
	{
		printf("You are eligible to vote.");
	} else if(a < 18 || c == 'n' || c == 'N')
	{
    	printf("You are not eligible to vote.");
	} else
	{
		printf("Invalid Input.");
	}
	return 0;
}