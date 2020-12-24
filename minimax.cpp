#include "tickTackToeClass.cpp"
#include <vector>

using namespace std;

// checks if board is full
bool isFullBoard(vector<vector<player>> vboard);

// player change
player playerChange(player p);

// minimax algorhitm
int tickTackToe::minimaxAI(vector<vector<player>> vBoard, bool isMaximizing, player AI, player human){
    player result = checkVectorWin(vBoard);
    if(result == AI){
        return 1;
    }else if(result == human){
        return -1;
    }else if(isFullBoard(vBoard)){
        return 0;
    }else if(isMaximizing){
        int bestScore = -2;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(vBoard[i][j] == player::NOBODY){
                    vBoard[i][j] = AI;
                    int score = minimaxAI(vBoard, false, AI, human);
                    vBoard[i][j] = player::NOBODY;
                    if(score > bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }else{
        int bestScore = 2;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(vBoard[i][j] == player::NOBODY){
                    vBoard[i][j] = human;
                    int score = minimaxAI(vBoard, true, AI, human);
                    vBoard[i][j] = player::NOBODY;
                    if(score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

// tickTackToe void function
void tickTackToe::minimax(player AI){
    intField bestMove;
    int bestScore = -3;
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
                vectorBoard[i][j] = AI;
                score = minimaxAI(vectorBoard, false, AI, playerChange(AI));
                vectorBoard[i][j] = player::NOBODY;
                if(score > bestScore){
                    bestScore = score;
                    bestMove = move;
                }
                
            }
        }
    }

    makeMove(bestMove);
}

/////////////////////////////////////////////////////////////

bool isFullBoard(vector<vector<player>> vboard){
    bool returnFlag = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(vboard[i][j] == player::NOBODY){
                returnFlag = false;
                break;
            }
        }
    }
    return returnFlag;
}

// checks win for vector
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
        return player::O;
    }else{
        return player::X;
    }
}