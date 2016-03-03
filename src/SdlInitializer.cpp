/*
 * src/SdlInitializer.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Initialize SDL2 with the passed flags,
 * creates and initialize main window, renderer and main_event handler!
 *
 */


#include "SdlInitializer.h"
#include "ErrorHandler.h"

namespace tok {

    SdlInitializer::SdlInitializer(Uint32 flags, const std::string &title, const uint32_t pos_x,
                                   const uint32_t pos_y, const uint32_t passed_weight, const uint32_t passed_height) throw (ErrorHandler) :
        window(nullptr), renderer(nullptr)
    {

        if (SDL_Init(flags) != 0)
            throw ErrorHandler();

        window = SDL_CreateWindow(title.c_str(), pos_x, pos_y, passed_weight, passed_height,
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