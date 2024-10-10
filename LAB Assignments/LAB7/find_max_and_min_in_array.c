#include <stdio.h>
int main()
{
	int size, max, min;
	int i, n, p;
	
	printf("Enter how many numbers you want to enter: ");
	scanf("%d", &size);
	int array[size];
	
	for(i = 0;i < size;i++)
	{
		p = i + 1;
		printf("Enter the Element %d: ", p);
		scanf("%d", &n);
		array[i] = n;
	}
	
	max = array[0];
	for(i = 0;i < size;i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}

	printf("The Maximum Number you Entered is %d. \n", max);

	min = array[0];
	for(i = 0;i < size;i++)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
	}

	printf("The Minimun Number you Entered is %d. \n", min);

	return 0;
}