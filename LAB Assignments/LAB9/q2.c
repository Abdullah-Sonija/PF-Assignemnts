#include<stdio.h>

void input(int *a, int *b);
void swap_integer(int *a, int *b);

int main()
{
    int a, b;
    input(&a, &b);
    swap_integer(&a, &b);
    return 0;
}
 
void input(int *a, int *b)
{
    //taking input 
    printf("Enter the first number: ");
    scanf("%d", a);
    printf("Enter the second number: ");
    scanf("%d", b);
    //printing original
    printf("Integer 1: %d\n", *a);
    printf("Integer 2: %d\n", *b);
}

void swap_integer(int *a, int *b)
{
    //swapping
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    //printing final
    //printing original
    printf("Integer 1 after swapping: %d\n", *a);
    printf("Integer 2 after swapping: %d\n", *b);
}