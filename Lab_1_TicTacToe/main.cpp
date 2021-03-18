#include "TICTACTOE.h"

int main() {
    // initializing variables to be used in main. the array, active player, inner game loop (play),
    // and outer game loop (gameLoop) are here.
    char tictactoeArray[SIZE];
    int activePlayer = playerOne;
    bool play = true;
    bool gameLoop = true;

    do {
        displayInstructions();
        initBoard(tictactoeArray, SIZE, play);
        do {
            showBoard(tictactoeArray, SIZE);
            getMove(tictactoeArray, activePlayer);
            playAgain(play, gameLoop, tictactoeArray);
        } while (play);
    } while (gameLoop);

    return 0;

}



