#include <stdio.h>
int main()
{
	int n;
	printf("Enter the Number: ");
	scanf("%d", &n);
	if(n == 0)
	{
		printf("The given Number is Zero.\n");
	} else if(n > 0)
	{
		printf("The given Number is Positive.\n");
		if(n % 2 == 0)
		{
			printf("The given Number is Even.\n");
		} else
		{
			printf("The given Number is Odd.\n");
		}
	} else
	{
	printf("The given Number is Negative.\n");
	}
	return 0;		
}
