#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include "SDL_Utils.hpp"

struct Object {
    SDL_Point p;
    SDL_Rect rect;

    Object (int _x, int _y);
    
    void render(SDL_Renderer* renderer, SDL_Texture* egg, SDL_Point& point);

};

#endif //OBJECT_H