#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct 
{
    int id;
    char name[30];
    float salary;
} Employee;

int compare_by_salary(const void *a, const void *b); 

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    Employee **employee=(Employee **)malloc(n * sizeof(Employee*));
    for (int i = 0; i < n; i++) 
    {
        employee[i] = (Employee *)malloc(sizeof(Employee));
        printf("Enter details for employee %d (ID, Name, Salary):\n", i + 1);
        scanf("%d %s %f", &employee[i]->id, employee[i]->name, &employee[i]->salary);
    }
    qsort(employee, n, sizeof(Employee *), compare_by_salary);
    printf("\nEmployees sorted by salary:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employee[i]->id, employee[i]->name, employee[i]->salary);
    }
    for (int i = 0; i < n; i++) 
    {   
        free(employee[i]);
    }
    free(employee);
    return 0;
}

int compare_by_salary(const void *a, const void *b)
{
    const Employee *emp1 = *(const Employee **)a;
    const Employee *emp2 = *(const Employee **)b;
    if (emp1->salary < emp2->salary) 
        return -1;
    else if (emp1->salary > emp2->salary) 
        return 1;
    else 
        return 0;
}