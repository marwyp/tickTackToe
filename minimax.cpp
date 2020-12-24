#include "tickTackToeClass.cpp"
#include <vector>

using namespace std;

// check win for vector
player tickTackToe::checkVectorWin(vector<vector<player>> vboard){
    player winner;
    winner = player::NOBODY;
    for(int i = 0; i < 3; i++){
        if(vboard[0][i] == vboard[1][i] && vboard[0][i] == vboard[2][i] && vboard[0][i] != player::NOBODY){
            winner = vboard[0][i];
        }
    }

    for(int i = 0; i < 3; i++){
        if(vboard[i][2] == vboard[i][1] && vboard[i][2] == vboard[i][0] && vboard[i][2] != player::NOBODY){
            winner = vboard[i][2];
        }
    }

    if(vboard[0][2] == vboard[1][1] && vboard[0][2] == vboard[2][0] && vboard[0][2] != player::NOBODY){
        winner = vboard[1][1];
    }

    if(vboard[2][2] == vboard[1][1] && vboard[2][2] == vboard[0][0] && vboard[2][2] != player::NOBODY){
        winner = vboard[1][1];
    }
    return winner;
}

// player change
player playerChange(player p){
    if(p == player::X){
        return player::X;
    }else{
        return player::O;
    }
}

// minimax algorhitm
int tickTackToe::minimaxAI(vector<vector<player>> vBoard, int depth, player currentPlayer){
    player result = checkVectorWin(vBoard);
    if(result != player::NOBODY){
        if(result == whoseTurn){
            return 1;
        }else{
            return -1;
        }
    }
    if(currentPlayer == whoseTurn){
        int bestScore = -1;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(vBoard[i][j] == player::NOBODY){
                    vBoard[i][j] = whoseTurn;
                    int score = minimaxAI(vBoard, depth + 1, playerChange(currentPlayer));
                    vBoard[i][j] = player::NOBODY;
                    if(score >= bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }else{
        int bestScore = 1;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(vBoard[i][j] == player::NOBODY){
                    vBoard[i][j] = playerChange(whoseTurn);
                    int score = minimaxAI(vBoard, depth + 1, playerChange(currentPlayer));
                    vBoard[i][j] = player::NOBODY;
                    if(score <= bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

// tickTackToe void function
void tickTackToe::minimax(){
    intField bestMove;
    int bestScore = -1;
    int score;

    // converting board to vector
    vector<vector<player>> vectorBoard;
    for(int i = 0; i < 3; i++){
        vector<player> row; 
        for(int j = 0; j < 3; j++){
            row.push_back(board[i][j]);
        }
        vectorBoard.push_back(row);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == player::NOBODY){
                intField move;
                move.x = i;
                move.y = j;
                vectorBoard[i][j] = whoseTurn;
                //printBoard(vectorBoard);
                score = minimaxAI(vectorBoard, 0, whoseTurn);
                vectorBoard[i][j] = player::NOBODY;
                if(score >= bestScore){
                    bestScore = score;
                    bestMove = move;
                }
                
            }
        }
    }

    makeMove(bestMove);
}