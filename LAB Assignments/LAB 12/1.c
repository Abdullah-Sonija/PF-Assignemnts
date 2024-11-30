#include<stdio.h>
#include<stdlib.h>

void reverse(int *array, int size);

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int *array=(int*)malloc(n * sizeof(int));
    if(array==NULL)
    {
        printf("Memory allocation failed.");
        return 0;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    reverse(array,n);
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}

void reverse(int *array, int size)
{
    int *start = array;
    int *end = array + size - 1;
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}