#pragma once
#include <iostream>
#include <vector>

using namespace std;

// enum for player
enum class player{
    X,
    O,
    NOBODY
};

// enum for game mode
enum class mode{
    MINIMAX,
    MULTIPLAYER,
    TEST,
    NONE
};

// field on the board with char
struct field{
    char x;
    int y;
};

// field on the board, ints
struct intField{
    int x;
    int y;
};

// class
class tickTackToe{

    ////////////////////////////////////////////////////////////////////////
    //                          privete variables                         //
    ////////////////////////////////////////////////////////////////////////

    private:
    //public:
    // player who makes move currently
    player whoseTurn;
    // tick tack toe board
    player board[3][3];
    // winner
    player winner;
    // counts amount of made moves
    int turnsCounter;

    ////////////////////////////////////////////////////////////////////////
    //                          privete functions                         //
    ////////////////////////////////////////////////////////////////////////

    // converts player enum to char - o, x
    char playerToChar(player p);

    // converts x coordinate from char to integer
    int xToInt(char x);

    // makes move [0-2][0-2]
    void makeMove(intField);

    // minimax AI
    int minimaxAI(vector<vector<player>> vBoard, bool isMaximizing, player AI, player human);

    // check win for vector
    player checkVectorWin(vector<vector<player>> vboard);

    //prints board
    void printBoard(vector<vector<player>> vBoard);

    ////////////////////////////////////////////////////////////////////////
    //                          public functions                          //
    ////////////////////////////////////////////////////////////////////////

    public:

    // constructor
    tickTackToe(player startPlayer);

    // winner enum getter
    player getWinner();

    // winner converted to char getter
    char getCharWinner();

    // whoseTurn getter
    player getWhoseTurn();

    //prints board
    void printBoard();

    // prints player move interface
    void printMoveInterface();

    // chacks if move is correct
    bool checkMove(field move);

    // makes move [A,B,C][1-3]
    void makeMove(field move);

    // checks if game is over
    bool gameOver();

    // checks if somebody won
    void checkWin();

    // minimax algorithm
    void minimax(player AI);
};