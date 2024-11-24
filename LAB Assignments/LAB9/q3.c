#include<stdio.h>
#include<math.h>

void prime(int n);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    prime(n);

    return 0;
}

void prime(int n)
{
    if(n<=1)
    {
        printf("The given no is not a prime number.\n");
        return;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            printf("The given no is not a prime number.\n");
            return;
        }
    }
    printf("The given no is a prime number.\n");
}