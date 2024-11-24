#include<stdio.h>

void input(int array[],int*n);
void finding(int array[],int n, int *max,int *min);

int main()
{
    int n;
    int array[100];
    int min, max;
    input(array,&n);
    finding(array, n, &max, &min);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    return 0;
}

void input(int array[],int *n)
{
    printf("Enter the number of integer you wil enter: ");
    scanf("%d", n);
    for(int i=0;i<*n;i++)
    {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &array[i]);
    }
}
void finding(int array[],int n, int *max,int *min)
{
    *max = array[0];
    *min = array[0];
    for (int i=1;i<n;i++) 
    {
        if (array[i]>*max) 
        {
            *max=array[i];
        }
        if (array[i]<*min) 
        {
            *min=array[i];
        }
    }
}
