#include "tickTackToeClass.cpp"

// minimax algorhitm
int minimaxAI(intField move){
    return 1;
}

// tickTackToe void function
void tickTackToe::minimax(){
    intField bestMove;
    int bestScore = -1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == player::NOBODY){
                intField move;
                move.x = i;
                move.y = j;
                if(minimaxAI(move) >= bestScore){
                    bestMove = move;
                }
            }
        }
    }

    makeMove(bestMove);
}