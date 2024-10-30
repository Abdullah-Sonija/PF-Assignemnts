//Finding the second smallest element in an array.
#include <stdio.h>
int main()
{
    int size,i;
    do
    {
        printf("Enter the size of array: ");
        scanf("%d", &size);
    } while (size<2);
    
    
    int array[size];

    //Input elements
    for(i=0;i<size;i++)
    {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &array[i]);
    }

    //finding second smallest
    int smallest=__INT_MAX__;
    int second_smallest=__INT_MAX__;
    for(i=0;i<size;i++)
    {
        if(array[i]<smallest)
        {
            second_smallest=smallest;
            smallest=array[i];
        }
        else if(array[i]<second_smallest&&array[i]!=smallest)
        {
            second_smallest=array[i];
        }
    }
    if(second_smallest==__INT_MAX__)
    {
        printf("All the elements are equal.\n");
    }
    else
    {
        printf("The second smallest number is %d\n", second_smallest);
    }
    return 0;
}