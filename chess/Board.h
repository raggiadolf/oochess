//
//  Board.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Board has a 2d array of ChessPiece pointers which represents the board.
//  The constructor uses the place helper functions to place the pieces
//  on the board.
//

#ifndef chess_Board_h
#define chess_Board_h

#include "ChessPiece.h"

const int BOARDSIZE = 8;

class Board {
private:
    ChessPiece* board[BOARDSIZE][BOARDSIZE];
    void placePawns(int whiteStartRow, int blackStartRow);
    void placeRooks(int whiteStartRow, int blackStartRow);
    void placeKnights(int whiteStartRow, int blackStartRow);
    void placeBishops(int whiteStartRow, int blackStartRow);
    void placeQueens(int whiteStartRow, int blackStartRow);
    void placeKings(int whiteStartRow, int blackStartRow);
    
public:
    Board();
    ~Board();
    void displayBoard() const;
    ChessPiece* getAt(const BoardPosition& pos) const;
    void setAt(const BoardPosition& pos, ChessPiece* piece);
};

#endif
