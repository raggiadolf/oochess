//
//  SequentialChessPiece.cpp
//  chess
//
//  Created by Ragnar Adolf on 05/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "SequentialChessPiece.h"
#include "Board.h"

SequentialChessPiece::SequentialChessPiece(BoardPosition pos, bool isUpper, Board* board) : ChessPiece(pos, isUpper, board) {
}

vector<BoardPosition> SequentialChessPiece::checkMoves(vector<vector<BoardPosition> > jumps) const {
    vector<BoardPosition> moves;
    
    for(unsigned int i = 0; i < jumps.size(); i++) {
        for(unsigned int j = 0; j < jumps.at(i).size(); j++) {
            BoardPosition pos = jumps.at(i).at(j);
            if(this->getBoard()->getAt(pos) == NULL) {
                moves.push_back(pos);
            } else if(this->getBoard()->getAt(pos)->getColor() != this->getColor()) {
                moves.push_back(pos);
                break;
            } else {
                break;
            }
        }
    }
    
    return moves;
}
