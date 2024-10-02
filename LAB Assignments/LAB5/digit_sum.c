#include <stdio.h>
int main()
{
	int n, last_digit, a, sum = 0;
	printf("Enter the Number: ");
	scanf("%d", &n);
	a = n;
	while(n > 0)
	{
		last_digit = n % 10;
		sum = sum + last_digit;
		n = n / 10;
	}
	printf("The sum of digits of the %d is = %d", a, sum);
	return 0;
}