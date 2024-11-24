#include <stdio.h>

typedef struct Employee
{
    char name[30];
    int id;
    float salary;
} Employee;

void store_records(const char *filename, Employee *employees, int n);
double total_salary(const char *filename);

int main()
{
    Employee employees[] = 
    {
        {"Osman", 12, 90000},
        {"Reham", 13, 30000},
        {"Ahmed", 14, 50000}
    };
    int n = sizeof(employees) / sizeof(employees[0]);
    const char *filename = "employee_salary.dat";

    store_records(filename, employees, n);
    double total = total_salary(filename);
    printf("Total Salary Expense: $%.2f\n", total);
    return 0;
}

void store_records(const char *filename, Employee *employees, int n)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(employees, sizeof(Employee), n, file);
    fclose(file);
}

double total_salary(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return 0;
    }
    Employee employee;
    double total = 0;
    while (fread(&employee, sizeof(Employee), 1, file))
    {
        total += employee.salary;
    }
    fclose(file);
    return total;
}
