#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger
{
    int passenger_id;
    char name[100];
    char sex[10];
    int age;
    int survived;
    int pclass;
    float fare;
    char cabin[20];
} Passenger;

void load_data(FILE *file, Passenger passengers[], int *count);
void calculate_average_age(Passenger passengers[], int count);
void calculate_survival_rate(Passenger passengers[], int count);
void display_survived_passengers(Passenger passengers[], int count);
void display_missing_cabin(Passenger passengers[], int count);

int main() 
{
    Passenger passengers[MAX_PASSENGERS];
    int count = 0;
    FILE *file = fopen("titanic.csv", "r");
    if (file == NULL) 
    {
        printf("Error opening file\n");
        return 1;
    }
    load_data(file, passengers, &count);
    fclose(file);

    calculate_average_age(passengers, count);
    calculate_survival_rate(passengers, count);
    display_survived_passengers(passengers, count);
    display_missing_cabin(passengers, count);

    return 0;
}

void load_data(FILE *file, Passenger passengers[], int *count) 
{
    char line[256];
    fgets(line, sizeof(line), file); // Skip header row

    while (fgets(line, sizeof(line), file)) 
    {
        sscanf(line, "%d,%99[^,],%9[^,],%d,%d,%d,%f,%19s",
               &passengers[*count].passenger_id,
               passengers[*count].name,
               passengers[*count].sex,
               &passengers[*count].age,
               &passengers[*count].survived,
               &passengers[*count].pclass,
               &passengers[*count].fare,
               passengers[*count].cabin);

        (*count)++;
    }
}

void calculate_average_age(Passenger passengers[], int count) 
{
    int total_age = 0;
    int valid_count = 0;
    for (int i = 0; i < count; i++) 
    {
        if (passengers[i].age > 0) 
        {
            total_age += passengers[i].age;
            valid_count++;
        }
    }
    if (valid_count > 0) 
    {
        printf("Average age of passengers: %.2f\n", (float)total_age / valid_count);
    } 
    else 
    {
        printf("No valid age data available\n");
    }
}

void calculate_survival_rate(Passenger passengers[], int count) 
{
    int survived_count = 0;
    int total_count = 0;
    for (int i = 0; i < count; i++) 
    {
        if (passengers[i].survived == 1) 
        {
            survived_count++;
        }
        if (passengers[i].survived >= 0) 
        {
            total_count++;
        }
    }
    if (total_count > 0) 
    {
        printf("Survival rate: %.2f%%\n", (float)survived_count / total_count * 100);
    } 
    else 
    {
        printf("No survival data available\n");
    }
}

void display_survived_passengers(Passenger passengers[], int count) 
{
    printf("\nList of Survived Passengers:\n");
    printf("ID  Name                   Age  Class  Fare\n");
    for (int i = 0; i < count; i++) 
    {
        if (passengers[i].survived == 1) 
        {
            printf("%-3d %-20s %-4d %-6d %-7.2f\n", 
                   passengers[i].passenger_id, passengers[i].name,
                   passengers[i].age, passengers[i].pclass, passengers[i].fare);
        }
    }
}

void display_missing_cabin(Passenger passengers[], int count) 
{
    printf("\nPassengers with Missing Cabin Details:\n");
    printf("ID  Name                   Age  Class  Fare\n");
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(passengers[i].cabin, "") == 0) 
        {
            printf("%-3d %-20s %-4d %-6d %-7.2f\n", 
                   passengers[i].passenger_id, passengers[i].name,
                   passengers[i].age, passengers[i].pclass, passengers[i].fare);
        }
    }
}
