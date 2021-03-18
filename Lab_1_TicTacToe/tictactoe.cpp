//
// Created by lucas on 1/10/2021.
//

#include "TICTACTOE.h"

/*
 * displayInstructions outlines player actions and victory conditions.
 * */

void displayInstructions() {

    std::cout << "Welcome to Tic Tac Toe! To begin, player one will be X's and player two will be O's."
                 " You will be prompted to enter a board position to play on. The board positions are as follows:\n\n";

    std::cout << "[1][2][3] \n[4][5][6] \n[7][8][9] \n";

    std::cout << "\nTo win, you will need to get three of your character in a row horizontally, "
              << "vertically, or diagonally.\n\n";
    std::cout << "For example:\n\n";
    std::cout << "[X][X][X]   [X][2][3]   [X][2][3]\n"
                 "[4][5][6]   [X][5][6]   [4][X][6]\n"
                 "[7][8][9]   [X][8][9]   [7][8][X]\n";

}

/*
 * initBoard sets every array element to am empty space, and sets 'gameState' for inner game loop to true. this ensures
 * a clean board on each iterative game.
 * */

void initBoard(char array[], int arraySize, bool &gameState) {

    gameState = true;

    for (int i = 0; i < arraySize; i++) {
        array[i] = SPACE;
    }

}

/*
 * showBoard displays the current board state, breaking the display into three rows and columns
 * */

void showBoard(const char array[], int arraySize) {

    std::cout << "\n";
    std::cout << "Currently, the board looks like this: \n";
    std::cout << "\n";

    for (int i = 0; i < arraySize; i++) {
        std::cout << "[" << array[i] << "]";
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
        }
    }

    std::cout << "\n";

}

/*
 * getMove validates player input to determine the plays move, then switches the active player so
 * the next player can make their move.
 * */

void getMove(char array[], int &currentActivePlayer) {

    if (currentActivePlayer == playerOne) {
        array[validMove(array)] = X;
    }
    else if (currentActivePlayer == playerTwo) {
        array[validMove(array)] = O;
    }

    if (currentActivePlayer == playerOne) {
        currentActivePlayer = playerTwo;
    }
    else if (currentActivePlayer == playerTwo) {
        currentActivePlayer = playerOne;
    }

}

/*
 * checkWin determines if a win condition has been met and return true if a win condition is met.
 * */

bool checkWin(const char array[]) {

    if (array[0] == X && array[1]  == X && array[2]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[0] == O && array[1]  == O && array[2]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    else if (array[3] == X && array[4]  == X && array[5]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[3] == O && array[4]  == O && array[5]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    else if (array[6] == X && array[7]  == X && array[8]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[6] == O && array[7]  == O && array[8]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    if (array[0] == X && array[3]  == X && array[6]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[0] == O && array[3]  == O && array[6]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    else if (array[1] == X && array[4]  == X && array[7]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[1] == O && array[4]  == O && array[7]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    else if (array[2] == X && array[5]  == X && array[8]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[2] == O && array[5]  == O && array[8]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    else if (array[0] == X && array[4]  == X && array[8]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[0] == O && array[4]  == O && array[8]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }
    else if (array[2] == X && array[4]  == X && array[6]  == X) {
        std::cout << "Player one has won!\n";
        return true;
    }
    else if(array[2] == O && array[4]  == O && array[6]  == O) {
        std::cout << "Player two has won!\n";
        return true;
    }

    return false;

}

/*
 * checkTie checks the gamestate to determine if the game is a stalemate, ie, if every space is occupied but
 * there is no winner
 * */

bool checkTie(const char array[]) {

   if (array[0] != SPACE && array[1] != SPACE && array[2] != SPACE &&
       array[3] != SPACE && array[4] != SPACE && array[5] != SPACE &&
       array[6] != SPACE && array[7] != SPACE && array[8] != SPACE) {
       return true;
   }

    return false;
}

/*
 * playAgain is the iterative game loop that allows continued play. This loop will set both inner and out game
 * loops dependent on the users input.
 * */

void playAgain(bool &play, bool &gameLoop, const char array[]) {
    char keepPlaying;

    if (checkWin(array) && !checkTie(array)) {

        std::cout << "Would you like to play again?\n";
        std::cin >> keepPlaying;
        convert(keepPlaying);

        if (keepPlaying == 'Y') {
            play = false;
            gameLoop = true;
        } else if (keepPlaying == 'N') {
            play = false;
            gameLoop = false;
            std::cout << "Exiting game, thank you for playing!\n";
        } else {
            std::cout << "Logic error; exiting.\n";
            play = false;
        }
    }

    if (checkTie(array)) {
        std::cout << "This game has resulted in a tie.\n";
        std::cout << "Would you like to play again?\n";
        std::cin >> keepPlaying;
        convert(keepPlaying);

        if (keepPlaying == 'Y') {
            play = false;
            gameLoop = true;
        } else if (keepPlaying == 'N') {
            play = false;
            gameLoop = false;
            std::cout << "Exiting game, thank you for playing!\n";
        } else {
            std::cout << "Logic error; exiting.\n";
            play = false;
        }
    }
}

/*
 * validMove takes input from the user, comparing it against the board constraints of tic tac toe, and also
 * checking to see if the board position (array element) already contains a valid input.
 * */

int validMove (const char array[])
{
    int input;

    std::cout << "Please enter a valid move between position 1 and 9 on the board.\n";
    std::cin >> input;

    while (input > 9 || input < 1) {
        std::cout << "Please enter a valid move between position 1 and 9 on the board.\n";
        std::cin >> input;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(LARGE, END_LINE);
            std::cout << "Please enter a valid move between position 1 and 9 on the board.\n";
            std::cin >> input;
        }
    }

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(LARGE, END_LINE);
        std::cout << "Please enter a valid move between position 1 and 9 on the board.\n";
        std::cin >> input;
    }

    while (array[input - 1] != SPACE) {
        std::cout << "Please enter a valid (blank) move between position 1 and 9 on the board.\n";
        std::cin >> input;
    }

    return input - 1;

}

/*
 * The convert function takes a char input, passing it through the 'toupper' function resulting in lower case chars
 * becoming upper case chars.
 */

void convert (char& input) {
    input=toupper(input);
}
