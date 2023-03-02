#include <iostream>
#include <cstdio>

void PrintMatchesLeft(int a);
int EasyAI();
int Player();

int main()
{
    bool playersTurn = false;
    int matchesLeft = 24;
    PrintMatchesLeft(matchesLeft);
   
    while(matchesLeft > 0)
    {

        switch (playersTurn)
        {
        case 0:
            EasyAI();
            break;
        case 1:
            Player();
        default:
            //throw std::error
            printf("Unhandled things fixit boyj");
            break;
        }
        PrintMatchesLeft(matchesLeft);


        matchesLeft = 0;
    }
    return 0;
}

void PrintMatchesLeft(int a)
{
    printf("Matches Left: %d \n" , a);
    for (std::size_t i = a; i > 0; ++i)
        printf("| ");
}

int EasyAI()
{
    return 0;
}

int Player()
{
    return 0;
}