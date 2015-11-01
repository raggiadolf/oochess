//
//  Board.cpp
//  chess
//
//  Created by Ragnar Adolf on 27/04/15.
//  Copyright (c) 2015 Ragnar Adolf. All rights reserved.
//

#include <iostream>
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

using namespace std;

Board::Board() {
    int whiteStartRow = 0;
    int blackStartRow = 7;
    
    for(int i = 0; i < BOARDSIZE; i++) {
        for(int j = 0; j < BOARDSIZE; j++) {
            this->board[i][j] = NULL;
        }
    }
    
    placePawns(whiteStartRow, blackStartRow);
    placeRooks(whiteStartRow, blackStartRow);
    placeKnights(whiteStartRow, blackStartRow);
    placeBishops(whiteStartRow, blackStartRow);
    placeQueens(whiteStartRow, blackStartRow);
    placeKings(whiteStartRow, blackStartRow);
}

Board::~Board() {
    for(int i = 0; i < BOARDSIZE; i++) {
        for(int j = 0; j < BOARDSIZE; j++) {
            if(board[i][j] != NULL) {
                delete board[i][j];
            }
        }
    }
}

void Board::displayBoard() const {
    cout << "--------------------" << endl;
    for(int i = BOARDSIZE - 1; i >= 0; i--) {
        cout << i + 1 << "| ";
        for(int j = BOARDSIZE - 1; j >= 0; j--) {
            if(this->board[i][j] == NULL) {
                cout << "  ";
            } else {
                cout << this->board[i][j]->representation() << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "--------------------" << endl;
    cout << "   a b c d e f g h  " << endl;
}

ChessPiece* Board::getAt(const BoardPosition& pos) const {
    if((pos.getRow() >= 0) && (pos.getRow() < BOARDSIZE)
            && (pos.getCol() >= 0) && (pos.getCol() < BOARDSIZE)) {
        return this->board[pos.getRow()][pos.getCol()];
    } else {
        return NULL;
    }
}

void Board::setAt(const BoardPosition& pos, ChessPiece* piece) {
    if((pos.getRow() >= 0) && (pos.getRow() < BOARDSIZE)
            && (pos.getCol() >= 0) && (pos.getCol() < BOARDSIZE)) {
        this->board[pos.getRow()][pos.getCol()] = piece;
    }
}

void Board::placePawns(int whiteStartRow, int blackStartRow) {
    for(int i = 0; i < BOARDSIZE; i++) {
        BoardPosition whitePos = BoardPosition(whiteStartRow + 1, i);
        this->board[whiteStartRow + 1][i] = new Pawn(whitePos, true, this);
        BoardPosition blackPos = BoardPosition(blackStartRow - 1, i);
        this->board[blackStartRow - 1][i] = new Pawn(blackPos, false, this);
    }
}

void Board::placeRooks(int whiteStartRow, int blackStartRow) {
    int leftCol = 0, rightCol = 7;
    
    BoardPosition whitePosLeft = BoardPosition(whiteStartRow, leftCol);
    this->board[whiteStartRow][leftCol] = new Rook(whitePosLeft, true, this);
    BoardPosition whitePosRight = BoardPosition(whiteStartRow, rightCol);
    this->board[whiteStartRow][rightCol] = new Rook(whitePosRight, true, this);
    
    BoardPosition blackPosLeft = BoardPosition(blackStartRow, leftCol);
    this->board[blackStartRow][leftCol] = new Rook(blackPosLeft, false, this);
    BoardPosition blackPosRight = BoardPosition(blackStartRow, rightCol);
    this->board[blackStartRow][rightCol] = new Rook(blackPosRight, false, this);
}

void Board::placeKnights(int whiteStartRow, int blackStartRow) {
    int leftCol = 1, rightCol = 6;
    
    BoardPosition whitePosLeft = BoardPosition(whiteStartRow, leftCol);
    this->board[whiteStartRow][leftCol] = new Knight(whitePosLeft, true, this);
    BoardPosition whitePosRight = BoardPosition(whiteStartRow, rightCol);
    this->board[whiteStartRow][rightCol] = new Knight(whitePosRight, true, this);
    
    BoardPosition blackPosLeft = BoardPosition(blackStartRow, leftCol);
    this->board[blackStartRow][leftCol] = new Knight(blackPosLeft, false, this);
    BoardPosition blackPosRight = BoardPosition(blackStartRow, rightCol);
    this->board[blackStartRow][rightCol] = new Knight(blackPosRight, false, this);
}

void Board::placeBishops(int whiteStartRow, int blackStartRow) {
    int leftCol = 2, rightCol = 5;
    
    BoardPosition whitePosLeft = BoardPosition(whiteStartRow, leftCol);
    this->board[whiteStartRow][leftCol] = new Bishop(whitePosLeft, true, this);
    BoardPosition whitePosRight = BoardPosition(whiteStartRow, rightCol);
    this->board[whiteStartRow][rightCol] = new Bishop(whitePosRight, true, this);
    
    BoardPosition blackPosLeft = BoardPosition(blackStartRow, leftCol);
    this->board[blackStartRow][leftCol] = new Bishop(blackPosLeft, false, this);
    BoardPosition blackPosRight = BoardPosition(blackStartRow, rightCol);
    this->board[blackStartRow][rightCol] = new Bishop(blackPosRight, false, this);
}

void Board::placeQueens(int whiteStartRow, int blackStartRow) {
    int col = 3;
    
    BoardPosition whitePos = BoardPosition(whiteStartRow, col);
    this->board[whiteStartRow][col] = new Queen(whitePos, true, this);
    
    BoardPosition blackPos = BoardPosition(blackStartRow, col);
    this->board[blackStartRow][col] = new Queen(blackPos, false, this);
}

void Board::placeKings(int whiteStartRow, int blackStartRow) {
    int col = 4;
    
    BoardPosition whitePos = BoardPosition(whiteStartRow, col);
    this->board[whiteStartRow][col] = new King(whitePos, true, this);
    
    BoardPosition blackPos = BoardPosition(blackStartRow, col);
    this->board[blackStartRow][col] = new King(blackPos, false, this);
}
