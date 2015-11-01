//
//  Rook.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  

#include "Rook.h"
#include "Board.h"

Rook::Rook(BoardPosition pos, bool isUpper, Board* board) : SequentialChessPiece(pos, isUpper, board) {
    this->setName('r');
}

vector<BoardPosition> Rook::legalMoves() const {
    return checkMoves(getLegalStraightMoves());
}

vector<vector<BoardPosition> > Rook::getLegalStraightMoves() const {
    vector<vector<BoardPosition> > jumps(directions);
    
    for(int i = this->getPos().getRow() + 1; i < BOARDSIZE; i++) {
        jumps.at(0).push_back(BoardPosition(i, this->getPos().getCol()));
    }
    
    // Check cells behind us, and see how far we can go
    for(int i = this->getPos().getRow() - 1; i >= 0; i--) {
        jumps.at(1).push_back(BoardPosition(i, this->getPos().getCol()));
    }
    
    // Check cells to the left side of us, and see how far we can go
    for(int i = this->getPos().getCol() + 1; i < BOARDSIZE; i++) {
        jumps.at(2).push_back(BoardPosition(this->getPos().getRow(), i));
    }
    
    // Check cells to the right side of us, and see how far we can go
    for(int i = this->getPos().getCol() - 1; i >= 0; i--) {
        jumps.at(3).push_back(BoardPosition(this->getPos().getRow(), i));
    }
    
    return jumps;
}
