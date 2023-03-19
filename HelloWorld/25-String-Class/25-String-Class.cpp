#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <utility>
using namespace std;
#include "String.h"

int main()
{
    /* 
     //Tests for creating the String class..
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

    //Tests for copying the String class..
    String a{ "Hello", 15 };
    String c{ "World", 15 };
    a.Print(); // a is fine
    {
        String b = a;
        b = a;
        c = a;
        a.Print(); // a is still fine
        b.Print();
        c.Print();

        a.Append(" test");
        b.Append(" lest");
        c.Append(" hest");

        a.Print(); // a is still fine
        b.Print();
        c.Print();
    }
    a.Print(); // now, a is broken!! :o
    */

    //Tests for Moving the String class..
    vector<String> heroes;
    heroes.push_back(String{ "Hercules",100 });
    heroes.push_back(String{ "Odysseus",100 });
    {
        String prometheus{ "Prometheus",100 };
        heroes.push_back(std::move(prometheus));
    }
    return 0;
}