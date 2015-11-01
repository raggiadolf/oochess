//
//  main.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All r/Users/ragnaradolf/Dropbox/Skóli/HR2015Vor/HlutbundinForritunC++T-528-HLUT/assignments/ass1/chess/Board.hights reserved.
//
//  While loop which prompts the user for input until 'x' is pressed.
//  For each input it validates the input, and repeats the loop if
//  wrong input is found, displaying appropriate error messages.
//  Instead of casting the string input we access it as a char array
//  and treat the chars as ASCII values, hence the constants needed
//  to correctly compute the correct grid cells.
//  We specifically check for the line length to catch input with
//  two numbers, fx. a10, to be explicit.

#include <iostream>
#include "Board.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int rowOffset = 49;
const int colOffset = 97; // ASCII values to correctly access the board.
const int colFlip = 7;    // To correctly access the columns on the board

void illegalSquare(bool whiteMove) {
    cout << "Illegal square!" << endl << endl;
    cout << ((whiteMove) ? "White's move - input square: " : "Black's move - input square: ");
}

bool inputOutOfRange(int col, int row, bool whiteMove) {
    if((col < 0 || col >= BOARDSIZE) || (row < 0 || row >= BOARDSIZE)) {
        illegalSquare(whiteMove);
        return true;
    }
    
    return false;
}

bool checkForEmpty(const Board& board, const BoardPosition& pos, bool whiteMove) {
    if(board.getAt(pos) == NULL) {
        cout << "No piece on square!" << endl << endl;
        cout << ((whiteMove) ? "White's move - input square: " : "Black's move - input square: ");
        return true;
    }
    
    return false;
}

bool checkTurn(const Board& board, BoardPosition pos, bool whiteMove) {
    if(board.getAt(pos)->getColor() != whiteMove) {
        cout << "Not your turn!" << endl << endl;
        cout << ((whiteMove) ? "White's move - input square: " : "Black's move - input square: ");
        return true;
    }
    
    return false;
}

bool checkMoves(const vector<BoardPosition>& possibleSquares, string line, bool whiteMove) {
    if(possibleSquares.empty()) {
        cout << "Piece on " << line << " cannot move!" << endl << endl;
        cout << ((whiteMove) ? "White's move - input square: " : "Black's move - input square: ");
        return true;
    }
    
    return false;
}

char colToChar(const BoardPosition& pos) {
    return colFlip - pos.getCol() + colOffset;
}

int rowToInt(const BoardPosition &pos) {
    return pos.getRow() + 1;
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    bool whiteMove = true;
    int col, row;
    string line;
    vector<BoardPosition> possibleSquares;
    
    Board myBoard;
    myBoard.displayBoard();
    cout << "White's move - input square: ";
    
    while(getline(cin, line) && line != "x") {
        if(line.length() != 2) {
            illegalSquare(whiteMove);
            continue;
        }
        col = colFlip - (line[0] - colOffset);
        row = (line[1] - rowOffset);
        BoardPosition pos(row, col);
        
        if(inputOutOfRange(col, row, whiteMove)) {
            continue;
        }
        
        if(checkForEmpty(myBoard, pos, whiteMove)) {
            continue;
        }
        
        if(checkTurn(myBoard, pos, whiteMove)) {
            continue;
        }
        
        possibleSquares = myBoard.getAt(BoardPosition(row, col))->legalMoves();

        if(checkMoves(possibleSquares, line, whiteMove)) {
            continue;
        }
        
        cout << "Possible squares: ";
        for(unsigned int i = 0; i < possibleSquares.size(); i++) {
            char newColumn = colToChar(possibleSquares.at(i));
            int newRow = rowToInt(possibleSquares.at(i));
            
            cout << newColumn << newRow << " ";
        }
        cout << endl;
    
        BoardPosition selectedMove = possibleSquares.at(rand() % possibleSquares.size());
        
        cout << "Selected square: " << colToChar(selectedMove) << rowToInt(selectedMove) << endl;
        
        myBoard.getAt(pos)->moveTo(selectedMove);
        myBoard.displayBoard();
        
        whiteMove = !whiteMove;
        cout << ((whiteMove) ? "White's move - input square: " : "Black's move - input square: ");
    }
    return 0;
}
