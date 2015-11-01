//
//  BoardPosition.h
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//
//  Used to represent a grid on the board.
//  Each piece owns an instance of this class which
//  represents its current position.
//

#ifndef __chess__BoardPosition__
#define __chess__BoardPosition__

#include <stdio.h>
#include <string>

using namespace std;

class BoardPosition {
private:
    int row;
    int col;
public:
    BoardPosition();
    BoardPosition(int row, int col);
    
    int getRow() const;
    void setRow(int newRow);
    int getCol() const;
    void setCol(int newCol);
};

#endif /* defined(__chess__BoardPosition__) */
