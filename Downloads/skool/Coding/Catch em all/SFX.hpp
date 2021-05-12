#ifndef SOUND_EFFECTS
#define SOUND_EFFECTS

#include "SDL_Utils.hpp"

void playScoringSound(bool ticked);

void playMenuMusic(bool ticked);

void playBackgroundMusic(bool ticked, int theme);

void playTimesUpSound(bool ticked);

void playClickingSound(bool ticked);

void stopMusic();

void pauseMusic();

void resumeMusic();

#endif //SOUND_EFFECTS