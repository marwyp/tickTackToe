#pragma once
#include <iostream>

using namespace std;

enum class player{
    X,
    O,
    NOBODY
};

enum class mode{
    MULTIPLAYER,
    NONE
};

struct field{
    char x;
    int y;
};


class tickTackToe{
    private:

    player whoseTurn;
    player board[3][3];
    player winner;
    field move;
    int turnsCounter;

    char playerToChar(player p){
        if(p == player::O){
            return 'o';
        }else if(p == player::X){
            return 'x';
        }else{
            return ' ';
        }
    }

    int xToInt(char x){
        switch (x)
        {
        case 'a':;
        case 'A':{
            return 0;
            break;
        }
        case 'b':;
        case 'B':{
            return 1;
            break;
        }
        case 'c':;
        case 'C':{
            return 2;
            break;
        }
        default:{
            return -1;
            break;
        }   
        }
    }

    public:
    tickTackToe(player startPlayer){
        whoseTurn = startPlayer;
        winner = player::NOBODY;
        turnsCounter = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = player::NOBODY;
            }
        }
    }

    player getWinner(){
        return winner;
    }

    char getCharWinner(){
        return playerToChar(winner);
    }

    void printBoard(){
        cout << "  -------------" << endl;
        cout << "3 | " << playerToChar(board[0][2]) << " | " << playerToChar(board[1][2]);
        cout << " | " << playerToChar(board[2][2]) << " |" <<endl;
        cout << "  -------------" << endl;
        cout << "2 | " << playerToChar(board[0][1]) << " | " << playerToChar(board[1][1]);
        cout << " | " << playerToChar(board[2][1]) << " |" <<endl;
        cout << "  -------------" << endl;
        cout << "1 | " << playerToChar(board[0][0]) << " | " << playerToChar(board[1][0]);
        cout << " | " << playerToChar(board[2][0]) << " |" <<endl;
        cout << "  -------------" << endl;
        cout << "    A   B   C" << endl << endl;
    }

    void printMoveInterface(){
        cout << "It is " <<playerToChar(whoseTurn) << " turn" << endl;
        cout << "Enter you're move: ";
    }

    void setMove(field m){
        move = m;
    }

    bool checkMove(){
        if(move.y > 3 || move.y < 0){
            cout << "Wrong field!" << endl << endl;
            return false;
        }else if(xToInt(move.x) > 3 || xToInt(move.x) < 0){
            cout << "Wrong field!" << endl << endl;
            return false;
        }else if(board[xToInt(move.x)][move.y-1] != player::NOBODY){
            cout << "This place has already been taken!" << endl << endl;
            return false;
        }else{
            return true;
        }
    }

    void makeMove(){
        board[xToInt(move.x)][move.y-1] = whoseTurn;
        if(whoseTurn == player::X){
            whoseTurn = player::O;
        }else{
            whoseTurn = player::X;
        }
        turnsCounter++;
    }

    bool gameOver(){
        if(winner != player::NOBODY){
            return true;
        }else if(turnsCounter == 9){
            return true;
        }else{
            return false;
        }
    }

    void checkWin(){
        for(int i = 0; i < 3; i++){
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != player::NOBODY){
                winner = board[0][i];
            }
        }

        for(int i = 0; i < 3; i++){
            if(board[i][2] == board[i][1] && board[i][2] == board[i][0] && board[i][2] != player::NOBODY){
                winner = board[i][2];
            }
        }

        if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != player::NOBODY){
            winner = board[1][1];
        }

        if(board[2][2] == board[1][1] && board[2][2] == board[0][0] && board[2][2] != player::NOBODY){
            winner = board[1][1];
        }

    }

};