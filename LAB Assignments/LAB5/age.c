#include <stdio.h>

int main()
{
	int age;
	printf("Enter your age: ");
	scanf("%d", &age);

	if (age >= 0) 
	{
		if (age <= 12) 
		{
			printf("You are a Child.\n");
        } else if (age <= 19) 
		{
            printf("You are a Teenager.\n");
        } else if (age <= 59) 
		{
            printf("You are an Adult.\n");
       	} else 
		{
            printf("You are a Senior.\n");
		}
    } else 
	{
    	printf("Invalid Input.\n");
    }
	return 0;
}
