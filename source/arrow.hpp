#include <math.h>
#include <SDL2/SDL.h>

class Arrow {
public:
    bool out = false;
    Arrow(double angle, int x, int y){
        this->angle = angle;
        this->x = x; this->y = y;
    }

    void update(){
        if (this->out){return;}
        this->x += sin(angle);
        this->y += cos(angle);
    }
    double angle, x, y;
private:
};