#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void PrintMatchesLeft(int a);
int EasyAI(int matchesRemaining);
int Player(int matchesRemaining);

int main()
{
    bool playersTurn = true;
    int matchesLeft = 24;
   
    while(matchesLeft > 0)
    {
        PrintMatchesLeft(matchesLeft);

        switch (playersTurn)
        {
        case 0:
            matchesLeft = EasyAI(matchesLeft);
  
            break;
        case 1:
            matchesLeft = Player(matchesLeft);
            
            break;
        default:
            //throw error
            printf("Unhandled things fixit boyj");
            break;
        }
        playersTurn = !playersTurn;
        //matchesLeft = 0;
    }
    printf("Matches Left: %d \n", matchesLeft);
    if (playersTurn = false)
        printf("You WIN!");
    else
        printf("You LOSE!");
    return 0;
}

void PrintMatchesLeft(int a)
{
    printf("Matches Left: %d \n" , a);
    for (size_t i = a; i > 0; --i)
        printf("| ");
    printf("\n");
}

int EasyAI(int matchesRemaining)
{
    int ans;
    srand(time(0));

    if (matchesRemaining > 3)
        ans = (rand() % 3) + 1;
    else if (matchesRemaining == 2)
        ans = (rand() % 2) + 1;
    else
        ans = 1;
    printf("AI chooses: %d matches\n", ans);
    if (matchesRemaining == 1)
    {
        printf("Matches Left: %d \nYou Win!", 0);
        exit(0);
    }
        
    return matchesRemaining - ans;
}

int Player(int matchesRemaining)
{
    unsigned int ans;
    
    printf("How many matches would u like to take 1-3? \n");
    while (true)
    {
        scanf_s("%d", &ans);
        if (ans > 0 && ans < 4 && matchesRemaining > 2)
            return matchesRemaining-ans;
        else if(ans > 0 && ans < 3 && matchesRemaining == 2)
            return matchesRemaining-ans;
        else if(ans > 0 && ans < 2 && matchesRemaining == 1)
            printf("You Lose!");
        else
            printf("Error, Please pick a number between 1-3\n");
    }
    printf("You picked %d matches!", ans);
    return ans;
}