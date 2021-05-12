#include "SFX.hpp"

void playScoringSound(bool ticked){
    if (ticked){
        Mix_Chunk* scoring = Mix_LoadWAV("SFX/scoring.wav");
        if( scoring == NULL ){
            printf( "Failed to load scoring sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_PlayChannel(-1, scoring, 0);
    }
    return;
}

void playMenuMusic(bool ticked){
    if (!ticked) stopMusic();
    if (ticked && Mix_PlayingMusic() != 1){
        Mix_Music* menuMusic = Mix_LoadMUS("SFX/menuMusic.wav");
        if( menuMusic == NULL ){
            printf( "Failed to load menu music! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_PlayMusic(menuMusic, -1);
    }
    return;
}

void playBackgroundMusic(bool ticked, int theme){
    if (ticked){
        Mix_Music* menuMusic = NULL;
        switch (theme)
        {
        case 1:
            menuMusic = Mix_LoadMUS("SFX/theme1Music.wav");
            break;
        case 2:
            menuMusic = Mix_LoadMUS("SFX/theme2Music.wav");
            break;
        case 3:
            menuMusic = Mix_LoadMUS("SFX/theme3Music.wav");
            break;
        }
        if( menuMusic == NULL ){
            printf( "Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_PlayMusic(menuMusic, -1);
    }
    return;
}

void playTimesUpSound(bool ticked){
    if (ticked){
        Mix_Chunk* timesup = Mix_LoadWAV("SFX/timesup.wav");
        if( timesup == NULL ){
            printf( "Failed to load timesup sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_PlayChannel(-1, timesup, 0);
    }
}

void playClickingSound(bool ticked){
    if (ticked){
        Mix_Chunk* click_sound = Mix_LoadWAV("SFX/mouse_click.wav");
        if( click_sound == NULL ){
            printf( "Failed to load clicking sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_PlayChannel(-1, click_sound, 0);
    }
    return;
}

void stopMusic(){
    if (Mix_PlayingMusic() == 1){
        Mix_HaltMusic();
    }
}

void pauseMusic(){
    if (Mix_PlayingMusic() == 1){
        Mix_PauseMusic();
    }
}

void resumeMusic(){
    if (Mix_PlayingMusic() == 1){
        Mix_ResumeMusic();
    }
}