#include "DungeonCrawler.h"
#include <iostream>
#include <iomanip>
#include <ctime>

/*
 * showInstructions orients the player in the dungeon, telling the the win and fail conditions.
 */

void showInstructions() {

    std::cout << "Hello and welcome to your doom! Whether by fate or fiat, you have entered the \n";
    std::cout << "dungeon. To win, make your way to the treasure; with treasure comes the hope of \n";
    std::cout << "fortune. If you find a trap, you will instead find death. Your character is \n";
    std::cout << "represented with '@', traps with 'X', and the treasure with 'T'.\n\n";
    std::cout << "You have fallen into a random place in the dungeon. Good luck - you'll need it. \n";
    std::cout << "\nTo navigate the dungeon, you will use the 'W','A','S', and 'D' keys as shown below:\n\n";
    std::cout << std::setw(39) << "^\n";
    std::cout << std::setw(40) << "[W]\n";
    std::cout << std::setw(46) << " < [A]   [S] > \n";
    std::cout << std::setw(40) << " [D]\n";
    std::cout << std::setw(39) << "v\n";
    std::cout << "\nUse any key to continue.\n";
    std::cin.get();

}

/*
 * createDungeon uses random generation to assign position for treasure, traps, and the player character. It validates
 * the placement of each of these using loops.
 */

void createDungeon(char (&dungeonArray)[MAX_SIZE][MAX_SIZE], int num_trap_gen, int num_treasure_gen, char trap_char,
                   char treasure_char, char player_char, char exit_char, int player_pos_array[2], bool& game_state) {
    // set seed for random generation
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    // variables for use in loops
    int row = MAX_SIZE;
    int col = MAX_SIZE;
    int trap_count = 0;
    int treasure_count = 0;
    bool player_placed = false;
    bool exit_placed = false;
    game_state = true;
    // loop that fills the base board with the default dungeon tile
    for (int i = 0; i < row; i++) {

        for(int j = 0; j < col; j++) {

            dungeonArray[i][j] = dungeonDefTile;

        }

    }
    // loop that randomly generates trap placement
    while (trap_count < num_trap_gen) {

        if (dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] == dungeonDefTile) {

            dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] = trap_char;
            trap_count++;

        }

    }
    // loop that randomly generates treasure placement
    while (treasure_count < num_treasure_gen) {

        if (dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] == dungeonDefTile) {

            dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] = treasure_char;
            treasure_count++;

        }

    }
    // loop that assigns player position, checking to ensure it is an empty space before placing
    while (!player_placed) {

        if (dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] == dungeonDefTile) {
            dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] = player_char;
            // this loop updates the player_ppos_array to x,y coords of the player for later validation & safe updating
            for (int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if (dungeonArray[i][j] == player_char) {
                        player_pos_array[0] = i;
                        player_pos_array[1] = j;
                    }
                }
            }
            player_placed = true;
        }
    }
    /*
     * following code was for error checking boundaries
   dungeonArray[9][9] = player_char;
   player_pos_array[0] = 9;
   player_pos_array[1] = 9;
    */
    // this places the dungeon exit
    while (!exit_placed) {

        if (dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] == dungeonDefTile) {
            dungeonArray[rand() % MAX_SIZE][rand() % MAX_SIZE] = exit_char;
            exit_placed = true;
        }
    }

}

/*
 * displayDungeons draws the dungeon in rows and columns equal to MAX_SIZE using nested for loops
 */

void displayDungeon(const char dungeonArray[MAX_SIZE][MAX_SIZE]) {

    int row = MAX_SIZE;
    int col = MAX_SIZE;
    // draws the dungeon. the nested if will draw it in dimensions of max_size * max_size using modulus
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            std::cout << std::setw(3) << dungeonArray[i][j];
            if ((j + 1 )% MAX_SIZE == 0) {
                std::cout << "\n";
            }
        }
        if ((i + 1 )% MAX_SIZE == 0) {
            std::cout << "\n";
        }

    }

}

/*
 * getMove take the players input and verifies that input as a valid move both as an entry and as a move on the board.
 */

void getMove(char& player_move, const int player_pos_array[2], int player_pos_update[2]) {
    // set the updated position to the current position to ensure move checking and
    // moving is valid
    player_pos_update[0] = player_pos_array[0];
    player_pos_update[1] = player_pos_array[1];

    char input;
    // checks for valid w,a,s,d entry
    validateMove(input);
    // while loops checks the player input and the players board position, forcing the player to
    // choose a different move as long as it would place them out of bounds.
    while   (input == up && ((player_pos_array[0] - 1) < 0)     ||
            (input == left &&((player_pos_array[1] - 1) < 0))   ||
            (input == down && ((player_pos_array[0] + 1) > (MAX_SIZE - 1))) ||
            (input == right && ((player_pos_array[1] + 1) > (MAX_SIZE - 1)))) {

                std::cout << "You cannot move out of bounds\n";
                validateMove(input);
    }

    player_move = input;
    // switch statement to change the players position once a valid move is entered. commented co
    switch (input) {

        case up:

            std::cout << "You chose to move up.\n\n";
            //std::cout << "{" << player_pos_array[0] << "," << player_pos_array[1] << "}\n";
            player_pos_update[0] = player_pos_update[0] - 1;
            //std::cout << "{" << player_pos_update[0] << "," << player_pos_update[1] << "}\n";
            break;

        case left:

            std::cout << "You chose to move left.\n\n";
            //std::cout << "{" << player_pos_array[0] << "," << player_pos_array[1] << "}\n";
            player_pos_update[1] = player_pos_update[1] - 1;
            //std::cout << "{" << player_pos_update[0] << "," << player_pos_update[1] << "}\n";
            break;

        case down:

            std::cout << "You chose to move down.\n\n";
            //std::cout << "{" << player_pos_array[0] << "," << player_pos_array[1] << "}\n";
            player_pos_update[0] = player_pos_update[0] + 1;
            //std::cout << "{" << player_pos_update[0] << "," << player_pos_update[1] << "}\n";
            break;

        case right:

            std::cout << "You chose to move right.\n\n";
            //std::cout << "{" << player_pos_array[0] << "," << player_pos_array[1] << "}\n";
            player_pos_update[1] = player_pos_update[1] + 1;
            //std::cout << "{" << player_pos_update[0] << "," << player_pos_update[1] << "}\n";
            break;

        default:
            std::cout << "Bruh.\n\n";
            break;

    }



}
/*
 * checkMove evaluates the players position against elements in the array tha twould alter the gam state, ie
 * treasure, traps, and the exit. it will trigger the playAgain function if a win or loss condition is met to
 * determine if the player would like to continue.
 */
void checkMove(const char dungeonArray[MAX_SIZE][MAX_SIZE], int player_pos_updated[2], const char trap_char,
               const char treasure_char,  const char exit_char, bool& game_state, bool& cont_game) {
    // local variables used for altering the game flow
    bool dead = false;
    bool escape = false;
    bool continueGame;
    static int treasureCounter = 0;
    // determines if a player stepped on a trap, flagging the player as dead and setting their treasure to 0
    if (dungeonArray[player_pos_updated[0]][player_pos_updated[1]] == trap_char) {
        std::cout << "\nFool! You have stepped on a trap and died. Your entrails paint the floor,\n"
                  << "and your Game is Over.\n";
        dead = true;
        treasureCounter = 0;
    }
    // determines if a player collected treasure, incrementing the treasure counter
    if (dungeonArray[player_pos_updated[0]][player_pos_updated[1]] == treasure_char) {
        std::cout << "\nFor those with the nerve, the dungeon can yield untold treasures; it appears that\n"
                  << "you have the nerve.\n";
        treasureCounter++;
        std::cout << "\nYou have found " << treasureCounter << " treasures. These will fetch a high price _if_\n"
                  << "you escape.\n";
    }
    // determines if the player has reached the exit, and gives optional dialogue if they have treasures
    if (dungeonArray[player_pos_updated[0]][player_pos_updated[1]] == exit_char) {
        std::cout << "You have stumbled across the exit, adventurer. You wearily ascend the steps toward a distant\n"
                  << "pinprick of light. The sweet smell of fresh air wafts down the passage, imbuing your aching limbs\n"
                  << "with fresh energy. You have made your way out of the dungeon.\n";
            if (treasureCounter > 0) {
                std::cout << "\nYou have recovered " << treasureCounter << " treasures. These will fetch a high price at"
                << " the nearest settlement.\nPerhaps the risk was worth it after all.\n";
            }
        escape = true;
    }
    // calls playAgain if the player has died or escaped
    if (dead || escape) {
        continueGame = playAgain();
        if (continueGame) {
            game_state = false;
            cont_game = true;
        } else {
            game_state = false;
            cont_game = false;
        }
    }

}

/*
 * updateDungeon moves the player character visually by updating the position of the player_char in the dungeon
 * array, and overwrites the old location with the default dungeon tile.
 */

void updateDungeon(char (&dungeonArray)[MAX_SIZE][MAX_SIZE], int player_pos_array[2], int player_pos_updated[2],
                   const char player_char) {
    // couts were for visual confirmation and error checking
    //std::cout << "player pos array:\n";
    //std::cout << "{" << player_pos_array[0] << "," << player_pos_array[1] << "}\n";
    dungeonArray[player_pos_array[0]][player_pos_array[1]] = dungeonDefTile;
    //std::cout << "{" << player_pos_updated[0] << "," << player_pos_updated[1] << "}\n";
    dungeonArray[player_pos_updated[0]][player_pos_updated[1]] = player_char;
    player_pos_array[0] = player_pos_updated[0];
    player_pos_array[1] = player_pos_updated[1];

}

/*
 * playAgain takes the users input, validates it, and return the result of if they would like to play again.
 */

bool playAgain() {

    char play;

    std::cout << "\nWould you like to play again? (Y/N)\n";
    std::cin >> play;
    convert(play);

    while (play != 'y' && play != 'n') {
        std::cin.clear();
        std::cin.ignore(LARGE, END_LINE);
        std::cout << "\nWould you like to play again? (Y/N)\n";
        std::cin >> play;
        convert(play);
    }

    if (play == 'y') {
        std::cout << "Thank you for playing again, I knew you were strong enough. Regenerating dungeon.\n";
        return true;
    }
    else if (play == 'n') {
        std::cout << "Staying in the dungeon isn't for everyone.\n";
        return false;
    }
    else {
        std::cout << "Logic error. Exiting game.\n";
        return false;
    }

}

/*
 * convert input to lower case
 */

void convert (char& input) {
    input=tolower(input);
}

/*
 * validateMove ensures that a player is selecting a valid move condition w,a,s,d. other functions will compare that move
 * against the board and provide feedback
 */

char validateMove(char& player_input) {

    std::cout << "\nPick a direction for your character to move.\n";
    std::cin >> player_input;
    convert(player_input);

    while (player_input != 'w' && player_input != 'a' && player_input != 's' && player_input != 'd') {

        std::cin.clear();
        std::cin.ignore(LARGE, END_LINE);
        std::cout << "That was not a valid selection. Please navigate using W, A, S, or D.\n";
        std::cin >> player_input;
        convert(player_input);

    }

    return player_input;

}