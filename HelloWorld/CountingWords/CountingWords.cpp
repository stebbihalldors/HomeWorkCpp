#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

void CountingWords(char* current, size_t length);

int main()
{
    char arr[]{ "Hello, my name is Marc.\n"};
    CountingWords(arr, size(arr));

}

void CountingWords(char* current, size_t length)
{
    printf("Input: %s", current);
    int countWords = 0;
    for (size_t i = 0; i < length; ++i)
    {
        if (current[i] == '\0')
            break;
        if (current[i] == ' ' || current[i] == '\t' || current[i] == '\n')
            countWords++;
    }

    printf("Output: %d", countWords);
}
