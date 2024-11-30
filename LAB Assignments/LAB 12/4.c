#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int sum = 0;
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of the first %d integers: %d\n", n, sum);
    //reallocate
    arr = (int *)realloc(arr, 2 * n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory reallocation failed.\n");
        return 1;
    }
    printf("Enter %d more integers:\n", n);
    for (int i = n; i < 2 * n; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum after adding %d more integers: %d\n", n, sum);
    free(arr);
    return 0;
}
