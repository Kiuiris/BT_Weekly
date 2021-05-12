#include "Catcher.hpp"


Catcher::Catcher (int _x, int _y){
    x = _x;
    y = _y;
}

void Catcher::render(SDL_Renderer* renderer, SDL_Texture* basket){
    SDL_QueryTexture(basket, NULL, NULL, &rect.w, &rect.h);
    rect.x = x;
    rect.y = y;
    SDL_RenderCopy(renderer, basket, NULL, &rect);
}

void Catcher::moveleft(){
    if (x >= 0){
        x -= CATCHER_VEL;
    } else x += CATCHER_VEL;
}

void Catcher::moveright(){
    if (x <= WIDTH - rect.w){
        x += CATCHER_VEL;
    } else x -= CATCHER_VEL;
}

void Catcher::handle_input(SDL_Event e){
    if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.sym)
        {
            case SDLK_ESCAPE: break;
            case SDLK_LEFT:
                moveleft();
                break;
            case SDLK_RIGHT:
                moveright();
                break;
            default:
                break;
        }
    } 
}

bool Catcher::checkCollision(vector<SDL_Point>& ob, int i, SDL_Rect egg){
    if (ob[i].x > x && ob[i].x < (x + rect.w) && ob[i].y > y && (ob[i].y + egg.h < y + rect.h)){
        return true;
    } else return false;
}

void Catcher::update(SDL_Rect egg, int& score, vector<SDL_Point>& obs, int i, int& vel, int& rand, bool sfx){
    if (checkCollision(obs, i, egg)){
        playScoringSound(sfx);
        score++;
        obs.erase(obs.begin() + i);
        if (score % LEVEL_UP_SCORE == 0 && rand > MIN_RAND){
            cout << "faster!" << endl;
            vel++;
            rand -= LEVEL_UP_RAND;
        }
    }
}