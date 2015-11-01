//
//  Knight.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "Knight.h"
#include "Board.h"
#include <iostream>

Knight::Knight(BoardPosition pos, bool isUpper, Board* board) : ChessPiece(pos, isUpper, board) {
    this->setName('n');
}

vector<BoardPosition> Knight::legalMoves() const {
    return checkMoves(legalJumps());
}

vector<vector<BoardPosition> > Knight::legalJumps() const {
    vector<vector<BoardPosition> > jumps(1);
    
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 1, this->getPos().getCol() + 2));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 2, this->getPos().getCol() + 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 1, this->getPos().getCol() - 2));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 2, this->getPos().getCol() - 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 1, this->getPos().getCol() + 2));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 2, this->getPos().getCol() + 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 1, this->getPos().getCol() - 2));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 2, this->getPos().getCol() - 1));
    
    return jumps;
}
