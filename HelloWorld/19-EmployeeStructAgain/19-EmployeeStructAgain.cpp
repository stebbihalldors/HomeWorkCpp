#include <iostream>

struct Employee {
    char Name[100];
    int Salary;
};

void PrintEmployeeName(Employee* arr, int size);
void AverageSalary(Employee* arr, int size);

int main()
{
    const int numberOfEmployees = 5;
    Employee emArr[numberOfEmployees];

    for (size_t i = 0; i < numberOfEmployees; i++)
    {
        Employee employee;
        printf("Please Enter a Employee%zu name: \n", i+1);
        scanf_s("%s", &employee.Name, 100);
        printf("Please Enter a Employee%zu salary: \n", i + 1);
        scanf_s("%d", &employee.Salary);

        emArr[i] = employee;
    }

    PrintEmployeeName(emArr, numberOfEmployees);
    AverageSalary(emArr, numberOfEmployees);
}

void PrintEmployeeName(Employee* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Employee%zu Name is: %s\n", i+1, arr[i].Name);
        printf("Employee%zu Salary is: %d\n", i+1, arr[i].Salary);
    }
}

void AverageSalary(Employee* arr, int size)
{
    float average = 0;
    printf("Input: ");
    for (size_t i = 0; i < size; ++i)
        average += arr[i].Salary;
    printf("\nThe total of your numbers is: %f\n", average);
    printf("The average salary is %f\n", average / size);
}
