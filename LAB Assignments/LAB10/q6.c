#include<stdio.h>
#include<string.h>

#define MAX_PACKAGES 100

typedef struct Packages 
{
    char name[40];
    char destination[40];
    float duration;
    float cost;
    int a_seats;
} packages;

void booking(packages package[], int n);
void display(packages package[], int n);

int main() 
{
    packages package[MAX_PACKAGES];
    int n;
    printf("Enter the number of travel packages (max %d): ", MAX_PACKAGES);
    scanf("%d", &n);
    if (n <= 0 || n > MAX_PACKAGES) 
    {
        printf("Invalid number of packages.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        printf("\nPackage %d:\n", i + 1);
        printf("Enter package name: ");
        scanf(" %[^\n]s", package[i].name);
        printf("Enter destination: ");
        scanf(" %[^\n]s", package[i].destination);
        printf("Enter duration (in days): ");
        scanf("%f", &package[i].duration);
        printf("Enter cost: $");
        scanf("%f", &package[i].cost);
        printf("Enter available seats: ");
        scanf("%d", &package[i].a_seats);
    }
    int choice;
    do 
    {
        printf("\nTravel Package Booking System\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                display(package, n);
                break;
            case 2:
                booking(package, n);
                break;
            case 3:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

void display(packages package[], int n) 
{
    printf("\nList of Available Packages:\n");
    printf("ID  Name                  Destination     Duration  Cost($)  Seats\n\n");
    for (int i = 0; i < n; i++) 
    {
        if (package[i].a_seats > 0) 
        {
            printf("%-3d %-20s %-15s %-8.1f %-7.2f %-5d\n",
                   i + 1, package[i].name, package[i].destination,
                   package[i].duration, package[i].cost, package[i].a_seats);
        }
    }
    printf("\n");
}

void booking(packages package[], int n) 
{
    int package_id, seats_to_book;
    display(package, n);
    printf("Enter the ID of the package you want to book (1-%d): ", n);
    scanf("%d", &package_id);
    if (package_id < 1 || package_id > n) 
    {
        printf("Invalid package ID. Please try again.\n");
        return;
    }
    package_id--;
    if (package[package_id].a_seats == 0)
    {
        printf("Sorry, no seats are available for this package.\n");
        return;
    }
    printf("Enter the number of seats to book: ");
    scanf("%d", &seats_to_book);
    if (seats_to_book <= 0) 
    {
        printf("Invalid number of seats. Please try again.\n");
    } 
    else if (seats_to_book > package[package_id].a_seats) 
    {
        printf("Sorry, only %d seats are available.\n", package[package_id].a_seats);
    } else 
    {
        package[package_id].a_seats -= seats_to_book;
        printf("Successfully booked %d seat(s) for package: %s.\n",
               seats_to_book, package[package_id].name);
    }
}