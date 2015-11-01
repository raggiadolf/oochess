//
//  Queen.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "Queen.h"
#include "Board.h"

Queen::Queen(BoardPosition pos, bool isUpper, Board* board) : ChessPiece(pos, isUpper, board), bishop(pos, isUpper, board), rook(pos, isUpper, board) {
    this->setName('q');
}

vector<BoardPosition> Queen::legalMoves() const {
    vector<BoardPosition> diags = this->bishop.legalMoves();
    vector<BoardPosition> straights = this->rook.legalMoves();
    vector<BoardPosition> moves;
    
    moves.reserve(diags.size() + straights.size());
    moves.insert(moves.end(), diags.begin(), diags.end());
    moves.insert(moves.end(), straights.begin(), straights.end());
    
    return moves;
}

void Queen::moveTo(const BoardPosition& newPos) {
    this->getBoard()->setAt(this->getPos(), NULL);
    delete this->getBoard()->getAt(newPos);
    this->getBoard()->setAt(newPos, this);
    this->setPos(newPos);
    this->bishop.setPos(newPos);
    this->rook.setPos(newPos);
}
