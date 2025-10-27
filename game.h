/**
 * @file game.h
 * @brief Header file declaring the interface of the game
 * @authors Ben Guest, Duncan Clark
 */

 /**
  * @struct Game
  * @brief A struct object to track the game state
  * @note Game stores the height and width of the game board
  * and the player whose turn it is. Game also stores an
  * array representing the game board, whose indices store
  * previous moves or and still empty spaces.
  */
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

/**
 * @typedef (*Func)(int move_num, char* move_desc, void* user_data)
 * @brief A function declaration to create options for a player's turn
 * @param move_num The number to accompany a turn option
 * @param move_desc The turn option
 * @param user_data User context if necessary
 * @note This function accepts a number to use as a label for a
 * turn option, a message to describe the turn option to the player,
 * and an untyped parameter that is available if user data
 * is necessary to provide context for the function.
 * @example Func(1, "Top Left", user_data)
 * In the example above, "1. Top Left" is provided as a turn option
 * to the player whose turn it currently is
 */
typedef void (*Func)(int move_num, char* move_desc, void* user_data);

/**
 * @fn GameP game_init(void)
 * @brief Initializes the game state
 * @returns GameP object
 * @note game_init() accepts no parameters and returns a GameP object
 * describing the state of the game as outlined in the definition of
 * the Game struct
 * @sa typedef struct Game{}
 */
GameP game_init(void);

/**
 * @fn void game_enumerate_plays(GameP game, Func print_play_func, void* user_data)
 * @brief Creates turn option table
 * @param game Current stored game state
 * @param print_play_func Function to create table of player options
 * @param user_data Context about the user if needed
 * @note This function accepts the current game state object, as well as a
 * function created to print turn options to the player as parameters. It
 * also accepts an untyped user_data object containing context if needed.
 * While analyzing the game state, this function displays the valid
 * moves still available to the current player
 */
void game_enumerate_plays(GameP game, Func print_play_func, void* user_data);

/**
 * @fn int game_play(GameP game, int input)
 * @brief Resolves the chosen game action each turn
 * @param game Current stored game state
 * @param input Turn option chosen by the current player
 * @returns One of the following options:
 *  * -2 if the game has resulted in a draw
 *  * -1 if an invalid move has been selected
 *  *  0 if the chosen game option was successful and it is the
 *     next player's turn
 *  * 'X' or 'O' if either player X or player O, respectively, has successfully
 *     made a move and won.
 * @note After a list of possible turn options has been provided by the
 * game_enumerate_plays() function, game_play() accepts the current stored game
 * state and the proposed turn option from the player whose turn it is and
 * resolves that choice. This function returns a different value depending on
 * the resolution of the chosen turn option.
 */
int game_play(GameP game, int input);