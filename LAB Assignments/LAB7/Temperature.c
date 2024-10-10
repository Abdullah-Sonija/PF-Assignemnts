#include <stdio.h>
int main()
{
	int t;
	int temp[7];
	int i;
	int sum = 0;
	int avg;
	int a;

	//Input

	for(i=0;i<7;i++)
	{
		printf("Enter Today's Temperature: ");
		scanf("%d", &t);
		
		temp[i] = t;
	}

	//Average

	for(i=0;i<7;i++)
	{
		sum = sum + temp[i];
	}

	avg = sum / 7;

	printf("Aveage Temperature is: %d\n", avg);

	//Extreme Temperature (above 40 and below 10)

	for(i=0;i<7;i++)
	{
		if(temp[i] <= 10 || temp[i] >= 40)
		{
		    a = i + 1;
			printf("Extreme Temperature on day %d: %d°C\n", i + 1, temp[i]);
		}
	}
	
}