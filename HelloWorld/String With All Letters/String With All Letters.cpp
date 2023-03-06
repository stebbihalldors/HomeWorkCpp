#include <iostream>
#include <cstdio>

void PrintOutAlphabet();

int main()
{
	PrintOutAlphabet();
	return 0;
}

void PrintOutAlphabet()
{
	int const alphabetCount = 26;
	char text[alphabetCount] = { };

	for (size_t i = 0; i < alphabetCount; ++i)
	{
		text[i] = 65+i;
	}
	//text[alphabetCount] = 0;
		printf("%s ", text);
}