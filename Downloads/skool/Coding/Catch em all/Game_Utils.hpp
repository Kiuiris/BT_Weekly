#ifndef GAME_UTILS
#define GAME_UTILS
#include <fstream>
#include "SDL_Utils.hpp"
#include "Button.hpp"
#include "LTimer.hpp"
#include "SFX.hpp"

#define HEIGHT 545
#define WIDTH 800

#define FONT_SIZE 28

#define MENU_BUTTON_POS_X 340
#define MENU_BUTTON_POS_Y 300
#define MENU_BUTTON_SPACING 5

#define OK_BUTTON_POS_X 370
#define OK_BUTTON_POS_Y 450

#define THEME_1 1
#define THEME_2 2
#define THEME_3 3

#define OPTIONS_BUTTON_1_POS_X 350
#define OPTIONS_BUTTON_2_POS_X 500
#define OPTIONS_BUTTON_3_POS_X 650
#define THEME_BUTTONS_POS_Y 170
#define TIME_BUTTONS_POS_Y 275

#define TIMESUP_SCORE_POS_X 200
#define TIMESUP_SCORE_POS_Y 252
#define TIMESUP_SCORE_SPACING 60
#define TIMESUP_FIRST_BUTTON_POS_X 275
#define TIMESUP_SEC_BUTTON_POS_X 375
#define TIMESUP_THIRD_BUTTON_POS_X 475
#define TIMESUP_BUTTONS_POS_Y 375

#define DEFAULT_TIME 30000
#define DEFAULT_THEME 1
#define DEFAULT_SCORE 0
#define DEFAULT_OBJECT_VEL 2
#define DEFAULT_RAND 800
#define DEFAULT_COUNT 0

#define MIN_RAND 500
#define LEVEL_UP_SCORE 15
#define LEVEL_UP_RAND 50

#define ONE_MINUTE 60000
#define A_MIN_AND_A_HALF 90000
#define ONE_SEC 1000

#define CATCHER_INIT_POS_X 336
#define CATCHER_INIT_POS_Y 400

#define CATCHER_VEL 10

#define OBJECT_INIT_POS_X 100
#define OBJECT_INIT_POS_Y 10
#define OBJECT_MAX_NUMBER 6

#define PAUSE_TEXT_POS_X 200
#define PAUSE_TEXT_POS_Y 100

#define GAME_SCORE_TEXT_POS_X 45
#define GAMETIME_TEXT_POS_X 600
#define GAME_TEXT_POS_Y 10



void handlePlayButton(SDL_Renderer* renderer, Button& play, bool& inMenu, SDL_Event* e, const int& x, const int& y, bool sfx);

void renderOptions(SDL_Renderer* renderer, SDL_Event e, bool& quit, int& theme, int& time, bool& music, bool& sfx);

void handleOptionsButton(SDL_Renderer* renderer, int& theme, int& time, Button& themes, bool& inMenu, SDL_Event* e, const int& x, const int& y, bool& music, bool& sfx);

void backButton(SDL_Texture* rule, SDL_Renderer* renderer, SDL_Event* e, bool sfx);

void handleHelpButton(SDL_Renderer* renderer, SDL_Texture* menu, Button& help, bool& inMenu, SDL_Event* e, const int& x, const int& y, bool sfx);

void handleExitButton(SDL_Renderer* renderer, Button& exit, bool& quit, SDL_Event* e, const int& x, const int& y, bool sfx);

void handleTimeButton(int& theme, int type, Button& one, SDL_Renderer* renderer, int mx, int my, SDL_Event e, bool sfx);

int drawHighScore(int time, int score);

#endif //GAME_UTILS