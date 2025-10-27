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


void game_enumerate_plays(GameP game, Func print_play_func, void* user_data){ //Func* is a function pointer
    char* move_desc[] = { //descrptions of all the possible moves
        "Top left", "Top Center", "Top Right",
        "Middle Left", "Middle Center", "Middle Right",
        "Bottom Left", "Bottom Center", "Bottom Right"
    };

    for(int i =0; i < 9; i++){
        if(game->cells[i] == ' '){ //only print options if they are still open
            print_play_func(i, move_desc[i], user_data); //call helper function
        }
    }
    return; //done printing
}

int game_play(GameP game, int input) {
    ///TODO: move validation, update game board, and check winner.
    if (input < 0 || input >= 9) {
        return -1;
    }
    if (game->cells[input] != ' '){
        return -1;
    }
    game->cells[input] = game->turn;
    if (game->turn == 'X') {
        game->turn = 'O';
    }
    else {
        game->turn = 'X';
    }

    //Check Horizontals
    if (game->cells[0] == game->cells[1] &&
        game->cells[1] == game->cells[2] &&
        game->cells[0] != ' ') {
            return game->cells[0];
        }
    if (game->cells[3] == game->cells[4] &&
        game->cells[4] == game->cells[5] &&
        game->cells[3] != ' ') {
            return game->cells[3];
        }
    if (game->cells[6] == game->cells[7] &&
        game->cells[7] == game->cells[8] &&
        game->cells[6] != ' ') {
            return game->cells[6];
        }

    //Check Verticals
    if (game->cells[0] == game->cells[3] &&
        game->cells[3] == game->cells[6] &&
        game->cells[0] != ' ') {
            return game->cells[0];
        }
    if (game->cells[1] == game->cells[4] &&
        game->cells[4] == game->cells[7] &&
        game->cells[1] != ' ') {
            return game->cells[1];
        }
    if (game->cells[2] == game->cells[5] &&
        game->cells[5] == game->cells[8] &&
        game->cells[2] != ' ') {
            return game->cells[2];
        }

    //Check Diagonals
    if (game->cells[0] == game->cells[4] &&
        game->cells[4] == game->cells[8] &&
        game->cells[0] != ' ') {
            return game->cells[0];
        }
    if (game->cells[2] == game->cells[4] &&
        game->cells[4] == game->cells[6] &&
        game->cells[2] != ' ') {
            return game->cells[1];
        }

    //Check Tie
    for (int i = 0; i < 9; i++) {
        if (game->cells[i] == ' ') {
            return 0;
        }
    }

    return -2;
}