#include <iostream>
#include <vector>
#include "tickTackToeClass.cpp"

using namespace std;

int main(int argc, char *argv[]){
    // vector for cmd arguments
    vector<string> args(argv, argv + argc);

    // cmd options variables
    player startPlayer;
    player AIplayer;
    mode gameMode;

    // default values
    gameMode = mode::NONE;
    startPlayer = player::NOBODY;
    AIplayer = player::NOBODY;

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
                if(args[i + 1] == "multiplayer"){
                    gameMode = mode::MULTIPLAYER;

                // single player - minimax algorithm
                }else if(args[i + 1] == "minimax"){
                    if(i + 2 < args.size()){
                        if(args[i + 2] == "x"){
                            AIplayer = player::X;
                            gameMode = mode::MINIMAX;
                        }else if(args[i + 2] == "o"){
                            gameMode = mode::MINIMAX;
                            AIplayer = player::O;
                        }
                    }
                    
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
        cout << "-m <mode> <AI sign>\t game mode, modes: multiplayer - without AI sign";
        cout << ", minimax - singleplayer with minimax AI - AI sign x or o" << endl;

    // multiplayer
    }else if(startPlayer != player::NOBODY && gameMode == mode::MULTIPLAYER){
        tickTackToe game(startPlayer);
        do{
            game.printBoard();
            field move;
            do{
                game.printMoveInterface();
                cin >> move.x >> move.y;
                cin.clear();
                cout << endl;
            }while(!game.checkMove(move));
            game.makeMove(move);
            game.checkWin();
        }while(!game.gameOver());

        game.printBoard();

        if(game.getWinner() == player::NOBODY){
            cout << endl << "It is draw" << endl;
        }else{
            cout << "Player " << game.getCharWinner() << " wins" << endl;
        }
        
    // single player - minimax algorithm   
    }else if(startPlayer != player::NOBODY && gameMode == mode::MINIMAX){
        tickTackToe game(startPlayer);
        do{
            game.printBoard();
            if(game.getWhoseTurn() == AIplayer){
                game.minimax();
            }else{
                field move;
                do{
                    game.printMoveInterface();
                    cin >> move.x >> move.y;
                    cin.clear();
                    cout << endl;
                }while(!game.checkMove(move));
                game.makeMove(move);
            }
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