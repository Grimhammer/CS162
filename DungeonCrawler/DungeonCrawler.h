#ifndef DUNGEONCRAWLER_DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_DUNGEONCRAWLER_H
#include <limits>
#include <iostream>
const unsigned long long LARGE = std::numeric_limits<std::streamsize>::max();
const int   MAX_SIZE = 10, num_trap = 4, num_treasure = 2;
const char  END_LINE = '\n', dungeonDefTile = '.', treasure = 'T', trap = 'X', player = '@', exitC = 'E', up = 'w', left = 'a',
            down = 's', right = 'd';

void showInstructions();
void createDungeon(char (&dungeonArray)[MAX_SIZE][MAX_SIZE], const int num_trap_gen, const int num_treasure_gen, const char trap_char,
                   const char treasure_char, const char player_char, const char exit_char, int player_pos_array[2], bool& game_state);
void displayDungeon(const char dungeonArray[MAX_SIZE][MAX_SIZE]);
void getMove(char& player_move, const int player_pos_array[2], int player_pos_update[2]);
void checkMove(const char dungeonArray[MAX_SIZE][MAX_SIZE], int player_pos_updated[2], const char trap_char,
               const char treasure_char,  const char exit_char, bool& game_state, bool& cont_game);
void updateDungeon(char (&dungeonArray)[MAX_SIZE][MAX_SIZE], int player_pos_array[2], int player_pos_updated[2],
                   const char player_char);
bool playAgain();
void convert (char& input);
char validateMove(char& player_input);

#endif //DUNGEONCRAWLER_DUNGEONCRAWLER_H
