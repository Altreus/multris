#ifndef _MS_RENDERER_H
#define _MS_RENDERER_H

#include <SDL.h>
#include <cmath>

#define RENDERER Renderer::getInstance()

class Game;
class PlayArea;

class Renderer {
    public:
        static Renderer& getInstance() { static Renderer r; return r; }
        void init(int,int);//MS_RendererInfo& info);
        void terminate();
        void draw();
        void game(const Game*);

    private:
        SDL_Surface* _screen;
        PlayArea* _playarea;
        const Game* _game;
};

class PlayArea {
    public:
        PlayArea();
        SDL_Surface* buf() const;
        SDL_Rect rect() const;

        void setPiece(int,int,int);
        void setBoardSize(int*);

    private:
        int _blockSize;
        int x,y;
        SDL_Surface* _buf;
};

#endif
