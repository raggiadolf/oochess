//
//  ChessPiece.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "ChessPiece.h"
#include "Board.h"

ChessPiece::ChessPiece(BoardPosition pos, bool isUpper, Board* board) : pos(pos), board(board) {
    this->color = isUpper;
}

vector<BoardPosition> ChessPiece::checkMoves(vector<vector<BoardPosition> > jumps) const {
    vector<BoardPosition> moves;
    
    for(unsigned int i = 0; i < jumps.at(0).size(); i++) { // for(unsigned int i = 0; i < jumps.size(); i++)
        if(!this->outOfBounds(jumps.at(0).at(i))) {
            ChessPiece* piece = this->getBoard()->getAt(jumps.at(0).at(i));
            if(piece == NULL || piece->getColor() != this->getColor()) {
                moves.push_back(jumps.at(0).at(i));
            }
        }
    }
    
    return moves;
}

char ChessPiece::representation() const {
    if(this->getColor()) {
        return toupper(this->name);
    } else {
        return tolower(this->name);
    }
}

bool ChessPiece::getColor() const {
    return this->color;
}

BoardPosition ChessPiece::getPos() const {
    return this->pos;
}

void ChessPiece::setPos(BoardPosition newPos) {
    this->pos = newPos;
}

Board* ChessPiece::getBoard() const {
    return this->board;
}

void ChessPiece::setName(char newName) {
    this->name = newName;
}

void ChessPiece::moveTo(const BoardPosition& newPos) {
    board->setAt(this->getPos(), NULL);
    delete board->getAt(newPos);
    board->setAt(newPos, this);
    this->setPos(newPos);
}

bool ChessPiece::outOfBounds(const BoardPosition& pos) const {
    return !(pos.getRow() >= 0 && pos.getRow() < BOARDSIZE)
        || !(pos.getCol() >= 0 && pos.getCol() < BOARDSIZE);
}
