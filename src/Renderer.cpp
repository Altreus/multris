#include "Renderer.h"
#include "Game.h"
#include "Board.h"

#include <vector>

using std::vector;

void Renderer::init(
int screenWidth,
int screenHeight) {
    _screen = NULL;
    _playarea = NULL;
    _game = NULL;
    
    SDL_Surface* screen =
        SDL_SetVideoMode( 
            screenWidth, screenHeight, 0,
            SDL_HWSURFACE|SDL_ANYFORMAT
        );

    if(screen == NULL) {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        // TODO: Exiting here is overkill. Throw.
        exit(1);
    }

    _screen = screen;

    _playarea = new PlayArea();
}

void Renderer::game(const Game* game) {
    _game = game;
    _playarea->setBoardSize(_game->boardSize());
}

void Renderer::terminate() {
    // Clear out temp surfaces.
}

void Renderer::draw() {
    vector<BlockInfo>* blocks = _game->allBlockInfo();
    
    for(vector<BlockInfo>::const_iterator i = blocks->begin();
        i != blocks->end();
        ++i) {
        _playarea->setPiece( i->x, i->y, i->type );
    }

    delete blocks;

    SDL_Rect srcrect = _playarea->rect(), 
             destrect = srcrect;

    SDL_BlitSurface(_playarea->buf(), &srcrect, _screen, &destrect);
    SDL_UpdateRect(_screen,0,0,0,0);
}

PlayArea::PlayArea() :
_blockSize(16),
x(0), y(0), _buf(NULL) {
}

SDL_Surface* PlayArea::buf() const {
    return _buf;
}

SDL_Rect PlayArea::rect() const {
    SDL_Rect retval;
    retval.x = x;
    retval.y = y;
    retval.w = _buf->w;
    retval.h = _buf->h;

    return retval;
}

void PlayArea::setPiece(int xpos, int ypos, int type) {
    SDL_Rect rect;
    rect.x = _blockSize * xpos;
    rect.y = _blockSize * ypos;
    rect.w = rect.h = _blockSize;
    Uint8 r = 0, g = 0, b = 0;

    switch(type) {
        case 1:
            r = 0xFF;
            break;
        case 2:
            g = 0xFF;
            break;
        case 3:
            b = 0xFF;
            break;
        case 4:
            r = g = b = 0xFF;
            break;
    }

    SDL_FillRect(_buf, &rect, SDL_MapRGB(_buf->format, r, g, b));
}

void PlayArea::setBoardSize(int* size) {
    if(!_buf) {
        int bufw = _blockSize * size[0];
        int bufh = _blockSize * size[1];
        _buf = SDL_CreateRGBSurface(SDL_HWSURFACE, bufw, bufh, 32, 0,0,0,0);
    }

    delete[] size;
}
