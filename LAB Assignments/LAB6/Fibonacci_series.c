#include <stdio.h>
int main()
{
	int n, i, x;
	printf("Enter the Number: ");
	scanf("%d", &n);
	if(n <= 1)
	{
		printf("The given is not a prime number.\n");
	}
	else if(n == 2 || n == 3)
	{
		printf("The given is a prime number.\n");
		int a, b, c, w = 2;
    		a = 0;
		    b = 1;
		    printf("The fibonacci sequence is: ");
    		printf("%d,", a);
    		printf("%d,", b);
    		while(w < n)
    		{
       	 		c = a + b;
        		printf("%d,", c);
        		a = b;
        		b = c;
        		w = w + 1;
    		}
	}
	else
	{
		i = 2;
		while(i * i <= n)
		{
			if(n % i == 0)
			{
				printf("The given is not a prime number.\n");
				return 0;
			}
			i = i +1;
		}
		printf("The given is a prime number.\n");
		int a, b, c, w = 2;
    		a = 0;
    		b = 1;
    		printf("The fibonacci sequence is: ");
    		printf("%d,", a);
    		printf("%d,", b);
    		while(w < n)
    		{
       			c = a + b;
        		printf("%d,", c);
        		a = b;
        		b = c;
        		w = w + 1;
    		}
	}
	return 0;
}