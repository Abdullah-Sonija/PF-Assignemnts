#include<stdio.h>

#define max_temp 30

void temp_check(float temp);

int main()
{
    float temp;
    int n;
    printf("How many temperatures you will enter?");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the temperature %d in celsius: ", i+1);
        scanf("%f", &temp);
        temp_check(temp);
    }
    return 0;
}

void temp_check(float temp)
{
    static int count=0;
    if(temp>max_temp)
    {
        count++;
        printf("Temperature %.2f°C exceeds the maximum allowable limit of %d°C.\n", temp, max_temp);
    }
    else
    {
        printf("Temperature %.2f°C is within the safe limit.\n", temp);
    }
    printf("The maximum temperature has been exceeded %d times.\n\n", count);   
}