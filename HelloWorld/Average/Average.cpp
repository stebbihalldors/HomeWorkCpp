#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

void Average(int* current, size_t length);

int main()
{
    int arr[9];
    Average(arr, 9);

}

void Average(int* current, size_t length)
{
    float average = 0;
    for (size_t i = 0; i < length; ++i)
    {
        cout << "Please put 9 numbers! Number: " << i+1 << endl;
        scanf_s("%d", &current[i]);
        average += current[i];
    }
    cout << "The average of the 9 numbers you entered is: " << average / length << endl;

   /* for (size_t i = 0; i < length; i++)
    {
        cout << current[i] << endl;
    }*/
   
}
