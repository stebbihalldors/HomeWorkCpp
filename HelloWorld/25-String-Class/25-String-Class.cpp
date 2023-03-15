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
        buffer = new char[maxsize]{};
        maxSize = maxsize;
        length = 0;
    }
    String(char* defaultText, size_t maxsize)
    {
        printf("non-empty string is constructed: %s\n", defaultText);
        buffer = new char[maxsize]{};
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
       
        //add each char until \0 into buffer and add length += text;
        while (*text != '\0') {
            buffer[length] = *text;
            length++;
            text++;
        }
        printf("length %d\n", length);
    }

    void AppendLine(char* text)
    {
        /*
        while (*text != '\0') {
            buffer[length] = *text;
            length++;
            text++;
        }*/
        Append(text);
        buffer[length] = '\n';
        length++;
        printf("length %d\n", length);
    }

    void Print()
    {
        /*
        for (size_t i = 0; i < length; i++)
            printf("%c", buffer[i]);
        printf("\n");
        */
        printf("%s\n", buffer);
    }

    char* GetString()
    {
        //return buffer with \0? and some cost or something so they cant change the values of the string with the pointer
        return buffer;
    }
};

int main()
{
    char arr[]{ "anna" };
    String string(arr,100);
    printf("%s", string.GetString());
    string.Print();
    
    char arr2[]{ "test" };
    string.Append(arr2);
    string.Print();
    
    char arr3[]{ "test3" };
    string.AppendLine(arr3);
    string.Print();

}