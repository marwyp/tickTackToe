#include "tickTackToeClass.cpp"

// converts player enum to char - o, x
char tickTackToe::playerToChar(player p){
    if(p == player::O){
        return 'o';
    }else if(p == player::X){
        return 'x';
    }else{
        return ' ';
    }
}

// converts x coordinate from char to integer
int tickTackToe::xToInt(char x){
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

// constructor
tickTackToe::tickTackToe(player startPlayer){
    whoseTurn = startPlayer;
    winner = player::NOBODY;
    turnsCounter = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = player::NOBODY;
        }
    }
}

// winner enum getter
player tickTackToe::getWinner(){
    return winner;
}

// winner converted to char getter
char tickTackToe::getCharWinner(){
    return playerToChar(winner);
}

// whoseTurn getter
player tickTackToe::getWhoseTurn(){
    return whoseTurn;
}

//prints board
void tickTackToe::printBoard(){
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

// prints player move interface
void tickTackToe::printMoveInterface(){
    cout << "It is " <<playerToChar(whoseTurn) << " turn" << endl;
    cout << "Enter you're move: ";
}

// chacks if move is correct
 bool tickTackToe::checkMove(field move){
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

// makes move [A,B,C][1-3]
void tickTackToe::makeMove(field move){
    board[xToInt(move.x)][move.y-1] = whoseTurn;
    if(whoseTurn == player::X){
        whoseTurn = player::O;
    }else{
        whoseTurn = player::X;
    }
    turnsCounter++;
}

// makes move [0-2][0-2]
void tickTackToe::makeMove(intField move){
    board[move.x][move.y] = whoseTurn;
    if(whoseTurn == player::X){
        whoseTurn = player::O;
    }else{
        whoseTurn = player::X;
    }
    turnsCounter++;
}

// checks if game is over
bool tickTackToe::gameOver(){
    if(winner != player::NOBODY){
        return true;
    }else if(turnsCounter == 9){
        return true;
    }else{
        return false;
    }
}

// checks if somebody won
void tickTackToe::checkWin(){
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