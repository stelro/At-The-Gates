/*
 * src/Timer.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Timer, used to controls the *frame rate per second* fps
 * in our game
 *
 */

#include "Timer.h"

namespace tok {

    Timer::Timer()
    {
        _startTicks = 0;
        _pausedTicks = 0;
        _paused = false;
        _started = false;
    }

    void Timer::start()
    {
        _started = true;
        _paused = false;
        _startTicks = SDL_GetTicks();
    }

    void Timer::stop()
    {
        _started = false;
        _paused = false;
    }

    void Timer::pause()
    {
        if ((_started) && (!_paused)) {
            _paused = true;
            _pausedTicks = SDL_GetTicks() - _startTicks;
        }
    }

    void Timer::unpause()
    {
        if (_paused) {

            _paused = false;
            //Reset the starting ticks
            _startTicks = SDL_GetTicks() - _pausedTicks;
            _pausedTicks = 0;
        }
    }

    size_t Timer::get_ticks()
    {
        if (_started) {

            if (_paused)
                return _pausedTicks;
            else
                return SDL_GetTicks() - _startTicks;
        }

        // if the timer isn't running
        return 0;
    }

    bool Timer::is_started()
    {
        return _started;
    }

    bool Timer::is_paused()
    {
        return _paused;
    }

}
