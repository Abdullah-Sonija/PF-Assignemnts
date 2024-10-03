#include <stdio.h>
int main()
{
	int n, last_digit, a, sum;
	printf("Enter the Number: ");
	scanf("%d", &n);
	a = n;
	while(a >= 10)
	{
		sum = 0;
		while(a > 0)
		{
			last_digit = a % 10;
			sum = sum + last_digit;
			a = a / 10;
		}
		a = sum;
	}
    printf("The sum of digits of %d till the answer is a single digit number is = %d\n", n, a);

	return 0;
}
