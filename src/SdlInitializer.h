//
// Created by stel on 2/3/2016.
//

#ifndef TOK_SDLINITIALIZER_H
#define TOK_SDLINITIALIZER_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "ErrorHandler.h"

namespace tok {

    class SdlInitializer {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event *main_event;
    public:
        SdlInitializer();
        SdlInitializer(Uint32 flags,const char *title, const uint32_t pos_x, const uint32_t pos_y,
                       const uint32_t passed_weight, const uint32_t passed_height) throw(ErrorHandler);
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

#endif //TOK_SDLINITIALIZER_H
