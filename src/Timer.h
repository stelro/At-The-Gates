/*
 * src/Timer.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Timer, used to controls the *frame rate per second* fps
 * in our game
 *
 */

#ifndef TOK_TIMER_H
#define TOK_TIMER_H

#include <iostream>
#include <SDL2/SDL.h>

namespace tok {

    class Timer {
    private:
        //The clock time when timer started
        size_t _startTicks;

        //The ticks stored when the timer was paused
        size_t _pausedTicks;

        //The timer status
        bool _paused;
        bool _started;

    public:
        //Constructor
        Timer();
        //explicitly delete special member functions
        //assign constructor and copy consturctor
        Timer &operator =(const Timer&) = delete;
        Timer(const Timer&) = delete;

        //Clock actions
        void start();
        void stop();
        void pause();
        void unpause();

        size_t get_ticks();

        bool is_started();
        bool is_paused();
    };
}


#endif //TOK_TIMER_H
