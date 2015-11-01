//
//  ChessPiece.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Base class for the Pieces on the board.
//  Implements checkMoves for Pawn, Knight and King.
//  As well as getters/setters as needed, and moveTo function
//  which moves the pieces around the board, and an outOfBounds
//  helper function which checks if a BoardPosition object is on
//  the board.
//

#ifndef __chess__ChessPiece__
#define __chess__ChessPiece__

#include <stdio.h>
#include "BoardPosition.h"
#include <vector>

const int directions = 4;

class Board;

class ChessPiece {
private:
    BoardPosition pos;
    bool color;
    char name;
    Board* board;
    
public:
    ChessPiece(BoardPosition pos, bool isUpper, Board* board);
    virtual ~ChessPiece() { }
    
    virtual vector<BoardPosition> legalMoves() const = 0;
    virtual vector<BoardPosition> checkMoves(vector<vector<BoardPosition> > jumps) const;
    char representation() const;
    
    bool getColor() const;
    BoardPosition getPos() const;
    void setPos(BoardPosition newPos);
    Board* getBoard() const;
    void setName(char newName);
    virtual void moveTo(const BoardPosition& newPos);
    bool outOfBounds(const BoardPosition& pos) const;
};

#endif /* defined(__chess__ChessPiece__) */
