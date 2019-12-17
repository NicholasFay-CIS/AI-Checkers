//
// Created by Ryan Gurnick on 2019-05-21.
//
#include<tuple>
#include "heads/CLI.h"
#include "heads/Board.h"

using namespace std;

CLI::CLI() {
    createMenu();
}

void CLI::buildHeader() {
    //cout << "\033[1;31mbold red text\033[0m\n" << endl;
    cout << "\e[40m\e[32m+------------------------------------+\e[0m" << endl;
    cout << "\e[40m\e[33m+--------------R-O-N-----------------+\e[0m" << endl;
    cout << "\e[40m\e[32m+------------------------------------+\e[0m" << endl;
    cout << "\e[40m\e[33m+----------C-H-E-C-K-E-R-S-----------+\e[0m" << endl;
    cout << "\e[40m\e[32m+------------------------------------+\e[0m" << endl;
    cout << "\e[40m\e[33m+-------------M-E-N-U----------------+\e[0m" << endl;
    cout << "\e[40m\e[32m+------------------------------------+\e[0m" << endl;
}

bool CLI::setPlayers() {
    cout << "Player 0 Name: ";
    cin >> player0Name;
    cout << "Player 0's name is now " << player0Name << endl;

    cout << "Player 1 Name: ";
    cin >> player1Name;
    cout << "Player 1's name is now " << player1Name << endl;

    // player start randomizer
    srand(time(0));
    currentPlayer = rand() & 1;
    if(currentPlayer == 0){
        cout << player0Name << " is starting first!" << endl;
    } else if(currentPlayer == 1){
        cout << player1Name << " is starting first!" << endl;
    }
    cout << endl;

    return true;
}

int CLI::getSelection() {
    int option;
    if(!gameStarted) {
        cout << "(1): Start Game" << endl;
        cout << "(-1): Exit" << endl;
        cout << "Which menu option do you want to select: ";
    }
    cin >> option;
    return option;
}

void CLI::tellCurrentPlayer(bool stupid) {
    if(currentPlayer == 0){
        if(!stupid) {
            cout << player0Name << " it is your turn!" << endl;
            cout << "You are (*) on the board." << endl;
        }else{
            cout << player0Name << ", try again stupid!" << endl;
        }
    } else if(currentPlayer == 1) {
        if(!stupid) {
            cout << player1Name << " it is your turn!" << endl;
            cout << "You are (-) on the board." << endl;
        }else{
            cout << player1Name << ", try again stupid!" << endl;
        }
    }
}

void CLI::createMenu() {
    if(!gameStarted) {
        buildHeader();
        setPlayers();
    }

    while(true){
        int option = getSelection();
        if(option == -1){
            exit(1);
        } else if(option == 1 && !gameStarted){
            gameStarted = true;
            cout << "Game started!" << endl;
            //board = *(new Board());
            cout << "Board Initialized!" << endl;
            cout << board.printCombinedBoard() << endl << endl;

        } else {
            cout << "Invalid menu option" << endl;
        }

        // have currentPlayer (0/1)
        // loop (completed() = true)
        while(!board.completed()) {
            tellCurrentPlayer();
            requestMove();

            if(!board.capturedTile) {
                if (currentPlayer == 0) {
                    currentPlayer = 1;
                } else if (currentPlayer == 1) {
                    currentPlayer = 0;
                }
            }
            board.capturedTile = false;
        }
    }
    //delete &board;
}

void CLI::requestMove() {
    int inX, inY, inMX, inMY;
    Tile * bestTile = board.bestTile(currentPlayer); // get the best tile for the A.I Suggestion
    cout << "\e[40m\e[32mPlease input the X for the tile to move: (Optimal X: " << bestTile->x << ") \e[0m";
    cin >> inX;
    cout << "\e[40m\e[33mPlease input the Y for the tile to move: (Optimal Y: " << bestTile->y << ") \e[0m";
    cin >> inY;
    bool ableToSelect = board.selectTile(to_string(currentPlayer) + "-" + to_string(inX) + "-" + to_string(inY));
    if(ableToSelect){
        // check the tile to see how it moves
        Tile* t = board.getSelectedTile();
        vector<tuple <string, int> > x = board.possibleMoves(t); //possible moves of the user selected tile
        // if the tile has no moves request vector
        if(!x.size()) { // if the tile has no moves then tell the user and prompt for a new input
            cout << "This tile has no possible moves" << endl;
            requestMove();
        }
        // get the best move for the tile that had been selected (for A.I)
        string bestMove = board.bestMove(board.getSelectedTile());
        int pID, dX, dY = 0;
        smatch payload;

        regex expression("([01])-'([\-0-9]+)'-'([\-0-9]+)'");
        bool found = regex_search(bestMove, payload, expression);

        if(!found){
            cout << "Invalid Tile Selection" << endl;
            return;
        }

        // set all of the tile related info
        // playerid will automatically be checked with regex to be 0 or 1
        pID = atoi(payload[1].str().c_str());
        int dirBias = [](int pID){ if (pID == 0) { return 1; }else{ return -1;}}(pID); //accounts for players opposite movements
        dX = atoi(payload[2].str().c_str()) * dirBias;
        dY = atoi(payload[3].str().c_str()) * dirBias;
        cout << "Thanks for selecting the tile" << endl;
        if ((t->player == 0 && t->x == 0) || (t->player == 1 && t->x == 9)) {
            cout << "[1] Forward Left" << endl;
            requestMoveVector();
        }
        else if ((t->player == 0 && t->x == 9) || (t->player == 1 && t->x == 0)) {
            cout << "[2] Forward Right" << endl;
            requestMoveVector();
        }
        else if(!t->king) {
            // forward left -1 1
            // forward right 1 1
            if(t->player == 0 ){
                if( dX == 1) {
                    cout << "[1] Forward Left / (2) Forward Right" << endl;
                } else if (dX == -1) {
                    cout << "(1) Forward Left / [2] Forward Right" << endl;
                }else {
                    cout << "(1) Forward Left / (2) Forward Right" << endl;
                }
            } else if( t->player == 1){
                if( dX == -1 ) {
                    cout << "[1] Forward Left / (2) Forward Right" << endl;
                } else if (dX == 1) {
                    cout << "(1) Forward Left / [2] Forward Right" << endl;
                }else {
                    cout << "(1) Forward Left / (2) Forward Right" << endl;
                }

            }

            requestMoveVector();
        } else if(t->king) {
            cout << "(3) Backward Left / (4) Backward Right" << endl;
            requestMoveVector();
            return;
        }

    } else {
        tellCurrentPlayer(true);
        requestMove();
    }
}


void CLI::requestMoveVector() {
    //
    int selection;
    Tile* t = board.getSelectedTile();
    cout << "Which do you select: ";
    cin >> selection;
    if(selection == 1){
        if( !board.moveSelectedTile(1, 1) ) {
            cout << "" << endl;
            requestMove();
        }
        cout << board.printCombinedBoard();
    }
    else if(selection == 2) {
        if( !board.moveSelectedTile(-1, 1) ){
            requestMove();
        }
        cout << board.printCombinedBoard();
    }
    else if(selection == 3 && t->king) {
        if( !board.moveSelectedTile(-1, -1) ){
            requestMove();
        }
        cout << board.printCombinedBoard();
    }
    else if(selection == 4 && t->king) {
        if( !board.moveSelectedTile(-1, 1) ){
            requestMove();
        }
        cout << board.printCombinedBoard();
    }
    cout << "Player 0 Score: " << board.player0Score.getPlayerScore() << " | Player 1 Score: " << board.player1Score.getPlayerScore() << endl;
    return;
}

CLI::~CLI() {
    delete &board;
}


