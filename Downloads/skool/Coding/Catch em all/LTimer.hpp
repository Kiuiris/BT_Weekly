#ifndef TIMER_H
#define TIMER_H
#include "SDL_Utils.hpp"

struct LTimer
{
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void pause();
		void unpause();
		void stop();

		//Gets the timer's time
		Uint32 getTicks();
        
        bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};

#endif //TIMER_H