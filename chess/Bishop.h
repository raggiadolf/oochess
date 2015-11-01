//
//  Bishop.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Inherits from SequentialChessPiece, which inherits from
//  ChessPiece and overwrites checkMoves correctly for the
//  pieces that need to.
//

#ifndef __chess__Bishop__
#define __chess__Bishop__

#include <stdio.h>
#include "SequentialChessPiece.h"

class Bishop : public SequentialChessPiece {
private:
    
public:
    Bishop(BoardPosition pos, bool isUpper, Board* board);
    virtual ~Bishop() { }
    
    virtual vector<BoardPosition> legalMoves() const;
    vector<vector<BoardPosition> > getLegalDiagonalMoves() const;
};

#endif /* defined(__chess__Bishop__) */
