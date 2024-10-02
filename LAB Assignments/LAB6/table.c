#include <stdio.h>
int main()
{
	int a, n, i = 1;
	int c;
	printf("Enter the number whose table you want to print: ");
	scanf("%d", &n);
	printf("Enter the number till where you want the table to go: ");
	scanf("%d", &c);
	do
	{
	    a = n * i;
	    if(a >= 500)
	    {
	        break;
	    }
		printf("%d x %d = %d\n", n, i, a);
		i = i + 1;
		
	}while(i <= c);
    return 0;
}
