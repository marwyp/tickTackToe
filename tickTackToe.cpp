#include <iostream>
#include <vector>
#include "tickTackToeClass.cpp"

using namespace std;

int main(int argc, char *argv[]){
    // vector for cmd arguments
    vector<string> args(argv, argv + argc);

    // cmd options variables
    player startPlayer;
    mode gameMode;

    // default values
    gameMode = mode::NONE;
    startPlayer = player::NOBODY;

    // cmd arguments for
    for(size_t i = 0; i < args.size(); i++){
        // -p - player options
        if(args[i] == "-p"){
            if(i + 1 < args.size()){
                if(args[i + 1] == "x"){
                    startPlayer = player::X;
                }else if(args[i + 1] == "o"){
                    startPlayer = player::O;
                }
            }
        }
        // -m - mode options
        if(args[i] == "-m"){
            if(i + 1 < args.size()){
                // multiplayer
                if(args[i + 1] == "m"){
                    gameMode = mode::MULTIPLAYER;

                // single player - min max algorithm
                }else if(args[i + 1] == "m"){
                    gameMode = mode::MINMAX;
                }
            }
        }
    }

    // welcoming string
    cout << "tick-tack-toe by Marek Wypich" << endl << endl;

    // print options
    if(startPlayer == player::NOBODY || gameMode == mode::NONE){
        cout << "Options: " << endl;
        cout << "-p <player>\t\t starting player, x or o" << endl;
        cout << "-m <mode>\t\t game mode, m - multiplayer" << endl;

    // multiplayer
    }else if(startPlayer != player::NOBODY && gameMode == mode::MULTIPLAYER){
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
        
    // single player - min max algorithm   
    }else if(startPlayer != player::NOBODY && gameMode == mode::MINMAX){
        ;
    }
}