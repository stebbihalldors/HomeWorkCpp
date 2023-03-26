#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <utility>
#include "String.h"
using namespace std;

int main()
{
    String yeah{ "Jebbsi",100 };
    cout << yeah;
    return 0;

    String tester{ "tester",100 };
    char fromIndex = tester[2];
    printf("test1: %c, Test2: %c\n", fromIndex, tester[0]);
    return 0;

    String test{ "test" ,100};
    String test2{ "test2", 100 };

    test = test + test2;
    test.Print();

    String test3{ "test3",100 };
    String test4{ "test4",100 };
    test3 += test4;
    test3.Print();
    return 0;
    
     //Tests for creating the String class..
    printf("Tests for creating the string class: \n");
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
    printf("\nTests for copying the string class: \n");
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
    

    //Tests for Moving the String class..
    printf("\nTests for Moving the string class: \n");
    vector<String> heroes;
    heroes.push_back(String{ "Hercules",100 });
    heroes.push_back(String{ "Odysseus",100 });
    {
        String prometheus{ "Prometheus",100 }; // Tests the move constructor
        prometheus = String{ "Testerino",100 }; // Tests the move assignment

        heroes.push_back(move(prometheus));
    }
    return 0;
}