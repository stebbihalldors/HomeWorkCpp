#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

void Average(int* current, size_t length);

int main()
{
    int const numberLength = 9;
    int arr[numberLength];
    Average(arr, numberLength);

}

void Average(int* current, size_t length)
{
    float average = 0;
    for (size_t i = 0; i < length; ++i)
    {
        cout << "Please put " << length << " numbers! Number: " << i+1 << endl;
        scanf_s("%d", &current[i]);
        average += current[i];
    }
    cout << "The total of your entered numbers is: " << average << endl;
    cout << "The average of the "<< length << " numbers you entered is : " << average / length << endl;
}
