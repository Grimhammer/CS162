#include <iostream>
#include "DungeonCrawler.h"

int main() {
    // this is the dungeon of dimension max_size * max_size
    char dungeon[MAX_SIZE][MAX_SIZE];
    // the player_pos array stores the x,y coordinates of the player
    int player_pos[2];
    // player_pos_update is used for comparing the current player pos to the updated pos for validation & safe update purposes
    int player_pos_update[2];
    char movement;
    // bools for inner and outer game loop. playing checks current game state, play_again is used to play another fresh game
    bool playing = true;
    bool play_again = true;

    showInstructions();

    do {
        createDungeon(dungeon, num_trap, num_treasure, trap, treasure, player, exitC, player_pos, playing);
        do {
            displayDungeon(dungeon);
            getMove(movement, player_pos, player_pos_update);
            checkMove(dungeon, player_pos_update, trap, treasure, exitC, playing, play_again);
            updateDungeon(dungeon,player_pos,player_pos_update,player);
        } while (playing);
    } while (play_again);

}
