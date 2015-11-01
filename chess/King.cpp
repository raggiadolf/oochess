//
//  King.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "King.h"
#include "Board.h"

King::King(BoardPosition pos, bool isUpper, Board* board) : ChessPiece(pos, isUpper, board) {
    this->setName('k');
}

vector<BoardPosition> King::legalMoves() const {
    return checkMoves(legalJumps());
}

vector<vector<BoardPosition> > King::legalJumps() const {
    vector<vector<BoardPosition> > jumps(1);
    
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 1, this->getPos().getCol()));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 1, this->getPos().getCol() + 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() + 1, this->getPos().getCol() - 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow(),     this->getPos().getCol() + 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow(),     this->getPos().getCol() - 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 1, this->getPos().getCol()));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 1, this->getPos().getCol() + 1));
    jumps.at(0).push_back(BoardPosition(this->getPos().getRow() - 1, this->getPos().getCol() - 1));
    
    return jumps;
}
