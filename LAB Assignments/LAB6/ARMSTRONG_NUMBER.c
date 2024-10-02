#include <stdio.h>
int main()
{
	int i, n, a, sum = 0;
	printf("Enter the Number: ");
	scanf("%d", &n);
	i = n;
	while(i > 0)
	{
		a = i % 10;
		i = i / 10;
		sum = sum + (a * a * a);	
	}
	if(sum == n)
	{
		printf("The given number is an Armstrong Number.");
	}
	else
	{
		printf("The given number is not an Armstrong Number.");
	}
	return 0;
}