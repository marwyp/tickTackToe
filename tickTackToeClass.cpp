#pragma once
#include <iostream>

using namespace std;

// enum for player
enum class player{
    X,
    O,
    NOBODY
};

// enum for game mode
enum class mode{
    MINMAX,
    MULTIPLAYER,
    NONE
};

// field on the board
struct field{
    char x;
    int y;
};

// class
class tickTackToe{

    ////////////////////////////////////////////////////////////////////////
    //                          privete variables                         //
    ////////////////////////////////////////////////////////////////////////

    private:

    // player who makes move currently
    player whoseTurn;
    // tick tack toe board
    player board[3][3];
    // winner
    player winner;
    // field for next move
    field move;
    // counts amount of made moves
    int turnsCounter;

    ////////////////////////////////////////////////////////////////////////
    //                          privete functions                         //
    ////////////////////////////////////////////////////////////////////////

    // converts player enum to char - o, x
    char playerToChar(player p);

    // converts x coordinate from char to integer
    int xToInt(char x);


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

    //prints board
    void printBoard();

    // prints player move interface
    void printMoveInterface();

    // move setter
    void setMove(field m);

    // chacks if move is correct
    bool checkMove();

    // makes move
    void makeMove();

    // checks if game is over
    bool gameOver();

    // checks if somebody won
    void checkWin();
};