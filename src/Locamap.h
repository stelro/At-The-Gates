//
// Created by stel on 4/3/2016.
//

#include <SDL2/SDL.h>
#include <string>
#include "SdlInitializer.h"
#include "Sprite.h"
#include "StateMachine.h"

#ifndef TOK_LOCAMAP_H
#define TOK_LOCAMAP_H

namespace tok {
    class Localmap : public StateMachine {
    private:
        SdlInitializer *csdl_setup;

        bool onPress;
        double *CameraX;
        double *CameraY;

        Sprite *backgroundImage[4][7];
    public:
        Localmap(int screenWidth,int screenHeight, double *passedCameraX,
                double *passedCameraY, SdlInitializer *passed_csdl_setup);
        ~Localmap();
        void Render();
        void Update();


    };
}

#endif //TOK_LOCAMAP_H
