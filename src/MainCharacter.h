//
// Created by stel on 4/3/2016.
//

#ifndef TOK_MAINCHARACTER_H
#define TOK_MAINCHARACTER_H

#include <cmath>

#include "Sprite.h"
#include "StateMachine.h"
#include "SdlInitializer.h"

namespace tok {

    class MainCharacter {
    public:
        void UpdateAnimation();
        void UpdateControllers();

    private:
        Sprite *main_char;
        SdlInitializer *csdl_setup;

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

        const double PI;
    public:
        MainCharacter(SdlInitializer *passed_csdl_setup, int *passedMouseX, int *passedMouseY,
                    double *passedCameraX, double *passedCameraY);
        ~MainCharacter();
        void Update();
        void Draw();
        double GetDistance(int x1, int y1, int x2, int y2);

    };
}


#endif //TOK_MAINCHARACTER_H
