//
//  Queen.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Implemented-in-terms-of bishop and rook.
//  gets its legal moves from bishop and rook, since its
//  moveset is the combined moveset of those two pieces.
//

#ifndef __chess__Queen__
#define __chess__Queen__

#include <stdio.h>
#include "ChessPiece.h"
#include "Bishop.h"
#include "Rook.h"

class Queen : public ChessPiece {
private:
    Bishop bishop;
    Rook rook;
    void updatePos();
    
public:
    Queen(BoardPosition pos, bool isUpper, Board* board);
    virtual ~Queen() { }
    
    virtual vector<BoardPosition> legalMoves() const;
    virtual void moveTo(const BoardPosition& newPos);
};

#endif /* defined(__chess__Queen__) */
