#include <stdio.h>
int main()
{
    int i,j;

    //Input
    int n;
    printf("Enter the number of rows of the upper half: ");
    scanf("%d", &n);

    //Printing upper half
    for(i=0;i<n;i++)
    {
        //Printing Space
        for(j=0;j<n-i-1;j++)
        {
            printf(" ");
        }
        
        //Printing *
        for(j=0;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    //Printing lower half
    for(i=n-1;i>0;i--)
    {
        //Printing Space
        for(j=0;j<n-i;j++)
        {
            printf(" ");
        }
        
        //Printing *
        for(j=0;j<i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
