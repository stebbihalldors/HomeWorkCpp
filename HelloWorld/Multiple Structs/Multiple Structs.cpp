
#include <iostream>


struct Chest {
    int chestPositionX;
    int chestPositionY;
    bool chestCollected;
};
struct Key {
    int keyPositionX;
    int keyPositionY;
    bool keyCollected;
};
struct Goal {
    int goalPositionX;
    int goalPositionY;
    int goalWidthX;
    int goalHeightY;
};
struct Game {
    char playerName[10];
    int remainingMinutes;
    int playerScore;
    int playerPositionX;
    int playerPositionY;
    int playerVelocityX;
    int playerVelocityY;

    Chest chest;
    Key key;
    Goal goal;
};

int main()
{
    Game game;
    Game game2;
    game.playerScore = 25;
    game2.playerScore = 5;
    game.chest.chestCollected = 1;

    printf("Player1 score: %d \nPlayer2 score: %d \n", game.playerScore, game2.playerScore);
}
