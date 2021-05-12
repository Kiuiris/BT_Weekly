#include "Button.hpp"

Button::Button (int _x, int _y, const char* button, SDL_Renderer* rend, int ratio){
    texture = loadTexture(button, rend);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = _x;
    rect.y = _y;
    rect.h /= ratio;
    rect.w /= ratio;
    SDL_RenderCopy(rend, texture, NULL, &rect);
}

bool Button::mouse_inside(int x, int y){
    //check if mouse is left, right, above or under button
    if (x < rect.x || x > rect.x + rect.w || y < rect.y || y > rect.y + rect.h) return false;
    else return true;
}