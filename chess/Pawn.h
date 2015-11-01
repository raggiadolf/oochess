//
//  Pawn.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  We use a 2d array in legalJumps so that we can later
//  overwrite the method instead of hiding it.
//  legalJump simply checks every cell that the pawn could
//  possibly jump to.
//

#ifndef __chess__Pawn__
#define __chess__Pawn__

#include <stdio.h>
#include "ChessPiece.h"

class Pawn : public ChessPiece {
private:
    virtual vector<vector<BoardPosition> > legalJumps() const;
    
public:
    Pawn(BoardPosition pos, bool isUpper, Board* board);
    virtual ~Pawn() { }
    
    virtual vector<BoardPosition> legalMoves() const;
};

#endif /* defined(__chess__Pawn__) */
