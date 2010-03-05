#ifndef _MS_ENGINE_H_
#define _MS_ENGINE_H_

#include "Structs.h"

class Board;

class Engine {
    public:
        Piece* createPiece();
        void initBoard(int, Board*);
        void tick(int);

    private:
};

#endif
