/*
 *  src/Timer.cpp - Timer, used to control the /frame rate per second/
 *  FPS in the game
 *
 *  This file is a part of At-The-Gates SDL2 Game
 *  Copyright (C) 2016  Stelmach Rostislav
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Timer.h"

namespace atg {

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

    size_t Timer::get_ticks() const
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

    bool Timer::is_started() const
    {
        return _started;
    }

    bool Timer::is_paused() const
    {
        return _paused;
    }

}
