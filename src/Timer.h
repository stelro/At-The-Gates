/*
 *  src/Timer.h - Timer, used to control the /frame rate per second/
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
