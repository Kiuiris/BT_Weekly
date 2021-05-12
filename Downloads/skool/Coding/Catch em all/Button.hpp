#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "SDL_Utils.hpp"

struct Button{
    SDL_Texture* texture;
    SDL_Rect rect;

    Button (int _x, int _y, const char* button, SDL_Renderer* rend, int ratio = 1);

    bool mouse_inside(int x, int y);
};


#endif //BUTTON_H