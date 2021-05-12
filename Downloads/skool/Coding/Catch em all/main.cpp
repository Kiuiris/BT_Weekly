#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "SDL_Utils.hpp"
#include "Catcher.hpp"
#include "Button.hpp"
#include "Game_Utils.hpp"
#include "SFX.hpp"

using namespace std;

const int SCREEN_WIDTH = WIDTH;
const int SCREEN_HEIGHT = HEIGHT;
const string WINDOW_TITLE = "CATCH 'EM ALL!";

const SDL_Color textColor = {0, 0, 0};
const SDL_Color theme2textColor = {255, 82, 0};

void renderMenu(SDL_Renderer* renderer, SDL_Event e, bool& quit, int& theme, int& time, bool& music, bool& sfx);
void renderTimesUp(const int& score, TTF_Font* font, SDL_Renderer* renderer, SDL_Event e, SDL_Texture* background, bool& quit, bool& replay, bool sfx, int time);
void renderScoreTime(TTF_Font* gFont, int score, Uint32 gameTime, SDL_Renderer* renderer, int theme);

int main(int argc, char* argv[]) {
    srand(time(NULL));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    TTF_Font* gFont = TTF_OpenFont( "Minecraft.ttf", FONT_SIZE );
    SDL_Event e;
    
    SDL_Texture* background = NULL;
    SDL_Texture* catcher = NULL;
    SDL_Texture* object = NULL;

    bool quit = false;
    bool music = true, sfx = true;
    int chosenTheme = DEFAULT_THEME;
    int timemax = DEFAULT_TIME;
    SDL_Color color;

    do {
        renderMenu(renderer, e, quit, chosenTheme, timemax, music, sfx);
        //stop menu music
        stopMusic();

        // set up game theme
        switch (chosenTheme){
            case THEME_2:
                background = loadTexture("Background/CasinoBg.jpg", renderer);
                catcher = loadTexture("CatchersAndObs/suitcase.png", renderer);
                object = loadTexture("CatchersAndObs/cash.png", renderer);
                color = theme2textColor;
                break;
            case THEME_3:
                background = loadTexture("Background/BGOmnom.jpg", renderer);
                catcher = loadTexture("CatchersAndObs/omNom.png", renderer);
                object = loadTexture("CatchersAndObs/Candy.png", renderer);
                color = textColor;
                break;
            default:
                background = loadTexture("Background/background.jpg", renderer);
                catcher = loadTexture("CatchersAndObs/basket.png", renderer);
                object = loadTexture("CatchersAndObs/Egg.png", renderer);
                color = textColor;
                break;
        }

        bool Replay = true;

        // start gameplay if not quit 
        while (!quit && Replay) {
            playBackgroundMusic(music, chosenTheme);

            Catcher Catcher (CATCHER_INIT_POS_X, CATCHER_INIT_POS_Y);
            Object Object(OBJECT_INIT_POS_X, OBJECT_INIT_POS_Y);

            int score = DEFAULT_SCORE;
            int ObsVel = DEFAULT_OBJECT_VEL;
            int ObsRand = DEFAULT_RAND;
            int ObsCount = DEFAULT_COUNT;

            vector <SDL_Point> Obs;

            LTimer gameTime;
            gameTime.start();

            // gameplay loop, out loop if time is up
            while (gameTime.getTicks() < timemax && Replay){
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, background, NULL, NULL);
                SDL_PollEvent(&e);
                
                Catcher.render(renderer, catcher);
                
                if (gameTime.getTicks() > ObsCount * ObsRand && Obs.size() < OBJECT_MAX_NUMBER){
                    ObsCount++;
                    SDL_Point add;
                    add.x = rand() % (SCREEN_WIDTH - Object.rect.w);
                    add.y = OBJECT_INIT_POS_Y;
                    Obs.push_back(add);
                }

                //erase the object after it is out of screen
                if (!Obs.empty() && Obs[0].y > SCREEN_HEIGHT){
                    Obs.erase(Obs.begin());
                }

                //render each object
                for (int i = 0; i < Obs.size(); i++){
                    Object.render(renderer, object, Obs[i]);
                    Obs[i].y += ObsVel;
                    Catcher.update(Object.rect, score, Obs, i, ObsVel, ObsRand, sfx);
                }

                renderScoreTime(gFont, score, gameTime.getTicks(), renderer, chosenTheme);
                SDL_RenderPresent(renderer);

                if (e.type == SDL_QUIT){
                    quit = true;
                    break;
                }

                //pause event
                if (e.type == SDL_KEYDOWN){
                    if (e.key.keysym.sym == SDLK_SPACE){
                        pauseMusic();
                        gameTime.pause();
                        string pauseText = "Press 'SPACE' to continue";
                        renderTextToScreen(pauseText, PAUSE_TEXT_POS_X, PAUSE_TEXT_POS_Y, gFont, color, renderer);
                        SDL_RenderPresent(renderer);
                        waitUntilSpacePressed();
                        gameTime.unpause();
                        resumeMusic();
                    } 
                }

                Catcher.handle_input(e);
            }
            stopMusic();
            if (gameTime.getTicks() >= timemax){
                renderTimesUp(score, gFont, renderer, e, background, quit, Replay, sfx, timemax);
            }
        }
    } while (!quit);

    SDL_DestroyTexture(background);
    background = NULL;
    SDL_DestroyTexture(catcher);
    catcher = NULL;
    SDL_DestroyTexture(object);
    object = NULL;

    quitSDL(window, renderer);

    return 0;
}

void renderMenu(SDL_Renderer* renderer, SDL_Event e, bool& quit, int& theme, int& time, bool& music, bool& sfx){
    SDL_Texture* menu = loadTexture("Background/menu.png", renderer);
    SDL_RenderCopy(renderer, menu, NULL, NULL);
    Button play (MENU_BUTTON_POS_X, MENU_BUTTON_POS_Y, "Buttons/bPlay.png", renderer);
    Button help (MENU_BUTTON_POS_X, MENU_BUTTON_POS_Y + play.rect.h + MENU_BUTTON_SPACING, "Buttons/bHelp.png", renderer);
    Button options (MENU_BUTTON_POS_X, help.rect.y + help.rect.h + MENU_BUTTON_SPACING, "Buttons/bOptions.png", renderer);
    Button exit (MENU_BUTTON_POS_X, options.rect.y + options.rect.h + MENU_BUTTON_SPACING, "Buttons/bExit.png", renderer);
    SDL_RenderPresent(renderer);

    bool inMenu = true;
    while (!quit && inMenu){
        if (e.type == SDL_QUIT) quit = true;
        while (SDL_PollEvent(&e) != 0 && inMenu){
            playMenuMusic(music);
            SDL_RenderCopy(renderer, menu, NULL, NULL);
            if (e.type == SDL_QUIT){
                break;
            }
            int x, y;
            SDL_GetMouseState( &x, &y );

            handlePlayButton(renderer, play, inMenu, &e, x, y, sfx);
            handleExitButton(renderer, exit, quit, &e, x, y, sfx);
            handleHelpButton(renderer, menu, help, inMenu, &e, x, y, sfx);
            handleOptionsButton(renderer, theme, time, options, inMenu, &e, x, y, music, sfx);

            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyTexture(menu);
}

void renderTimesUp(const int& score, TTF_Font* font, SDL_Renderer* renderer, SDL_Event e, SDL_Texture* background, bool& quit, bool& Replay, bool sfx, int time){
    playTimesUpSound(sfx);
    int hi_score = drawHighScore(time, score);

    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_Texture* gameOver = loadTexture("Background/timesUp.png", renderer);
    SDL_Rect overRect;
    SDL_QueryTexture(gameOver, NULL, NULL, &overRect.w, &overRect.h);
    overRect.w /= 2;
    overRect.h /= 2;
    overRect.x = SCREEN_WIDTH/2 - overRect.w/2;
    overRect.y = SCREEN_HEIGHT/2 - overRect.h/2;
    SDL_RenderCopy(renderer, gameOver, NULL, &overRect);

    string yourScore = "YOUR SCORE: " + to_string(score);
    renderTextToScreen(yourScore, TIMESUP_SCORE_POS_X, TIMESUP_SCORE_POS_Y, font, textColor, renderer);

    string hiScore = "HI SCORE: " + to_string(hi_score);
    renderTextToScreen(hiScore, TIMESUP_SCORE_POS_X, TIMESUP_SCORE_POS_Y + TIMESUP_SCORE_SPACING, font, textColor, renderer);
    

    Button replay (TIMESUP_FIRST_BUTTON_POS_X, TIMESUP_BUTTONS_POS_Y, "Buttons/bReplay.png", renderer);
    Button gameExit (TIMESUP_SEC_BUTTON_POS_X, TIMESUP_BUTTONS_POS_Y, "Buttons/bGameExit.png", renderer);
    Button toMenu (TIMESUP_THIRD_BUTTON_POS_X , TIMESUP_BUTTONS_POS_Y, "Buttons/bMenu.png", renderer);

    SDL_RenderPresent(renderer);
    bool inTimesup = false;
    while (!inTimesup){
        if (e.type == SDL_QUIT){
            quit = true;
            break;
        }

        while (SDL_PollEvent(&e) != 0){
            SDL_RenderCopy(renderer, background, NULL, NULL);
            SDL_RenderCopy(renderer, gameOver, NULL, &overRect);
            renderTextToScreen(yourScore, TIMESUP_SCORE_POS_X, TIMESUP_SCORE_POS_Y, font, textColor, renderer);
            renderTextToScreen(hiScore, TIMESUP_SCORE_POS_X, TIMESUP_SCORE_POS_Y + TIMESUP_SCORE_SPACING, font, textColor, renderer);

            int mX, mY;
            SDL_GetMouseState(&mX, &mY);
            if (replay.mouse_inside(mX, mY)){
                replay.texture = loadTexture("Buttons/bmoReplay.png", renderer);
                SDL_RenderCopy(renderer, replay.texture, NULL, &replay.rect);
                if (e.type == SDL_MOUSEBUTTONDOWN){
                    playClickingSound(sfx);
                    inTimesup = true;
                    quit = false;
                    break;
                }
            } else {
                replay.texture = loadTexture("Buttons/bReplay.png", renderer);
                SDL_RenderCopy(renderer, replay.texture, NULL, &replay.rect);
            }
            if (gameExit.mouse_inside(mX, mY)){
                gameExit.texture = loadTexture("Buttons/bmoGameExit.png", renderer);
                SDL_RenderCopy(renderer, gameExit.texture, NULL, &gameExit.rect);
                if (e.type == SDL_MOUSEBUTTONDOWN){
                    playClickingSound(sfx);
                    inTimesup = true;
                    quit = true;
                    break;
                }
            } else {
                gameExit.texture = loadTexture("Buttons/bGameExit.png", renderer);
                SDL_RenderCopy(renderer, gameExit.texture, NULL, &gameExit.rect);
            }
            if (toMenu.mouse_inside(mX, mY)){
                toMenu.texture = loadTexture("Buttons/bmoMenu.png", renderer);
                SDL_RenderCopy(renderer, toMenu.texture, NULL, &toMenu.rect);
                if (e.type == SDL_MOUSEBUTTONDOWN){
                    playClickingSound(sfx);
                    inTimesup = true;
                    Replay = false;
                    quit = false;
                    break;
                }
            } else {
                toMenu.texture = loadTexture("Buttons/bMenu.png", renderer);
                SDL_RenderCopy(renderer, toMenu.texture, NULL, &toMenu.rect);
            }
            SDL_RenderPresent(renderer);
        }
    }
}

void renderScoreTime(TTF_Font* gFont, int score, Uint32 gameTime, SDL_Renderer* renderer, int theme){
    SDL_Color color = textColor;
    if (theme == THEME_2){
        color = theme2textColor;
    }
    string yourScore = "YOUR SCORE: " + to_string(score);
    renderTextToScreen(yourScore, GAME_SCORE_TEXT_POS_X, GAME_TEXT_POS_Y, gFont, color, renderer);

    int min = gameTime/ONE_MINUTE;
    int sec = (gameTime - ONE_MINUTE*min)/ONE_SEC;
    string time;
    if (sec < 10) time = "TIME: " + to_string(min) + ":0" + to_string(sec);
    else time = "TIME: " + to_string(min) + ":" + to_string(sec);
    renderTextToScreen(time, GAMETIME_TEXT_POS_X, GAME_TEXT_POS_Y, gFont, color, renderer);
}