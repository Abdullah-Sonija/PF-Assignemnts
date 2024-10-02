//we need to design a program that takes the input and add it to a variable and print it until the user input becomes zero.
// for this reason we use DO WHILE which ensure that the program runs first  first time then check the input of the user and continue doing it till the user input becomes zero.

#include <stdio.h>
int main()
{
	int variable = 0;
	int n;
	do
	{
		printf("\nEnter the number: ");
		scanf("%d", &n);
		variable = variable + n;
		printf("variable = %d", variable);
	}
	while(n != 0);
	return 0;
}
