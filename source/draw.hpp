#include <SDL2/SDL.h>
#include <math.h>

void drawCircle(SDL_Renderer* renderer, int x, int y, int r){
    for (int _ = 0; _ < r;_++){
        for(int angle = 0; angle < 360; angle++){
            double rad = angle*(M_PI/180);
            SDL_RenderDrawPoint(
                renderer,
                x+sin(rad)*_,
                y+cos(rad)*_ 
            );
        }
    }
}