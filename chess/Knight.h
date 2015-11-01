//
//  Knight.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  We use a 2d array in legalJumps so that we can later
//  overwrite the method instead of hiding it.
//

#ifndef __chess__Knight__
#define __chess__Knight__

#include <stdio.h>
#include "ChessPiece.h"

class Knight : public ChessPiece {
private:
    virtual vector<vector<BoardPosition> > legalJumps() const;
    
public:
    Knight(BoardPosition pos, bool isUpper, Board* board);
    virtual ~Knight() { };
    
    virtual vector<BoardPosition> legalMoves() const;
};

#endif /* defined(__chess__Knight__) */
