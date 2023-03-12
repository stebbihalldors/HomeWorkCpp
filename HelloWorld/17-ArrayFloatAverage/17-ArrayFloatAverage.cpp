#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

void Average(float* current, size_t length);

int main()
{
    int const numberLength = 5;
    float arr[numberLength]{ 1,2,3,4,5 };
    Average(arr, numberLength);

}

void Average(float* current, size_t length)
{
    float average = 0;
    cout << "Input: ";
    for (size_t i = 0; i < length; ++i)
    {
        cout << current[i] << " ";
        average += current[i];
    }
    cout << endl;
    cout << "The total of your numbers is: " << average << endl;
    cout << "The average of the " << length << " numbers you entered is : " << average / length << endl;
}
