#ifndef SDL_UTILS
#define SDL_UTILS
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
using namespace std;

#define SDL_Error 1
#define IMG_Error 2
#define MIX_Error 3
#define TTF_Error 4


void LogError (const string& msg, int error);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, const int width, const int height, const string title);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilSpacePressed();
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);
void renderTextToScreen(string text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);

#endif //SDL_UTILS