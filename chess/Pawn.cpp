//
//  Pawn.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(BoardPosition pos, bool isUpper, Board* board) : ChessPiece(pos, isUpper, board) {
    this->setName('p');
}

vector<BoardPosition> Pawn::legalMoves() const {
    return checkMoves(legalJumps());
}

vector<vector<BoardPosition> > Pawn::legalJumps() const {
    vector<vector<BoardPosition> > jumps(1);
    
    if(this->getColor()) {
        BoardPosition oneForward(this->getPos().getRow() + 1, this->getPos().getCol());
        if(this->getBoard()->getAt(oneForward) == NULL) {
            jumps.at(0).push_back(oneForward);
            if(this->getPos().getRow() == 1) {
                BoardPosition twoForward(this->getPos().getRow() + 2, this->getPos().getCol());
                if(this->getBoard()->getAt(twoForward) == NULL) {
                    jumps.at(0).push_back(twoForward);
                }
            }
        }
        
        BoardPosition leftDiag(this->getPos().getRow() + 1, this->getPos().getCol() + 1);
        if(this->getBoard()->getAt(leftDiag) != NULL) {
            jumps.at(0).push_back(BoardPosition(leftDiag));
        }
        BoardPosition rightDiag(this->getPos().getRow() + 1, this->getPos().getCol() - 1);
        if(this->getBoard()->getAt(rightDiag) != NULL) {
            jumps.at(0).push_back(BoardPosition(rightDiag));
        }
    } else {
        BoardPosition oneForward(this->getPos().getRow() - 1, this->getPos().getCol());
        if(this->getBoard()->getAt(oneForward) == NULL) {
            jumps.at(0).push_back(oneForward);
            if(this->getPos().getRow() == 6) {
                BoardPosition twoForward(this->getPos().getRow() - 2, this->getPos().getCol());
                if(this->getBoard()->getAt(twoForward) == NULL) {
                    jumps.at(0).push_back(twoForward);
                }
            }
        }
        
        BoardPosition leftDiag(this->getPos().getRow() - 1, this->getPos().getCol() + 1);
        if(this->getBoard()->getAt(leftDiag) != NULL) {
            jumps.at(0).push_back(BoardPosition(leftDiag));
        }
        BoardPosition rightDiag(this->getPos().getRow() - 1, this->getPos().getCol() - 1);
        if(this->getBoard()->getAt(rightDiag) != NULL) {
            jumps.at(0).push_back(BoardPosition(rightDiag));
        }
    }
    
    return jumps;
}
