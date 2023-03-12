#include <iostream>
#include <cstdio>
#include <array>
using namespace std;

void ToUpper(char* arr, size_t length);

int main()
{
	int ans;
	char arr[]{ "anna" };
	ToUpper(arr, size(arr));
	char arr2[]{ "stockholm" };
	ToUpper(arr2, size(arr2));
}

void ToUpper(char* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = toupper(arr[i]);
	}

	printf("%s\n", arr);
}
