#include <iostream>
#include <cstdio>
#include <array>
using namespace std;


class String {
private:
    int length;
    char* buffer;
    size_t maxSize;

public:
    String(size_t maxsize)
    {
        printf("empty string is constructed!");
        buffer = new char[maxsize];
        maxSize = maxsize;
        length = 0;
    }
    String(char* defaultText, size_t maxsize)
    {
        printf("non-empty string is constructed: %s\n", defaultText);
        buffer = new char[maxsize];
        maxSize = maxsize;
        Append(defaultText);
    }
    ~String()
    {
        printf("String gets deconstructed");
        //delete buffer
        delete[] buffer;
    }

    void Append(char* text)
    {
        if (maxSize < length)
            throw exception("out of bounds");
       
        int numberOfChars = 0;
        while (*text != '\0') {
            buffer[length] = *text;
            numberOfChars++;

            text++;
        }
        length += numberOfChars;
    }

    void AppendLine(char* text)
    {

    }

    void Print()
    {
        printf("%s", buffer-(maxSize-length));
    }

    char* GetString()
    {
        return buffer;
    }
};

int main()
{
    char arr[]{ "anna" };
    String string(arr,size(arr));

    string.Print();
}