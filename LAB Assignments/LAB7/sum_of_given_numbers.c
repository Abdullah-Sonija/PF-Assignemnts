#include <stdio.h>
int main()
{
    int n, a, i, sum = 0;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int num[n];
    for(i = 0; i < n; i = i + 1)
    {
        printf("Enter the value of the number: ");
        scanf("%d", &a);
        num[i] = a;
        sum = sum + num[i];
    if(i< (n - 1))
    {
        printf("Give the next number \n");
    }
    }
    printf("The sum of the given numbers is = %d", sum);
    return 0;
}