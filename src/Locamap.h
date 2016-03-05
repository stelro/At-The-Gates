/*
 * src/Locamap.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Localmap game STATE, this is the one of the main classes
 * which called after the menu STATE!
 * Localmap class renders the main character, all the needed
 * NPC's, background image and anything it need's in the
 * character's enviroment!
 * Inherits from Statemachine abstract class, thus Render() and Update()
 * must be implemented!
 *
 */

#include <SDL2/SDL.h>
#include <string>
#include <memory>

#include "SdlInitializer.h"
#include "Sprite.h"
#include "StateMachine.h"
#include "MainCharacter.h"


#ifndef TOK_LOCAMAP_H
#define TOK_LOCAMAP_H

namespace tok {
    class Localmap : public StateMachine {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;
        std::shared_ptr<Sprite> backgroundImage[4][7];
        std::shared_ptr<MainCharacter> main_char;

        bool onPress;
        double *CameraX;
        double *CameraY;
        int *MouseX;
        int *MouseY;

    public:
        Localmap(std::shared_ptr<SdlInitializer> passed_csdl_setup,int screenWidth,int screenHeight, double *passedCameraX,
                double *passedCameraY,int *passedMouseX, int *passedMouseY);
        ~Localmap();
        void Render();
        void Update();


    };
}

#endif //TOK_LOCAMAP_H
