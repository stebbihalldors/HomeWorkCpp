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

    bool Test(int a, int b, bool c, int counter)
    {
        if (counter == 2 && c)
        {
            arr[a][b] = 'O';
            return true;
        }
        return false;
    }

    bool Guess(char who)
    {
        for (int i = 0; i < 3; i++)
        {
            int decreaser = 2;
            int winCounterRow = 0;
            int winCounterCol = 0;
            int winCounterDiagonal = 0;
            int winCounterOtherDiag = 0;
            for (int j = 0; j < 3; j++)
            {
                if (arr[j][i] == who)
                {
                    winCounterCol++;
                    if (winCounterCol == 2)
                        if (Test(j, i, true, winCounterCol))
                            return true;
                }
                else if (arr[j][i] == ' ')
                    if (Test(j, i, true, winCounterCol))
                        return true;
                if (arr[i][j] == who)
                {
                    winCounterRow++;
                    if (winCounterRow == 2)
                        if (Test(i, j, true, winCounterRow))
                            return true;
                }
                else if (arr[i][j] == ' ')
                    if (Test(i, j, true, winCounterRow))
                        return true;
                if (arr[j][j] == who)
                {
                    winCounterDiagonal++;
                    if (winCounterDiagonal == 2)
                        if (Test(j, j, true, winCounterDiagonal))
                            return true;
                }
                else if (arr[j][j] == ' ')
                    if (Test(j, j, true, winCounterDiagonal))
                        return true;
                if (arr[j][decreaser] == who)
                {
                    winCounterOtherDiag++;
                    if (winCounterOtherDiag == 2)
                        if (Test(j, decreaser, true, winCounterOtherDiag))
                            return true;
                }
                else if (arr[j][decreaser] == ' ')
                    if (Test(j, decreaser, true, winCounterOtherDiag))
                        return true;
                decreaser--;
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

