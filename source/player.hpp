#include <SDL2/SDL.h>
#include <vector>
#include <math.h>
#include <iostream>

#include "draw.hpp"
#include "arrow.hpp"

using namespace std;

class Player{
private:
    SDL_Renderer* renderer;
    double angle = 0;
    vector<Arrow> arrows;
public:
    int x, y;
    Player(){}

    void draw(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 100, 200, 200, 255);

        drawCircle(renderer, this->x, this->y, 10);
        SDL_RenderDrawLine(
            renderer, this->x, this->y, 
            this->x+sin(this->angle)*20, this->y+cos(this->angle)*20
        );

        SDL_SetRenderDrawColor(renderer, 200, 20, 200, 255);
        for(int i = 0; i < this->arrows.size(); i++){
            if (this->arrows.at(i).out){continue;}
            int pos[2] = {
                this->arrows.at(i).x,
                this->arrows.at(i).y
            };
            drawCircle(
                renderer, pos[0], pos[1], 5
            );
            if (pos[0] > 800 or pos[0] < 0 or pos[1] > 600 or pos[1] < 0){
                this->arrows.at(i).out = true;
            }
        }
    }

    void update(){
        for (int i = 0; i < this->arrows.size(); i++){
            this->arrows.at(i).update();
        }

        auto state = SDL_GetMouseState(0,0);
        if(state & SDL_BUTTON_LEFT){
            this->arrows.push_back(
                Arrow(this->angle, this->x, this->y)
            );
        }
    }

    void checkEvent(SDL_Event event){
        if (event.type == SDL_KEYDOWN){
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_w:
                this->x += sin(this->angle)*2;
                this->y += cos(this->angle)*2;
                break;
            
            case SDLK_DOWN:
            case SDLK_s:
                this->x -= sin(this->angle)*2;
                this->y -= cos(this->angle)*2;
                break;
            
            default:
                break;
            }
        } else if (event.type == SDL_MOUSEMOTION){
            int dx = event.motion.x - this->x;
            int dy = event.motion.y - this->y;
            this->angle = atan2(dx,dy);
            // cout << atan2(dx,dy) << "\t";
        }
    }
};