
#include <iostream>

struct Employee {
    int personnummer;
    int phoneNumber;
    char firstName[10];
    char lastName[10];
    int joinDate;
    char gender;
    int salary;
};

int main()
{
    std::cout << "Hello World!\n";
}

/*Build a struct that can store the following information:

We need a struct that can store an Employee's information. 
It needs to contain their Personnummer in the format 
e.g. 9008111234. Their Phone Number in the format 
e.g. 0708444780. Their First and Last Name. 
The Date they joined the company. 
Their Gender (sorry, we're as old-fashioned as C++).
His Address. His Salary.*/