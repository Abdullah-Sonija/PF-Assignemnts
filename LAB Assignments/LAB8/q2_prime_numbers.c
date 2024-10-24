#include<stdio.h>
int main()
{
	int s, e;
	int i, j;
	
	//Input
	printf("Enter the starting number: ");
	scanf("%d", &s);
	printf("Enter the ending number: ");
	scanf("%d", &e);

	//output
 	printf("Prime numbers between %d and %d are:\n", s,e);
 	
	for(i=s;i<=e;i++)
	{
		if(i<2)
		{
			continue;
		}
		
		int isprime =1;//Flag
		
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				isprime = 0;
				break;
			}
		}
		if(isprime==1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	
	return 0;
}

