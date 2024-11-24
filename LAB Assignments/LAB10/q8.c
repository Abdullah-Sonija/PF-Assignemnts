#include <stdio.h>

int linearSearch(int array[], int size, int target, int index);

int main() 
{
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Enter the target element to search for: ");
    scanf("%d", &target);
    int result = linearSearch(array, size, target, 0);
    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found in the array.\n", target);
    return 0;
}

int linearSearch(int array[], int size, int target, int index) 
{
    if (index == size) 
    {
        return -1;
    }
    if (array[index] == target) 
    {
        return index;
    }
    return linearSearch(array, size, target, index + 1);
}
