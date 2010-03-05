#include <stdlib.h>
#include <iostream>
#include <SDL.h>
#include <math.h>

#include "Renderer.h"
#include "Game.h"
#include "Board.h"
#include "Engine.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
    srand(10);

    atexit(SDL_Quit);
    
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0) {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        exit(1);
    }
    
    bool done = false;
    
    RENDERER.init(SCREEN_WIDTH,SCREEN_HEIGHT);
    Game* game = new Game();

    RENDERER.game(game);

    while(!done) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                done = true;
                continue;
            }
            else {
                // INPUT.handle(event);
            }
        }
        RENDERER.draw();
    }
    
    delete game;
    return 0;
}
