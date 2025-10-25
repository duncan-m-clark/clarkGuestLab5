/*
Ben Guest and Duncan Clark
Lab5
Dr. Guernsey 
10/27/2025
Project: tictactoe
*/
#include <stdlib.h>
#include "game.h"

typedef struct TicTacToeGame {   
    int turn;
    int width;
    int height; 
    char cells[9]; //from our analysis, its an array indexed by row*3 + column
} TicTacToeGame, *TicTacToeGameP;

/// These are the functions we need to make. Function declarations
GameP game_init(void);
void game_enumerate_plays(void);
void game_play(void);


GameP game_init(void) { //game_init. Creates the game board and saves the state of the game through the turn int. 
    GameP game = (GameP) malloc(sizeof(TicTacToeGame));
    game->turn = 'X';
    game->width = 3;
    game->height = 3;
    for(int y = 0; y < 3; y++){
        for(int x= 0; x < 3; x++){
            game->cells[y*3 + x] = ' '; //used to clear out and initalize the cells
        }
    }
    return game;
}


void game_enumerate_plays(void){
}

void game_play(void) {

}