#include "Game_Utils.hpp"

void handlePlayButton(SDL_Renderer* renderer, Button& play, bool& inMenu, SDL_Event* e, const int& x, const int& y, bool ticked){
    if (!play.mouse_inside(x, y)){
        play.texture = loadTexture("Buttons/bPlay.png", renderer);
        SDL_RenderCopy(renderer, play.texture, NULL, &play.rect);
    }
    else {
        play.texture = loadTexture("Buttons/bmoPlay.png", renderer);
        SDL_RenderCopy(renderer, play.texture, NULL, &play.rect);
        if (e->type == SDL_MOUSEBUTTONDOWN){
            playClickingSound(ticked);
            inMenu = false;
        }
    }
}

void themeButton(int& theme, int type, Button& one, SDL_Renderer* renderer, int mx, int my, SDL_Event e, bool ticked){
    string bmo, b;
    switch (type){
        case 1:
        b = "Buttons/bTheme1.png";
        bmo = "Buttons/bmoTheme1.png";
        break;
        case 2:
        b = "Buttons/bTheme2.png";
        bmo = "Buttons/bmoTheme2.png";
        break;
        case 3:
        b = "Buttons/bTheme3.png";
        bmo = "Buttons/bmoTheme3.png";
        break;
    }
    if (theme == type){
        one.texture = loadTexture(bmo, renderer);
        SDL_RenderCopy(renderer, one.texture, NULL, &one.rect);
    } else{
        one.texture = loadTexture(b, renderer);
        SDL_RenderCopy(renderer, one.texture, NULL, &one.rect);
        if (one.mouse_inside(mx, my)){
            if (e.type == SDL_MOUSEBUTTONDOWN){
                playClickingSound(ticked);
                theme = type;
                cout << "theme chosen:" << type << endl;
            }
        }
    }
}

void handleBoxChoice(bool& ticked, Button& box, SDL_Renderer* renderer, int mx, int my, SDL_Event e, bool sfx){
    if (ticked){
        box.texture = loadTexture("Buttons/tickedBox.png", renderer);
        SDL_RenderCopy(renderer, box.texture, NULL, &box.rect);
        if (box.mouse_inside(mx, my)){
            if (e.type == SDL_MOUSEBUTTONDOWN){
                playClickingSound(sfx);
                ticked = false;
                cout << "ticked off sound or music" << endl;
            }
        }
    }
    else {
        box.texture = loadTexture("Buttons/Box.png", renderer);
        SDL_RenderCopy(renderer, box.texture, NULL, &box.rect);
        if (box.mouse_inside(mx, my)){
            if (e.type == SDL_MOUSEBUTTONDOWN){
                playClickingSound(sfx);
                ticked = true;
                cout << "ticked sound or music" << endl;
            }
        }
    }
}

void renderOptions(SDL_Renderer* renderer, SDL_Event e, bool& quit, int& theme, int& time, bool& music, bool& sfx){
    SDL_Texture* choose_time = loadTexture("Background/options.png", renderer);
    SDL_RenderCopy(renderer, choose_time, NULL, NULL);
    Button one (OPTIONS_BUTTON_1_POS_X, THEME_BUTTONS_POS_Y, "Buttons/bTheme1.png", renderer);
    Button two (OPTIONS_BUTTON_2_POS_X, THEME_BUTTONS_POS_Y, "Buttons/bTheme2.png", renderer);
    Button three (OPTIONS_BUTTON_3_POS_X, THEME_BUTTONS_POS_Y, "Buttons/bTheme3.png", renderer);
    Button halfmin (OPTIONS_BUTTON_1_POS_X, TIME_BUTTONS_POS_Y, "Buttons/b30.png", renderer, 2);
    Button min (OPTIONS_BUTTON_2_POS_X, TIME_BUTTONS_POS_Y, "Buttons/b60.png", renderer, 2);
    Button minhalf (OPTIONS_BUTTON_3_POS_X, TIME_BUTTONS_POS_Y, "Buttons/b90.png", renderer, 2);
    Button boxMus (OPTIONS_BUTTON_1_POS_X - 5, TIME_BUTTONS_POS_Y + 80, "Buttons/Box.png", renderer);
    Button boxSFX (OPTIONS_BUTTON_2_POS_X + 45, TIME_BUTTONS_POS_Y + 80, "Buttons/Box.png", renderer);
    Button back (OK_BUTTON_POS_X, OK_BUTTON_POS_Y, "Buttons/bOk.png", renderer);
    SDL_RenderPresent(renderer);
    bool done = false;

    while (!done){
        if (e.type == SDL_QUIT) quit = true;
        while (SDL_PollEvent(&e) != 0 && !done){
            playMenuMusic(music);
            SDL_RenderCopy(renderer, choose_time, NULL, NULL);
            if (e.type == SDL_QUIT) break;
            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
                int mx, my;
                SDL_GetMouseState(&mx, &my);

                themeButton(theme, 1, one, renderer, mx, my, e, sfx);
                themeButton(theme, 2, two, renderer, mx, my, e, sfx);
                themeButton(theme, 3, three, renderer, mx, my, e, sfx);
                handleTimeButton(time, 30000, halfmin, renderer, mx, my, e, sfx);
                handleTimeButton(time, 60000, min, renderer, mx, my, e, sfx);
                handleTimeButton(time, 90000, minhalf, renderer, mx, my, e, sfx);
                handleBoxChoice(music, boxMus, renderer, mx, my, e, sfx);
                handleBoxChoice(sfx, boxSFX, renderer, mx, my, e, sfx);

                if (back.mouse_inside(mx, my)){
                    back.texture = loadTexture("Buttons/bmoOk.png", renderer);
                    SDL_RenderCopy(renderer, back.texture, NULL, &back.rect);
                    if (e.type == SDL_MOUSEBUTTONDOWN){
                        playClickingSound(sfx);
                        back.texture = loadTexture("Buttons/bmoOk.png", renderer);
                        SDL_RenderCopy(renderer, back.texture, NULL, &back.rect);
                    } else if (e.type == SDL_MOUSEBUTTONUP){
                        done = true;
                        break;
                    }
                } else {
                    back.texture = loadTexture("Buttons/bOk.png", renderer);
                    SDL_RenderCopy(renderer, back.texture, NULL, &back.rect);
                }
                SDL_RenderPresent(renderer);
            }
        }
    }
}

void handleOptionsButton(SDL_Renderer* renderer, int& theme, int& time, Button& themes, bool& inMenu, SDL_Event* e, const int& x, const int& y, bool& music, bool& sfx){
    if (!themes.mouse_inside(x, y)){
        themes.texture = loadTexture("Buttons/bOptions.png", renderer);
        SDL_RenderCopy(renderer, themes.texture, NULL, &themes.rect);
    } else {
        themes.texture = loadTexture("Buttons/bmoOptions.png", renderer);
        SDL_RenderCopy(renderer, themes.texture, NULL, &themes.rect);
        if (e->type == SDL_MOUSEBUTTONDOWN){
            playClickingSound(sfx);
            renderOptions(renderer, *e, inMenu, theme, time, music, sfx);
        }
    }
}

void backButton(SDL_Texture* rule, SDL_Renderer* renderer, SDL_Event* e, bool sfx){
    SDL_RenderCopy(renderer, rule, NULL, NULL);
    Button back(OK_BUTTON_POS_X, OK_BUTTON_POS_Y, "Buttons/bOk.png", renderer);
    SDL_RenderPresent(renderer);
    bool done = false;

    while(!done){
        if (e->type == SDL_QUIT) break;
        while (SDL_PollEvent(e) != 0 && !done){
            SDL_RenderCopy(renderer, rule, NULL, NULL);
            if (e->type == SDL_QUIT){
                done = true;
                break;
            }
            if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
                int mx, my;
                SDL_GetMouseState(&mx, &my);

                if (back.mouse_inside(mx, my)){
                    back.texture = loadTexture("Buttons/bmoOk.png", renderer);
                    SDL_RenderCopy(renderer, back.texture, NULL, &back.rect);
                    if (e->type == SDL_MOUSEBUTTONDOWN){
                        playClickingSound(sfx);
                        done = true;
                    }
                } else {
                    back.texture = loadTexture("Buttons/bOk.png", renderer);
                    SDL_RenderCopy(renderer, back.texture, NULL, &back.rect);
                }
                SDL_RenderPresent(renderer);
            }
        }
    }
}

void handleHelpButton(SDL_Renderer* renderer, SDL_Texture* menu, Button& help, bool& inMenu, SDL_Event* e, const int& x, const int& y, bool sfx){
    if (!help.mouse_inside(x, y)){
        help.texture = loadTexture("Buttons/bHelp.png", renderer);
        SDL_RenderCopy(renderer, help.texture, NULL, &help.rect);
    }
    else {
        help.texture = loadTexture("Buttons/bmoHelp.png", renderer);
        SDL_RenderCopy(renderer, help.texture, NULL, &help.rect);
        if (e->type == SDL_MOUSEBUTTONDOWN){
            playClickingSound(sfx);
            SDL_Texture* rule = loadTexture("Background/help.png", renderer);
            SDL_RenderCopy(renderer, rule, NULL, NULL);
            SDL_RenderPresent(renderer);
            backButton(rule, renderer, e, sfx);
        }
    }
}

void handleExitButton(SDL_Renderer* renderer, Button& exit, bool& quit, SDL_Event* e, const int& x, const int& y, bool sfx){
    if (!exit.mouse_inside(x, y)){
        exit.texture = loadTexture("Buttons/bExit.png", renderer);
        SDL_RenderCopy(renderer, exit.texture, NULL, &exit.rect);
    } else {
        exit.texture = loadTexture("Buttons/bmoExit.png", renderer);
        SDL_RenderCopy(renderer, exit.texture, NULL, &exit.rect);
        if (e->type == SDL_MOUSEBUTTONDOWN){
            playClickingSound(sfx);
            quit = true;
        }
    }
}

void handleTimeButton(int& time, int type, Button& one, SDL_Renderer* renderer, int mx, int my, SDL_Event e, bool sfx){
    string bmo, b;
    switch (type){
        case 30000:
        b = "Buttons/b30.png";
        bmo = "Buttons/bmo30.png";
        break;
        case 60000:
        b = "Buttons/b60.png";
        bmo = "Buttons/bmo60.png";
        break;
        case 90000:
        b = "Buttons/b90.png";
        bmo = "Buttons/bmo90.png";
        break;
    }
    if (time == type){
        one.texture = loadTexture(bmo, renderer);
        SDL_RenderCopy(renderer, one.texture, NULL, &one.rect);
    } else{
        one.texture = loadTexture(b, renderer);
        SDL_RenderCopy(renderer, one.texture, NULL, &one.rect);
        if (one.mouse_inside(mx, my)){
            if (e.type == SDL_MOUSEBUTTONDOWN){
                playClickingSound(sfx);
                time = type;
                cout << "time chosen:" << type << endl;
            }
        }
    }
}

int drawHighScore(int time, int score){
    string path = "";
    switch(time){
        case DEFAULT_TIME:
            path = "HighScoreFiles/hiScore30.txt";
            break;
        case ONE_MINUTE:
            path = "HighScoreFiles/hiScore60.txt";
            break;
        case A_MIN_AND_A_HALF:
            path = "HighScoreFiles/hiScore90.txt";
            break;
    }
    ifstream file(path);
    int hi_score;
    file >> hi_score;
    cout << "hi: " << hi_score << ", score: " << score << endl;
    if (hi_score < score){
        hi_score = score;
        ofstream file(path);
        file << hi_score;
    }
    return hi_score;
}