#include <iostream>
#include <cstdio>
#include <array>
#include <stdio.h>
#include <string.h>
using namespace std;

int Palindrome(char* arr, size_t length);

int main()
{
	int ans;
	char arr[]{ "anna" };
	printf("%d\n",Palindrome(arr, size(arr)));
	char arr2[]{ "stockholm" };
	printf("%d\n", Palindrome(arr2, size(arr2)));
}

int Palindrome(char* arr, size_t length)
{
	char* front = arr;
	char* back = arr + length-1;
	for (size_t i = 0; i < length; i++)
	{
		if (*front == *back)
		{
			front++;
			back--;
		}
		else
			break;
	}

	if (front > back)
		return 1;
	else
		return 0;
}

