#include<stdio.h>
#include<string.h>

#define max_car 50

void add_car(int *i);
void display_cars(int n);
void search_by_model(int n);
void search_by_make(int n);

typedef struct 
{
    char make[15];
    char model[10];
    int r_year;
    float price;
    float mileage;
} cars;
cars car[max_car];

int main()
{
    int a,n=0;
    //adding cars data
    do
    {
        add_car(&n);
        printf("\nPress 1-> Enter another car data.\t2-> No.");
        scanf("%d", &a);
    } while (a==1);
    //searching for the car
    int choice;
    do {
        printf("\nSearch options:\n");
        printf("    1 -> Search by make\n");
        printf("    2 -> Search by model\n");
        printf("    3 -> Display all cars\n");
        printf("    4 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                search_by_make(n);
                break;
            case 2:
                search_by_model(n);
                break;
            case 3:
                display_cars(n);
                break;
            case 4:
                printf("Exiting search.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);
    return 0;
}

void add_car(int *i)
{
    if(*i<max_car)
    {
    printf("Enter the manufacturer of the car: ");
    scanf("%14s", car[*i].make);
    printf("Enter the model no of the car: ");
    scanf("%9s", car[*i].model);
    printf("Enter the released year: ");
    scanf("%d", &car[*i].r_year);
    printf("Enter the price of the car: $");
    scanf("%f", &car[*i].price);
    printf("Enter the mileage of the car in Km: ");
    scanf("%f", &car[*i].mileage);
    (*i)++;
    }
    else
    {
        printf("Car limit reached to max.\n");
    }
}
void display_cars(int n)
{
    printf("\nList of available cars:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nDetails of car %d\n:", i+1);
        printf("    Make:    %s\n", car[i].make);
        printf("    Model:   %s\n", car[i].model);
        printf("    Year:    %d\n", car[i].r_year);
        printf("    Price:   $%.2f\n", car[i].price);
        printf("    Mileage: %.2fKm\n", car[i].mileage);
    }
}
void search_by_make(int n)
{
    char m[15];
    printf("Enter the manufacturer of the car: ");
    scanf("%14s", m);
    int count=1;
    printf("The list of cars manufactered by %s company: \n", m);
    for(int i=0;i<n;i++)
    {
        if(strcmp(m,car[i].make)==0)
        {
            printf("\nDetails of car %d\n:", count);
            printf("    Make:    %s\n", car[i].make);
            printf("    Model:   %s\n", car[i].model);
            printf("    Year:    %d\n", car[i].r_year);
            printf("    Price:   $%.2f\n", car[i].price);
            printf("    Mileage: %.2fKm\n", car[i].mileage);
            count++;
        }
    }
    if(count==1)
    {
        printf("No car %s is found", m);
    }
}
void search_by_model(int n)
{
    char mo[10];
    printf("Enter the model of the car: ");
    scanf("%9s", mo);
    int count=1;
    printf("The list of cars having model no %s: \n", mo);
    for(int i=0;i<n;i++)
    {
        if(strcmp(mo,car[i].model)==0)
        {
            printf("\nDetails of car %d\n:", count);
            printf("    Make:    %s\n", car[i].make);
            printf("    Model:   %s\n", car[i].model);
            printf("    Year:    %d\n", car[i].r_year);
            printf("    Price:   $%.2f\n", car[i].price);
            printf("    Mileage: %.2fKm\n", car[i].mileage);
            count++;
        }
    }
    if(count==1)
    {
        printf("No car is found that has a model no %s", mo);
    }
}