#include "SDL_Utils.hpp"


void LogError(const string& msg, int error)
{
    switch (error){
        case SDL_Error:
            cout << msg << SDL_GetError() << endl;
            break;
        case IMG_Error:
            cout << msg << IMG_GetError() << endl;
            break;
        case MIX_Error:
            cout << msg << Mix_GetError() << endl;
            break;
        case TTF_Error:
            cout << msg << TTF_GetError() << endl;
            break;
    }
}


void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, const int width, const int height, const string title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        LogError("SDL_Init", SDL_Error);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == nullptr)
        LogError("CreateWindow", SDL_Error);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr)
        LogError("CreateRenderer", SDL_Error);

    if( TTF_Init() == -1 ){
        LogError("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_Error);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
        LogError("SDL_mixer could not initialize! SDL_mixer Error: ", MIX_Error);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, width, height);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilSpacePressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             ((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer){
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr){
        cout << "Unable to load image " << path << " SDL_Image Error: " << IMG_GetError() << endl;
    }
    else {
        newTexture = SDL_CreateTextureFromSurface (renderer, loadedSurface);
        if (newTexture == nullptr){
            cout << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

void renderTextToScreen(string text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer){
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), color );
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
    textRect.x = x;
    textRect.y = y;     
    SDL_RenderCopy( renderer, textTexture, NULL, &textRect);
}