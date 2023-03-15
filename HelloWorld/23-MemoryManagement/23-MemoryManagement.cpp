#include <iostream>
#include <cstdio>
using namespace std;

struct Person {
    char name[100];
};

void Peeps();
Person* GetName();

int main()
{
    Peeps();
}

Person* GetName() {
    Person* person = new Person();
    printf("What's the next person supposed to be called?\n");
    scanf_s("%s", person->name, 100);
    //scanf_s("%99[ˆ\n]%*c", person->name, 100);
    return person;
}

void Peeps()
{
    printf("How many people do you want to create?\n");
    int numberOfPeople;
    cin >> numberOfPeople;
    Person** names = new Person*[numberOfPeople];
    for (size_t i = 0; i < numberOfPeople; i++)
    {
        Person* person = GetName();
        names[i] = person;
    }

    printf("Total amount of people: %d\n", numberOfPeople);
    for (size_t i = 0; i < numberOfPeople-1; i++)
    {
        printf("%s, ", names[i]->name);
        delete names[i];
    }
    printf("%s\n", names[numberOfPeople-1]->name);
    delete names[numberOfPeople - 1];
    delete[] names;
}