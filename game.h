

typedef struct Game {
    ///@brief Tracks the current player's turn. X or O
    int turn;

    ///@brief The width of the game board
    int width;

    ///@brief the height of the game board
    int height;

    ///@brief The value within each cell. ASCII X or O. Values are in row-major order. 
    char cells[];
} Game, *GameP;


typedef void (*Func)(int move_num, char* move_desc, void * user_data);


/// These are the functions we need to make. Function declarations
GameP game_init(void);
void game_enumerate_plays(GameP game, Func print_play_func, void* user_data);
void game_play(void);