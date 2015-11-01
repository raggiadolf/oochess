//
//  BoardPosition.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include "BoardPosition.h"

BoardPosition::BoardPosition() {
    
}

BoardPosition::BoardPosition(int row, int col) {
    this->row = row;
    this->col = col;
}

int BoardPosition::getRow() const {
    return this->row;
}

void BoardPosition::setRow(int newRow) {
    this->row = newRow;
}

int BoardPosition::getCol() const {
    return this->col;
}

void BoardPosition::setCol(int newCol) {
    this->col = newCol;
}
