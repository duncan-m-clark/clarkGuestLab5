



typedef struct Game {
    ///@brief Tracks the current player's turn. X or O
    int turn;

    ///@brief The width of the game board
    int width;

    ///@brief the height of the game board
    int height;

    ///@brief The value within each cell. ASCII X or O. Values are in row-major order. 
    char cells[];
} Game, *Gamep;