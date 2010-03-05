#include "Board.h"

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>

Board::Board() :
_h(15),_w(9),
_grid(NULL),
_piecex(0), _piecey(0),
_currentPiece(NULL)
{ 
    _grid = new int*[_h];

    for(int i = 0; i < _h; ++i) {
        _grid[i] = new int[_w];
    }
}

Board::Board(int w, int h) :
_h(h),_w(w),
_grid(NULL),
_piecex(0), _piecey(0),
_currentPiece(NULL)
{ 
    _grid = new int*[_h];

    for(int i = 0; i < _h; ++i) {
        _grid[i] = new int[_w];
    }
}

Board::~Board() {

    for(int i = 0; i < _h; ++i) {
        delete[] _grid[i];
    }
    delete[] _grid;
}

void Board::output() const {
    printf("\n");

    for (int i = 0; i < height(); ++i) {
        for (int j = 0; j < width(); ++j) {
            printf("%2d ", _grid[i][j] & typemask);
        }
        printf("\n");
    }
}

vector<BlockInfo>* Board::allBlockInfo() const {
    vector<BlockInfo>* retval = new vector<BlockInfo>();

    for(int i = 0; i < height(); ++i) {
        for(int j = 0; j < width(); ++j) {
            BlockInfo b;
            b.y = i;
            b.x = j;
            b.type = _grid[i][j] & typemask;
            b.highlighted = _grid[i][j] & fHighlighted;

            retval->push_back(b);
        }
    }

    return retval;
}

bool Board::advanceCurrentPiece() {
    // First, turn the current blocks to 0
        
    return false;
}

int Board::moveToCol(int col) {
    return 1;
}

void Board::newCurrentPiece(Piece* piece) {
}

bool Board::highlightArea(int,int) {
    return false;
}

void Board::set(BlockInfo* piece) {
    _grid[piece->y][piece->x] = piece->type & piece->highlighted;
    delete piece;
}
