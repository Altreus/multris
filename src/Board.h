#ifndef _MS_BOARD_H
#define _MS_BOARD_H

#include <vector>

#include "Structs.h"

using std::vector;

class Board {
    public:
        Board();
        Board(int, int);
        ~Board();

        vector<BlockInfo>* allBlockInfo() const;

        int width() const { return _w; }
        int height() const { return _h; }
        void output() const;

        void set(BlockInfo*);
        bool advanceCurrentPiece();
        int moveToCol(int);
        // The ints are the coords, in pairs.
        void newCurrentPiece(Piece*);
        bool highlightArea(int,int);

    private:
        int _h, _w;
        int** _grid;
        int _piecex, _piecey;
        Piece* _currentPiece;

    public:
        static const int fHighlighted = 0x100; // 127 should be enough block types.
        static const int fCurrentPiece = 0x200;
        static const int typemask = 0x0FF; // These bits are for the block type.
};

#endif
