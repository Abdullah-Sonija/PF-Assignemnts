#include<stdio.h>
#include<string.h>

#define MAX_EMPLOYEES_IN_A_DEPARTMENT 20

double total_salary(Department *dept);

typedef struct Employee
{
    char name[30];
    int id;
    float salary;
    
}Employee;

typedef struct Department
{
    char name[30];
    double t_salary;
    int employee_count;
    Employee employee[MAX_EMPLOYEES_IN_A_DEPARTMENT];
}Department;

int main()
{
    //creating Department with 3 Employees
    Department dept1={"Sales",0,3, //department name, initial total salary, no of employee.
                        {
                            //name,id,salary
                            {"Ali",12,10000},
                            {"Mustafa",13,20000},
                            {"Rafay",14,5000}
                        }
    };
    //Calculating total salary
    dept1.t_salary=total_salary(&dept1);
    //Printing total salary
    printf("Department: %s\n", dept1.name);
    printf("Total Salary: $%.2f\n", dept1.t_salary);
    return 0;
}

double total_salary(Department *dept)
{
    double t_salary=0;
    for(int i=0;i<dept->employee_count;i++)
    {
        t_salary+=dept->employee[i].salary;
    }
    return t_salary;
}