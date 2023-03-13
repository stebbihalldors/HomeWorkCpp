#include <iostream>
#include <cstdio>
using namespace std;

void Peeps();
char* GetName();

struct Person {
    char* name = new char[100];
};

int main()
{
    Peeps();
}

char* GetName() {
    Person person;
    printf("What's the next person supposed to be called?\n");
    scanf_s("%s", person.name, 100);
    return person.name;
}

void Peeps()
{
    printf("How many people do you want to create?\n");
    int numberOfPeople;
    cin >> numberOfPeople;
    char** names = new char*[numberOfPeople];
    for (size_t i = 0; i < numberOfPeople; i++)
    {
        char* name = GetName();
        names[i] = name;
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