/*
 * src/MainCharacter.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * MainCharacter, controlls the main's character
 * animatinos, mouse/move controllers and collision
 * with 'Localmap' object's!
 * The main character get rendered from Sprite class!
 *
 */

#ifndef TOK_MAINCHARACTER_H
#define TOK_MAINCHARACTER_H

#include <cmath>
#include <memory>
#include <vector>

#include "Sprite.h"
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "EnviromentObjects.h"

const double PI = 3.14159265359;
//speed of animation when caracter is running
const int SPEED = 120;

namespace tok {

    class MainCharacter {
    private:
        void UpdateAnimation();
        void UpdateControllers();

        std::shared_ptr<Sprite> main_char;
        std::shared_ptr<SdlInitializer> csdl_setup;

        int *MouseX;
        int *MouseY;

        double *CameraX;
        double *CameraY;

        size_t timeCheck;
        bool follow;

        int xFollowPoint;
        int yFollowPoint;

        double distance;
        bool stopAnimation;

        //We pass all enviroment object form the LocalMap to MainCharacter
        //to detect the collision of player with the objects
        std::vector<std::shared_ptr<EnviromentObjects>> enviromentObjects;

    public:
        MainCharacter(std::shared_ptr<SdlInitializer> passed_csdl_setup, int *passedMouseX, int *passedMouseY,
                    double *passedCameraX, double *passedCameraY, std::vector<std::shared_ptr<EnviromentObjects>> passed_envObjects);
        ~MainCharacter();
        void Update();
        void Draw();
        double GetDistance(int x1, int y1, int x2, int y2);

    };
}


#endif //TOK_MAINCHARACTER_H
