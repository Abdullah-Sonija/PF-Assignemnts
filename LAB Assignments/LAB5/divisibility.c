#include <stdio.h>
int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	if(n % 3 == 0 && n % 5 == 0)
	{
		printf("It is divisible by both 3 and 5.");
	} else
	{
		printf("It isdivisible by both 3 and 5");
	}
	return 0;
}