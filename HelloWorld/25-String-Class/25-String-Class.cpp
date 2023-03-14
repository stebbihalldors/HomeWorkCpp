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
        length = 0;
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
        //Need to test the length+length of text>maxsize then exception
        if (maxSize < length)
            throw exception("out of bounds");
       
        //add each char until \0 into buffer and then put length += text;
       // int numberOfChars = 0;
        while (*text != '\0') {
            buffer[length] = *text;
            length++;
            //numberOfChars++;
            
            text++;
        }
        printf("length %d\n", length);
       // length += numberOfChars;
    }

    void AppendLine(char* text)
    {

    }

    void Print()
    {
        printf("%s\n", buffer);
    }

    char* GetString()
    {
        return buffer;
    }
};

int main()
{
    char arr[]{ "anna" };
    String string(arr,100);

    string.Print();
    
    char arr2[]{ "test" };
    string.Append(arr2);
}