#include <iostream>
#include <vector>
#include "tickTackToeClass.cpp"

using namespace std;

int main(int argc, char *argv[]){
    vector<string> args(argv, argv + argc);
    player startPlayer;
    mode gameMode;

    gameMode = mode::NONE;
    startPlayer = player::NOBODY;
    for(size_t i = 0; i < args.size(); i++){
        if(args[i] == "-p"){
            if(i + 1 < args.size()){
                if(args[i + 1] == "x"){
                    startPlayer = player::X;
                }else if(args[i + 1] == "o"){
                    startPlayer = player::O;
                }
            }
        }
        if(args[i] == "-m"){
            if(i + 1 < args.size()){
                if(args[i + 1] == "m"){
                    gameMode = mode::MULTIPLAYER;
                }
            }
        }
    }
    cout << "tick-tack-toe by Marek Wypich" << endl << endl;
    if(startPlayer == player::NOBODY || gameMode == mode::NONE){
        cout << "Options: " << endl;
        cout << "-p <player>\t\t starting player, x or o" << endl;
        cout << "-m <mode>\t\t game mode, m - multiplayer" << endl;
    }else{
        tickTackToe game(startPlayer);
        do{
            game.printBoard();
            do{
                game.printMoveInterface();
                field move;
                cin >> move.x >> move.y;
                cin.clear();
                cout << endl;
                game.setMove(move);
            }while(!game.checkMove());
            game.makeMove();
            game.checkWin();
        }while(!game.gameOver());

        game.printBoard();

        if(game.getWinner() == player::NOBODY){
            cout << endl << "It is draw" << endl;
        }else{
            cout << "Player " << game.getCharWinner() << " wins" << endl;
        }
        
        
    }
}