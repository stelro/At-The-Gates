/*
 *  src/SdlInitializer.cpp - Initialize SDL2 with the passed flags from
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


#include "SdlInitializer.h"
#include "ErrorHandler.h"

namespace atg {

    SdlInitializer::SdlInitializer(Uint32 flags, const std::string &title, const uint32_t pos_x,
                                   const uint32_t pos_y, const uint32_t passed_width, const uint32_t passed_height) throw (ErrorHandler) :
        window(nullptr), renderer(nullptr)
    {

        if (SDL_Init(flags) != 0)
            throw ErrorHandler();

        window = SDL_CreateWindow(title.c_str(), pos_x, pos_y, passed_width, passed_height,
                                  SDL_WINDOW_OPENGL);

        if (window == nullptr) {
            throw ErrorHandler("Could not create SDL Window");
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) {
            throw ErrorHandler("Could not create SDL Renderer");
        }

        main_event = new SDL_Event();


    }

    SDL_Renderer *SdlInitializer::GetRenderer() const
    {
        return renderer;
    }

    SDL_Event *SdlInitializer::GetMainEvent() const
    {
        return main_event;
    }

    void SdlInitializer::SdlBegin() const
    {
        SDL_PollEvent(main_event);
        SDL_RenderClear(renderer);
    }

    void SdlInitializer::SdlEnd() const
    {
        SDL_RenderPresent(renderer);
    }

    SdlInitializer::~SdlInitializer()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        delete main_event;
        SDL_Quit();
    }

}