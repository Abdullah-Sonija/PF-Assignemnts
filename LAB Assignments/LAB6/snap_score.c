#include <stdio.h>
int main()
{
	char ans;
	int score = 0;
	do
	{
	    printf("\nDid you share the snap today (y for yes and n for no) :");
	    scanf(" %c", &ans);
	    if(ans == 'y')
	    {
            score = score + 1;
            printf("\nCurrent score: %d\n", score);

	    }
	    else if(ans == 'n')
	    {   
        	  break;
	    }
	    else
	    {
	    printf("Invalid input.\n");
	    }
    }while (ans == 'y'); // Corrected placement of while
    printf("\nYou broke your streak");
    return 0;
}