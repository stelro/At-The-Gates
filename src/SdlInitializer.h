/*
 *  src/SdlInitializer.h - Initialize SDL2 with the passed flags from
 *  the user, creates and initialize the main window, renderer and
 *  main_event handler!
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

#ifndef atg_SDLINITIALIZER_H
#define atg_SDLINITIALIZER_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

#include "ErrorHandler.h"

namespace atg {

    class SdlInitializer {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event *main_event;
    public:
        SdlInitializer();
        SdlInitializer(Uint32 flags,const std::string &title, const uint32_t pos_x, const uint32_t pos_y,
                       const uint32_t passed_width, const uint32_t passed_height) throw(ErrorHandler);
        SdlInitializer &operator =(const SdlInitializer&) = delete;
        SdlInitializer(const SdlInitializer&) = delete;
        virtual ~SdlInitializer();
    public:
        SDL_Renderer *GetRenderer() const;
        SDL_Event *GetMainEvent() const;
        void SdlBegin() const;
        void SdlEnd() const;
    };
}

#endif //atg_SDLINITIALIZER_H
