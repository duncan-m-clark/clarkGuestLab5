/*
Ben Guest and Duncan Clark
Lab5
Dr. Guernsey 
10/27/2025
Project: tictactoe
*/

#include "game.h"

typedef struct TicTacToeGame {   
    int turn;
    int width;
    int height; 
    char cells[9]; 
} TicTacToeGame. TicTacToeGamep*;

/// dummy functions to see what functions we need

void game_enumerate_plays(void){
}

GameP game_init(void) {
    GameP game = (GameP) malloc(sizeof(TicTacToeGame));
    game->turn = 'X';
    game->width = 3;
    game->height = 3;
    for(int y = 0; y < 3; y++){
        for(int x= 0; x < 3; x++){
            game->cells[y*3 + x] = " "; //used to clear out and initalize the cells
        }
    }
}