#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
using namespace std;


class String {
private:
    int length;
    char* buffer;
    size_t maxSize;

public:
    String(size_t maxsize)
    {
        printf("empty string is constructed!\n");
        buffer = new char[maxsize]{};
        maxSize = maxsize;
        length = 0;
    }
    String(const char* defaultText, size_t maxsize)
    {
        printf("non-empty string is constructed: %s\n", defaultText);
        buffer = new char[maxsize]{};
        maxSize = maxsize;
        length = 0;
        Append(defaultText);
    }
    ~String()
    {
        printf("String gets deconstructed\n");
        //delete buffer
        delete[] buffer;
    }
    String(const String& original) 
    {
        printf("String %s gets copied to new instance.\n", original.buffer);
        length = original.length;
        maxSize = original.maxSize;
        buffer = new char[maxSize] {};
        Copy(original);
        
        printf("String %s gets copied to new instance.\n", buffer); 
    }
    
    void Copy(const String& a)
    {
        int counter = 0;
        while (*a.buffer != '\0') {
            buffer[counter] = a.buffer[counter];
            counter++;
        }
    }

    String& operator=(const String& other)
    {
        printf("String %s gets copied to an extisting instance(%s)\n", other.buffer, buffer);
        delete[] buffer;
        length = other.length;
        maxSize = other.maxSize;
        buffer = new char[maxSize];
        return *this;
    }

    void Append(const char* text)
    {  
        //iterate once to calculate the length
        //then memcpy to copy the whole block to the correct address
        //would i need then a temp to hold the pointer to the correct address?
        const char* temp = text;
        int charCounter{ 0 };
        while (*temp != '\0') {
            charCounter++;
            temp++;
        }
       
        if (maxSize < length+charCounter)
            throw exception("out of bounds\n");

        memcpy(buffer+length, text, charCounter);
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

    void AppendLine(char* text)
    {
        Append(text);
        buffer[length] = '\n';
        length++;
        printf("length %d\n", length);
    }

    void Print()
    {
        printf("%s\n", buffer);
    }

    char* GetString()
    {
        //return buffer with \0?
        return buffer;
    }
};

int main()
{/*
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
    
    
    //here for testing the copy and move if it all works.
    vector<String> heroes;
    heroes.push_back(String{ "Hercules",100 });
    heroes.push_back(String{ "Odysseus",100 });
    {
        String prometheus{ "Prometheus",100 };
        heroes.push_back(std::move(prometheus));
    }
    return 0;
    */

    String a{ "Hello", 7 };
    a.Print(); // a is fine
    {
        String b = a;
        b = a;
        a.Print(); // a is still fine
        b.Print();
    }
    a.Print(); // now, a is broken!! :o

}