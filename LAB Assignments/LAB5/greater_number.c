#include <stdio.h>
int main()
{
    int a, b, c;
	printf("Enter the First Number: ");
	scanf("%d", &a);
	printf("Enter the Second Number: ");
	scanf("%d", &b);
	printf("Enter the Third Number: ");
	scanf("%d", &c);
	if(a>b)
	{
		if(a>c)
		{
			printf("The Greatest among the given Numbers is: %d" ,a);
		}
		else
		{
			printf("The Greatest among the given Numbers is: %d" ,c);
		}
	}
	else if(b>a)
	{
		if(b>c)
		{
			printf("The Greatest among the given Numbers is: %d" ,b);
		}
		else
		{
			printf("The Greatest among the given Numbers is: %d" ,c);
		}
	}
	return 0;
}
