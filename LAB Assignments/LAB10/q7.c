#include <stdio.h>

#define METER_TO_KILOMETER 0.001

void convert_and_count(float meters);

int main() 
{
    float meters;
    int choice;
    do 
    {
        printf("\nEnter distance in meters: ");
        scanf("%f", &meters);

        convert_and_count(meters);

        printf("\nDo you want to convert another distance? (1-> Yes / 2-> No): ");
        scanf("%d", &choice);
    } while (choice == 1);
    return 0;
}

void convert_and_count(float meters) 
{
    static int call_count = 0;
    float kilometers = meters * METER_TO_KILOMETER;
    call_count++;
    printf("Distance in kilometers: %.3f\n", kilometers);
    printf("Function called %d time(s).\n", call_count);
}
