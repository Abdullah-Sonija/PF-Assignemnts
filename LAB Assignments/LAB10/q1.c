#include<stdio.h>


void array_printing(int array[],int index,int size);

int main()
{
    int n;
    printf("Enter no of elements you want to insert.");
    scanf("%d", &n);
    int array[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d element of the array: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Elements of the array.\n");
    array_printing(array,0,n);      
    return 0;
}

void array_printing(int array[],int index,int size)
{
    if(index==size)
    {
        return;
    }
    printf("%d\n", array[index]);
    array_printing(array,index+1,size);
}