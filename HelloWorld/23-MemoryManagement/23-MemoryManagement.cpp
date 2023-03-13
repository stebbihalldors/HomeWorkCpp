#include <iostream>
#include <cstdio>
using namespace std;

struct Person {
    //char* name = new char[100];
    char name[100];
};

void Peeps();
//char* GetName();
Person* GetName();

int main()
{
    Peeps();
}

Person* GetName() {
    Person* person = new Person();
    printf("What's the next person supposed to be called?\n");
    scanf_s("%s", person->name, 100);
    return person;
}

void Peeps()
{
    printf("How many people do you want to create?\n");
    int numberOfPeople;
    cin >> numberOfPeople;
    char** names = new char*[numberOfPeople];
    for (size_t i = 0; i < numberOfPeople; i++)
    {
        Person* person = GetName();
        names[i] = person->name;
    }

    printf("Total amount of people: %d\n", numberOfPeople);
    for (size_t i = 0; i < numberOfPeople-1; i++)
    {
        printf("%s, ", names[i]);
        delete names[i];
    }
    printf("%s\n", names[numberOfPeople-1]);
    delete names[numberOfPeople - 1];
    delete[] names;
}