#include <stdio.h>
int main()
{
    int n, i, a;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int num[n];

    for(i = 0; i < n; i = i + 1)
    {
        printf("Enter the value of the number: ");
        scanf("%d", &a);
        num[i] = a;
    if(i< (n - 1))
    {
        printf("Give the next number \n");
    }
    }
    printf("Your output is ");
    for(i = n - 1; i >= 0; i = i - 1)
    {
        printf("%d ", num[i]);
    }
    return 0;
}
