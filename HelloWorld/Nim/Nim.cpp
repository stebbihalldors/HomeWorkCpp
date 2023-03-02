#include <iostream>
#include <cstdio>

void PrintMatchesLeft(int a);

int main()
{
    bool playersTurn = false;
    int matchesLeft = 24;
   
    while(matchesLeft > 0)
    {
        PrintMatchesLeft(matchesLeft);
        matchesLeft = 0;
    }
}

void PrintMatchesLeft(int a)
{
    printf("Matches Left: %d" , a);
    printf("| ");
}
