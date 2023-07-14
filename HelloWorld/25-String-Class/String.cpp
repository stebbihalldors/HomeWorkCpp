#include "String.h"
#include <cstdio>
#include <exception>
#include <string.h>

using namespace std;


String::String(const size_t maxsize) : buffer{ new char[maxsize] {} }, maxSize{ maxsize }, length{ 0 }
{
    printf("empty string is constructed!\n");
}
String::String(const char* defaultText, size_t maxsize) : buffer{ new char[maxsize] {} }, maxSize{ maxsize }, length{ 0 }
{
    printf("non-empty string is constructed: %s\n", defaultText);
    Append(defaultText);
}
String::~String()
{
    printf("String gets deconstructed\n");
    //delete buffer
    if (buffer) delete[] buffer;
}
String::String(const String& original) : length{ original.length }, maxSize{ original.maxSize }, buffer{ new char[original.maxSize] {} }
{
    printf("String %s gets copied to new instance.\n", original.buffer);
    Copy(original);
}

void String::Copy(const String& a) const 
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

String::String(String&& other) noexcept : maxSize{ other.maxSize }, length{other.length}, buffer{other.buffer}
{
    printf("Moving with move constructor: %s\n", other.buffer);
    other.buffer = nullptr;
}

String& String::operator=(String&& other) noexcept
{
    printf("Moving with operator: %s\n", other.buffer);
    if (this == &other) return *this;
    delete[] buffer;
    maxSize = other.maxSize;
    length = other.length;
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
}

void String::AppendLine(const char* text)
{
    Append(text);
    buffer[length] = '\n';
    length++;
    printf("length %d\n", length);
}

void String::Print() const
{
    printf("%s\n", buffer);
}

char* String::GetString() const
{
    //return buffer with \0?
    return buffer;
}

String String::operator+(const String& s) const
{
    memcpy(buffer + length, s.buffer, s.length);
    //length += charCounter;
   
    //printf("buffer: %s , s.buffer: %s\n", buffer, s.buffer);
    return String(buffer, maxSize);
}

String& String::operator+=(const String& s)
{
    memcpy(buffer + length, s.buffer, s.length);
    return *this;
}

char& String::operator[] (int i)
{
    //mayb dont need to tired to check atm
    if(i < 0 && i > maxSize)
        throw exception("out of bounds\n");

    return buffer[i];
}

ostream& operator<<(ostream& os, const String& s)
{
    return (os << "String: " << s.buffer << " Length: " << s.length << " MaxSize: " << s.maxSize << endl);
}