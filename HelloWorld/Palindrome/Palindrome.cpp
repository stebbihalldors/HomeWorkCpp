#include <iostream>
#include <cstdio>
#include <array>
using namespace std;

bool Palindrome(char* arr, size_t length);

int main()
{
	int ans;
	char arr[]{ "anna" };
	printf("%d\n",Palindrome(arr, size(arr)));
	char arr2[]{ "stockholm" };
	printf("%d\n", Palindrome(arr2, size(arr2)));
}

bool Palindrome(char* arr, size_t length)
{
    char* front = arr - 1;
    char* back = arr + length - 1;

    while (--back > ++front)
    {
        if (*front != *back) return false;

        front++;
        back--;
    }
    return true;
}

