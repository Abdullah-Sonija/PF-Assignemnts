#include <stdio.h>

void input_array(int arr[], int n);
void bubble_sort(int arr[], int n);

int main() 
{
    int n;
    //making array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    //taking array elements
    input_array(arr, n);
    //sorting function
    bubble_sort(arr, n);
    //printing
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void input_array(int arr[], int n) 
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter the element # %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void bubble_sort(int arr[], int n) 
{
    if (n == 1) 
    {
        return;
    }
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] > arr[i + 1]) 
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubble_sort(arr, n - 1);
}