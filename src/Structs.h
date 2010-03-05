#ifndef _MS_STRUCTS_H_
#define _MS_STRUCTS_H_

#include <vector>

using std::vector;

typedef struct {
    int x, y, type;
    bool highlighted;
} BlockInfo;

typedef struct {
    vector<BlockInfo> blocks;
    typedef vector<BlockInfo>::iterator iterator;
} Piece;

#endif
