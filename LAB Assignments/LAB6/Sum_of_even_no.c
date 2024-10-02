#include <stdio.h>
int main()
{
	int i, a, b, sum = 0;
	printf("Enter the smaller integer: ");
	scanf("%d", &a);
	printf("Enter the larger integer: ");
	scanf("%d", &b);
	if(a > b || a == b)
	{
		printf("Invalid Input.");
	}
	else
	{
		for(i = a; i <= b; i = i + 2)
		{
			sum = sum + i;
		}
		printf("Sum of even no = %d", sum);
	}
	return 0;
}