//
//  Bishop.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(BoardPosition pos, bool isUpper, Board* board) : SequentialChessPiece(pos, isUpper, board) {
    this->setName('b');
}

vector<BoardPosition> Bishop::legalMoves() const {
    return checkMoves(getLegalDiagonalMoves());
}

vector<vector<BoardPosition> > Bishop::getLegalDiagonalMoves() const {
    vector<vector<BoardPosition> > jumps(directions);
    
    int i, j;
    for(i = this->getPos().getRow() + 1, j = this->getPos().getCol() + 1; i < BOARDSIZE && j < BOARDSIZE; i++, j++) {
        jumps.at(0).push_back(BoardPosition(i, j));
    }
    
    for(i = this->getPos().getRow() + 1, j = this->getPos().getCol() - 1; i < BOARDSIZE && j >= 0; i++, j--) {
        jumps.at(1).push_back(BoardPosition(i, j));
    }
    
    for(i = this->getPos().getRow() - 1, j = this->getPos().getCol() + 1; i >= 0 && j < BOARDSIZE; i--, j++) {
        jumps.at(2).push_back(BoardPosition(i, j));
    }
    
    for(i = this->getPos().getRow() - 1, j = this->getPos().getCol() - 1; i >= 0 && j >= 0; i--, j--) {
        jumps.at(3).push_back(BoardPosition(i, j));
    }
    
    return jumps;
}
