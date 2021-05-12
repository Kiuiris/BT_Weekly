#include "Object.hpp"

Object::Object (int _x, int _y){
    p.x = _x;
    p.y = _y;
}
    
void Object::render (SDL_Renderer* renderer, SDL_Texture* egg, SDL_Point& point){
    SDL_QueryTexture(egg, NULL, NULL, &rect.w, &rect.h);
    rect.x = point.x;
    rect.y = point.y;
    SDL_RenderCopy(renderer, egg, NULL, &rect);
}