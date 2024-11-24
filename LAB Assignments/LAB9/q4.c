#include<stdio.h>

void input2numbers(int *a,int *b);
void operation(int a,int b);

int main()
{
    int a, b;
    input2numbers(&a,&b);
    operation(a,b);    
    return 0;
}

void input2numbers(int *a,int *b)
{
    
    printf("Enter the first number: ");
    scanf("%d", a);
    printf("Enter the second number: ");
    scanf("%d", b);
}
void operation(int a,int b)
{
    //operation choice
    int c;
    int answer;
    printf("Select your choice:");
    printf("1->Addition\n2->Subtraction\n3->Multiplication\n4->Division\n");
    scanf("%d", &c);
    //operation
    switch (c)
    {
    case 1:
        answer=a+b;
        printf("Sum = %d\n", answer);
        break;
    case 2:
        answer=a-b;
        printf("Subtracted answer = %d\n", answer);
        break;
    case 3:
        answer=a*b;
        printf("Product = %d\n", answer);
        break;
    case 4:
        if(b!=0)
        {
            float Answer=(float)a/b;
            printf("Quotient = %.2f\n", Answer);
        }
        else
        {
            printf("Invalid divisor.\n\n");
        }
        break;
    default:
        printf("Error, Invalid input.\n");
        break;
    }
}