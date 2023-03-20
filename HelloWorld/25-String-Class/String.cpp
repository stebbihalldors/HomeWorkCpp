#include "String.h"
#include <cstdio>
#include <exception>
#include <string.h>

using namespace std;


String::String(size_t maxsize)
{
    printf("empty string is constructed!\n");
    buffer = new char[maxsize] {};
    maxSize = maxsize;
    length = 0;
}
String::String(const char* defaultText, size_t maxsize)
{
    printf("non-empty string is constructed: %s\n", defaultText);
    buffer = new char[maxsize] {};
    maxSize = maxsize;
    length = 0;
    Append(defaultText);
}
String::~String()
{
    printf("String gets deconstructed\n");
    //delete buffer
    if (buffer) delete[] buffer;
}
String::String(const String& original)
{
    printf("String %s gets copied to new instance.\n", original.buffer);
    length = original.length;
    maxSize = original.maxSize;
    buffer = new char[original.maxSize] {};
    Copy(original);
}

void String::Copy(const String& a)
{
    char* temp = a.buffer;
    int count = 0;
    while (*temp != '\0') {
        buffer[count] = *temp;
        count++;
        temp++;
    }
}

String& String::operator=(const String& other)
{
    if (this == &other) return *this;
    printf("String %s gets copied to an extisting instance(%s)\n", other.buffer, buffer);
    delete[] buffer;
    length = other.length;
    maxSize = other.maxSize;
    buffer = new char[maxSize] {};
    Copy(other);
    return *this;
}

String::String(String&& other) noexcept
{
    printf("Moving %s\n", other.buffer);
    maxSize = other.maxSize;
    length = other.maxSize;
    buffer = other.buffer;
    other.buffer = nullptr;
}

String& String::operator=(String&& other) noexcept
{
    if (this == &other) return *this;
    maxSize = other.maxSize;
    length = other.maxSize;
    buffer = other.buffer;
    other.buffer = nullptr;
    return *this;
}

void String::Append(const char* text)
{
    //iterate once to calculate the length
    //then memcpy to copy the whole block to the correct address
    //I need then a temp to move the pointer to the end of string
    const char* temp = text;
    int charCounter{ 0 };
    while (*temp != '\0') {
        charCounter++;
        temp++;
    }

    if (maxSize < length + charCounter)
        throw exception("out of bounds\n");

    memcpy(buffer + length, text, charCounter);
    length += charCounter;
    printf("length: %d\n", length);

    /*
    //add each char until \0 into buffer and add length += text;
    while (*text != '\0') {
        if (maxSize < length)
            throw exception("out of bounds\n");
        buffer[length] = *text;
        length++;
        text++;
    }
    printf("length %d\n", length);
    */
}

void String::AppendLine(char* text)
{
    Append(text);
    buffer[length] = '\n';
    length++;
    printf("length %d\n", length);
}

void String::Print()
{
    printf("%s\n", buffer);
}

char* String::GetString()
{
    //return buffer with \0?
    return buffer;
}