#include "Game.h"
#include "Board.h"
#include "Engine.h"

#include <vector>
#include <iostream>

using std::vector;

Game::Game() :
_engine( new Engine() ),
_board( new Board() ) {
    _engine->initBoard(9, _board);
}

vector<BlockInfo>* Game::allBlockInfo() const {
    return _board->allBlockInfo();
}

void Game::printBoard() {
    _board->output();
}

int* Game::boardSize() const {
    int* retval = new int[2];
    retval[0] = _board->width();
    retval[1] = _board->height();

    return retval;
}
