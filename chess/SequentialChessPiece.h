//
//  SequentialChessPiece.h
//  chess
//
//  Created by Ragnar Adolf on 05/05/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Using this class which overwrites the checkMoves function so we can reuse it for
//  Rook and Bishop, and by extension for Queen as well.
//

#ifndef __chess__SequentialChessPiece__
#define __chess__SequentialChessPiece__

#include <stdio.h>
#include "ChessPiece.h"

class SequentialChessPiece : public ChessPiece {
public:
    SequentialChessPiece(BoardPosition pos, bool isUpper, Board* board);
    virtual vector<BoardPosition> checkMoves(vector<vector<BoardPosition> > jumps) const;
};

#endif /* defined(__chess__SequentialChessPiece__) */
