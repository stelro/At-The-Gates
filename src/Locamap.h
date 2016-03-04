//
// Created by stel on 4/3/2016.
//

#include <SDL2/SDL.h>
#include <string>
#include "SdlInitializer.h"
#include "Sprite.h"
#include "StateMachine.h"
#include "MainCharacter.h"


#ifndef TOK_LOCAMAP_H
#define TOK_LOCAMAP_H

namespace tok {
    class Localmap : public StateMachine {
    private:
        SdlInitializer *csdl_setup;

        bool onPress;
        double *CameraX;
        double *CameraY;
        int *MouseX;
        int *MouseY;
        Sprite *backgroundImage[4][7];

        MainCharacter *main_char;
    public:
        Localmap(SdlInitializer *passed_csdl_setup,int screenWidth,int screenHeight, double *passedCameraX,
                double *passedCameraY,int *passedMouseX, int *passedMouseY);
        ~Localmap();
        void Render();
        void Update();


    };
}

#endif //TOK_LOCAMAP_H
