#include <stdio.h>

void horizontal_histogram(int values[], int count) 
{
    for (int i = 0; i < count; i++) 
    {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) 
        {
            printf("*");
        }
        printf("\n");
    }
}

void vertical_histogram(int values[], int count) 
{
    int max_value = 0;

    for (int i = 0; i < count; i++) 
    {
        if (values[i] > max_value) 
        {
            max_value = values[i];
        }
    }

    for (int row = max_value; row > 0; row--) 
    {
        for (int i = 0; i < count; i++) 
        {
            if (values[i] >= row) 
            {
                printf("* ");
            } else 
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < count; i++) 
    {
        printf("%d ", values[i]);
    }
    printf("\n");
}

int main() 
{
    int count;

    printf("Enter the number of values: ");
    scanf("%d", &count);

    int values[count];

    for (int i = 0; i < count; i++) 
    {
        printf("Enter the values %d: ", i+1);
        scanf("%d", &values[i]);
    }

    printf("\nHorizontal Histogram\n");
    horizontal_histogram(values, count);

    printf("\nVertical Histogram\n");
    vertical_histogram(values, count);

    return 0;
}
