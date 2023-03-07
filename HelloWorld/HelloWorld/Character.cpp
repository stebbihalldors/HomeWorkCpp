
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char ans;
    int result;
AskAgain:
    printf("Give me a character.\n");
    result = scanf_s("%c", &ans, 100000);

    { // clear unparsed characters from the buffer
        char c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if (result != 1) goto AskAgain;

    if(ans == 'a')
        printf("Before that comes Z");
    else
        printf("Before that comes %c", toupper(ans - 1));
}
