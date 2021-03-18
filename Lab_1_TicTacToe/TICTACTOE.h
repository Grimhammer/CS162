//
// Created by lucas on 1/10/2021.
//

#ifndef LAB_1_TICTACTOE_TICTACTOE_H
#define LAB_1_TICTACTOE_TICTACTOE_H

#include <iostream>
#include <limits>
//function prototypes
void displayInstructions();
void initBoard(char array[], int arraySize, bool &gameState);
void showBoard(const char array[], int arraySize);
void getMove(char array[], int &currentActivePlayer);
bool checkWin(const char array[]);
bool checkTie(const char array[]);
void playAgain(bool &play, bool &gameLoop, const char array[]);
int validMove (const char array[]);
void convert (char& input);
//variable declarations
const int SIZE = 9;
const unsigned long long LARGE = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';
const char X = 'X';
const char O = 'O';
const char SPACE = ' ';
const int playerOne = 1;
const int playerTwo = 2;

#endif //LAB_1_TICTACTOE_TICTACTOE_H
