#ifndef CATCHER_H
#define CATCHER_H

#include "SDL_Utils.hpp"
#include "Object.hpp"
#include "Game_Utils.hpp"
#include "SFX.hpp"
#include <vector>

struct Catcher{
    int x;
    int y;
    SDL_Rect rect;

    Catcher (int _x, int _y);

    void render(SDL_Renderer* renderer, SDL_Texture* basket);

    void moveleft();

    void moveright();

    void handle_input(SDL_Event e);

    bool checkCollision(vector<SDL_Point>& ob, int i, SDL_Rect egg);

    void update(SDL_Rect egg, int& score, vector<SDL_Point>& obs, int i, int& vel, int& rand, bool sfx);
};

#endif //CATCHER_H