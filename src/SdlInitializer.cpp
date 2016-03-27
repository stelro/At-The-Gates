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

        //main window in the game
        //pos_x and pos_y is the possition where the main window will show up
        //in the screen, passed_width and passed_height is the dimensions of the
        //main window in screen cordinates
        //SDL_WINDOW_OPENGL flag, window usable with OpenGL context


        /*
         * window flags may be any of the following OR'd together
         *
         * SDL_WINDOW_FULLSCREEN = fullscreen window
         * SDL_WINDOW_FULLSCREEN_DESKTOP = fullscreen window at the current desktop resolution
         * SDL_WINDOW_OPENGL = window usable with OpenGL context
         * SDL_WINDOW_HIDDEN = window is not visible
         * SDL_WINDOW_BORDERLESS = no window decoration
         * SDL_WINDOW_RESIZABLE = window can be resized
         * SDL_WINDOW_MINIMIZED = window is minimized
         * SDL_WINDOW_MAXIMIZED = window is maximized
         * SDL_WINDOW_INPUT_GRABBED = window has grabbed input focus
         * SDL_WINDOW_ALLOW_HIGHDPI = window should be created in high-DPI mode if supported (>= SDL 2.0.1)
         */


        window = SDL_CreateWindow(title.c_str(), pos_x, pos_y, passed_width, passed_height,
                                  SDL_WINDOW_ALLOW_HIGHDPI);

        if (window == nullptr) {
            throw ErrorHandler("Could not create SDL Window");
        }

        //main renderer in the game

        /*
         *   SDL_Renderer* SDL_CreateRenderer(SDL_Window* window,
         *                                int         index,
         *                               Uint32      flags)
         */

        /*
         *   the index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags
         *   SDL_RENDERER_ACCELERATED the renderer uses hardware acceleration
         */

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) {
            throw ErrorHandler("Could not create SDL Renderer");
        }

        //main event handler in the game
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

        //SDL_RenderClear clears the screen
        //This method works with SDL_RenderPresent
        //both methods used inside the main GameLoop
        SDL_RenderClear(renderer);
    }

    void SdlInitializer::SdlEnd() const
    {
        //SdlBegin and SdlEnd , both called
        //inside GameLoop
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