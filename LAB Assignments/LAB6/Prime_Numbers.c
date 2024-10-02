#include <stdio.h>
int main()
{
	int n, i, x;
	printf("Enter the Number: ");
	scanf("%d", &n);
	if(n <= 1)
	{
		printf("The given is not a prime number.");
	}
	else if(n == 2 || n == 3)
	{
		printf("The given is a prime number.");
	}
	else
	{
		i = 2;
		while(i * i <= n)
		{
			if(n % i == 0)
			{
				printf("The given is not a prime number.");
				return 0;
			}
			i = i +1;
		}
		printf("The given is a prime number.");
	}
	return 0;
}