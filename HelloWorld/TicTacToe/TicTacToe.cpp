#include <iostream>
#include <cstdio>
#include <cstdlib>

int CountEmptyCell();
void FillEmptyCell(int skip);
void AiRandom();
void AiHard();
bool Test(int a, int b, bool c, int counter);
bool Guess(char who);
void Attack();
int GameMode();
void Tie();
void Player(char whatPlayer);
void PrintOutGameBoard();
void SetGameBoard();
bool WinCondition();

char arr[3][3];
char lastToDo;
int countMoves = 0;


int main()
{
    srand(time(0));
    printf("Welcome to Tic-Tac-Toe!\n");
    SetGameBoard();
    int gameChoice = GameMode();

    //countMoves != 9
    while (true)
    {
        Player('X');
        PrintOutGameBoard();
        switch (gameChoice)
        {
        case 1:
            //Player vs player
            Player('O');
            PrintOutGameBoard();
            break;
        case 2:
            //Player vs AiRandom
            AiRandom();
            PrintOutGameBoard();
            break;
        case 3:
            //Player vs AiSkyNet
            AiHard();
            PrintOutGameBoard();
            break;
        }
    }
}

    int CountEmptyCell()
    {
        int emptyCount = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (arr[i][j] == ' ')
                    emptyCount++;
        return emptyCount;
    }

    void FillEmptyCell(int skip)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == ' ')
                {
                    if (skip == 0)
                    {
                        arr[i][j] = 'O';
                        return;
                    }
                    skip--;
                }
            }
    }

    void AiRandom()
    {
        printf("AI O:\n");
        lastToDo = 'O';
        //Check if empty for AI guess
        //int skip = Random.Shared.Next(0, CountEmptyCell());
        int skip = (rand() & CountEmptyCell());
        FillEmptyCell(skip);
        countMoves++;
    } //ans = (rand() % 3) + 1

    void AiHard()
    {
        bool playerWinCase = false;
        printf("AI O:\n");
        lastToDo = 'O';

        if (countMoves == 1)
        {
            //Cpu picks mid 1st move always when it can, else corner
            if (arr[1][1] == ' ')
            {
                arr[1][1] = 'O';
                playerWinCase = true;
            }
            else
            {
                //If player picked mid, then take corner
                arr[0][0] = 'O';
                playerWinCase = false;
            }
        }

        //if 2nd player move is arr[0,0] and arr[2,2] then its playerWinCase and defend until tie or player fails
        if (countMoves == 3)
        {
            if (arr[2][2] == 'X' && playerWinCase)
                arr[0][1] = 'O';
            else
            {
                //Check first if 'O' can win if not then check if 2'X' to block else attack
                if (!Guess('O'))
                    if (!Guess('X'))
                        Attack();
            }
        }
        else if (countMoves > 3)
        {
            //Check first if 'O' can win if not then check if 2'X' to block else attack
            if (!Guess('O'))
                if (!Guess('X'))
                    Attack();
        }
        countMoves++;
    }


    bool Guess(char who)
    {
        int tala1 = 0;
        int tala2 = 0;
        int tala3 = 0;
        int tala4 = 0;
        int tala5 = 0;
        int tala6 = 0;
        int tala7 = 0;
        int tala8 = 0;
        for (int i = 0; i < 3; i++)
        {
            int decreaser = 2;
            int winCounterRow = 0;
            int winCounterCol = 0;
            int winCounterDiagonal = 0;
            int winCounterOtherDiag = 0;
            bool hasEmpty = false;
            bool hasEmpty2 = false;
            bool hasEmpty3 = false;
            bool hasEmpty4 = false;
            for (int j = 0; j < 3; j++)
            {
                if (arr[j][i] == who)
                    winCounterCol++;
                else if (arr[j][i] == ' ')
                {
                    tala1 = j;
                    tala2 = i;
                    hasEmpty = true;
                }
                if (arr[i][j] == who)
                    winCounterRow++;
                else if (arr[i][j] == ' ')
                {
                    tala3 = i;
                    tala4 = j;
                    hasEmpty2 = true;
                }
                if (arr[j][j] == who)
                    winCounterDiagonal++;
                else if (arr[j][j] == ' ')
                {
                    tala5 = j;
                    tala6 = j;
                    hasEmpty3 = true;
                }
                if (arr[j][decreaser] == who)
                    winCounterOtherDiag++;
                else if (arr[j][decreaser] == ' ')
                {
                    tala7 = j;
                    tala8 = decreaser;
                    hasEmpty4 = true;
                }
                decreaser--;
            }

            if (winCounterCol == 2 && hasEmpty)
            {
                arr[tala1][tala2] = 'O';
                return true;
            }
            if (winCounterRow == 2 && hasEmpty2)
            {
                arr[tala3][tala4] = 'O';
                return true;
            }
            if (winCounterDiagonal == 2 && hasEmpty3)
            {
                arr[tala5][tala6] = 'O';
                return true;
            }
            if (winCounterOtherDiag == 2 && hasEmpty4)
            {
                arr[tala7][tala8] = 'O';
                return true;
            }
        }
        return false;
    }

    void Attack()
    {
        //Random when both 'X' And 'O' count are 1 
        //int skip = Random.Shared.Next(0, CountEmptyCell());
        int skip = (rand() & CountEmptyCell());
        FillEmptyCell(skip);
    }

    int GameMode()
    {
        while (true)
        {
            printf("Press '1' for 2player, Press '2' for RandomAI, Press '3' for HardAI\n");
            int gameChoice;
            scanf_s("%d", &gameChoice);
            if (gameChoice > 0 && gameChoice <= 3)
            {
                return gameChoice;
            }
            printf("Please use correct numbers!\n");
        }
    }

    void Tie()
    {
        printf("It's a TIE. Try again\n");
        exit(0);
    }

    void Player(char whatPlayer)
    {
        lastToDo = whatPlayer;
        while (true)
        {
            printf("In what column do you want to place your X (1-3)?\n");
            int playerAnsCol;
            scanf_s("%d", &playerAnsCol);
            printf("In what row do you want to place your X (1-3)?\n");
            int playerAnsRow;
            scanf_s("%d", &playerAnsRow);

            //Decrease to fit into right array slot
            playerAnsCol--;
            playerAnsRow--;

            if (playerAnsCol >= 0 && playerAnsCol < 3 && playerAnsRow >= 0 && playerAnsRow < 3)
            {
                if (arr[playerAnsRow][playerAnsCol] == ' ')
                {
                    arr[playerAnsRow][playerAnsCol] = whatPlayer;
                    countMoves++;
                    break;
                }
            }
            printf("That's already taken! try again\n");
            printf("Please enter numbers between 1-3!\n");
        }
        printf("Player %c\n", whatPlayer);
    }

    void PrintOutGameBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c",arr[i][j]);
                if (j != 2)
                    printf("|");
            }
            if (i != 2)
            {
                printf("\n");
                printf("-----\n");
            }
        }
        printf("\n");

        //Todo: Move to a better place...
        if (WinCondition())
        {
            printf("%c Wins!\n",lastToDo);
            exit(0);
        }
    }

    void SetGameBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = ' ';
                printf("%c",arr[i][j]);
                if (j != 2)
                {
                    printf("|");
                }
            }
            if (i != 2)
            {
                printf("\n");
                printf("-----\n");
            }
        }
        printf("\n");
    }

    bool WinCondition()
    {
        for (int i = 0; i < 3; i++)
        {
            int winCounterRow = 0;
            int winCounterCol = 0;
            int winCounterDiagonal = 0;
            int winCounterOtherDiag = 0;
            int decreaser = 2;
            for (int j = 0; j < 3; j++)
            {
                if (arr[j][i] == lastToDo)
                    winCounterCol++;
                if (arr[i][j] == lastToDo)
                    winCounterRow++;
                if (arr[j][j] == lastToDo)
                    winCounterDiagonal++;
                if (arr[j][decreaser] == lastToDo)
                    winCounterOtherDiag++;
                if (winCounterRow == 3 || winCounterCol == 3 || winCounterDiagonal == 3 || winCounterOtherDiag == 3)
                    return true;
                decreaser--;
            }
        }
        //count++ after each move or 
        //Change to CountEmptyCell() == 0 ?? but worse performance ?
        if (countMoves == 9)
            Tie();

        return false;
    }

