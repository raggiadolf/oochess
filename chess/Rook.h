//
//  Rook.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Inherits from SequentialChessPiece, which inherits from
//  ChessPiece and overwrites checkMoves correctly for the
//  pieces that need to.
//

#ifndef __chess__Rook__
#define __chess__Rook__

#include <stdio.h>
#include "SequentialChessPiece.h"

class Rook : public SequentialChessPiece {
private:
    
public:
    Rook(BoardPosition pos, bool isUpper, Board* board);
    virtual ~Rook() { };
    
    virtual vector<BoardPosition> legalMoves() const;
    virtual vector<vector<BoardPosition> > getLegalStraightMoves() const;
};

#endif /* defined(__chess__Rook__) */
