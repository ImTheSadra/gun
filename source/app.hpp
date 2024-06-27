#include <SDL2/SDL.h>

#include "player.hpp"

using namespace std;

class App{
private:
    void draw(){
        SDL_SetRenderDrawColor(this->renderer, 50, 50, 50, 255);
        SDL_RenderClear(this->renderer);

        // SDL_SetRenderDrawColor(this->renderer, 200, 200, 200, 255);
        // drawCircle(this->renderer, 20, 20, 10);

        this->player.draw(this->renderer);

        SDL_RenderPresent(this->renderer);
    }

    void update(){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){this->running = false;}
            this->player.checkEvent(event);
        }

        this->player.update();
    }
public:
    bool running = true;
    int WIDTH, HEIGHT;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Player player = Player();

    App(){
        this->WIDTH = 800;
        this->HEIGHT = 600;
        this->window = SDL_CreateWindow(
            "virtual gun", 
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            this->WIDTH, this->HEIGHT,
            SDL_WINDOW_SHOWN
        );
        this->renderer = SDL_CreateRenderer(
            this->window, -1, 0
        );
        this->player.x = WIDTH/2;
        this->player.y = HEIGHT/2;
    }

    void run(){
        while(this->running){
            int s = SDL_GetTicks();
            this->draw();
            this->update();
            int e = SDL_GetTicks();
            SDL_Delay((e-s)/5);
        }
    }
};