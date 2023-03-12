#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

void LeftShiftArr(int* current, size_t length);

int main()
{
    int const numberLength = 5;
    int arr[numberLength]{ 12,14,16,18,20};
    LeftShiftArr(arr, numberLength-1);

}

void PrintArray(int* current, size_t length)
{
    for (size_t i = 0; i < length; ++i)
        cout << current[i] << " ";
    cout << current[length] << endl;
}

void LeftShiftArr(int* current, size_t length)
{
    cout << "Before: ";
    PrintArray(current, length);
  

    cout << "After: ";
    int firstNumber = current[0];
    for (size_t i = 0; i < length; i++)
    {
        current[i] = current[i + 1];
    }
    current[length] = firstNumber;

    PrintArray(current, length);
}
