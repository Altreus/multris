#ifndef _MS_GAME_H
#define _MS_GAME_H

#include <SDL.h>
#include <vector>

#include "Structs.h"

using std::vector;

class Engine;
class Board;

class Game {
    public:
        Game();
        void printBoard();
        vector<BlockInfo>* allBlockInfo() const;
        int* boardSize() const;

    private:
        int _score;
        Engine* _engine;
        Board* _board; 
    };

#endif
