#include <stdio.h>

void print_star(int n)
{
    for (int i = 1; i < n;i++)
    {

        //Print spaces
        for (int j = 0; j < 2 * n - 1 - i; j++)
        {
            printf(" ");
        }

        // Print stars and spaces for the hollow effect
        for (int k = 1; k <= (2 * i - 1); k++) 
        {
            if (k == 1 || k == (2 * i - 1) || i == n) 
            {
                // Print border
                printf("*");  
            } else 
            {
                //hollow effect
                printf(" "); 
            }
        }

    printf("\n");
    }
    // printing the line with straight hands
    for (int l = 0; l < (4 * n) - 3; l++) 
    {
        if (l < n || l >= (4 * n - 3 ) - n)
        {
            printf("*");
        }else
        {
            printf(" ");
        }

    }
    printf("\n");

    // printing the mid section spaces and stericks 
    for (int m = 1; m <= n - 1; m++) 
    {
        for (int o = 0; o < m; o++) 
        {
            printf(" ");
        }
        printf("*");
        for (int p = 0; p <= ((4 * n - 7) - 2 * m + 1); p++) 
        {
            printf(" ");
        }
        if (m < 4 * n - 7) 
        {
            printf("*");
        }
        printf("\n");
    }

    // printing the lower/ending section 

    for (int q = 1; q <= n - 2; q++)
    {
        for (int r = n-2; r >= 0 + q; r--) 
        {
            printf(" ");
        }
        printf("*");
        for (int r = n-2; r >= 0 + q; r--) 
        {
            printf(" ");
        }
        printf("*");
        
        if (n == 3) 
        {
        printf(" ");
        } 
        
        else if (n >= 5) 
        {
            int underscoresCount = 1 + (q - 1) * 4;
                
            // Print leading underscores
            for (int t = 0; t < 1 + (q - 1) * 4; t++) 
            {
                printf(" ");
            }
        }
        
        printf("*");
        for (int r = n-2; r >= 0 + q; r--) 
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    // print last line
    printf("*");
    for (int u = 1; u <= 4 * n - 5; u++)
    {
        printf(" ");
    }
    printf("*");

    printf("\n");
}

int main()
{
    int n;
    do
    {
        printf("Enter the size (greater than 3 and an odd number): ");
        scanf("%d", &n);
    }while(n < 3 || n % 2 == 0);

    print_star(n);

    return 0;
}