//
// Created by stel on 4/3/2016.
//

#include "MainCharacter.h"

namespace tok {
    MainCharacter::MainCharacter(tok::SdlInitializer *passed_csdl_setup, int *passedMouseX, int *passedMouseY,
                                 double *passedCameraX, double *passedCameraY) :
    PI(3.14159265359), csdl_setup(passed_csdl_setup), MouseX(passedMouseX), MouseY(passedMouseY) ,CameraX(passedCameraX), CameraY(passedCameraY),
    follow(false), stopAnimation(false)
    {
        main_char = new Sprite(csdl_setup->GetRenderer(), "assets/death_scythe_ani.png", 300,250,50,80,
                                CameraX, CameraY);

        //----------------------------------
        //set origin, set the half width and height
        //of the main character
        //----------------------------------

        main_char->SetupAnimation(4,4);
        main_char->SetOrigin(main_char->GetWidth() / 2.0f, main_char->GetHeight() / 2.0f);

        timeCheck = SDL_GetTicks();
        distance = 0;

    }

    MainCharacter::~MainCharacter() {
        delete main_char;
    }

    void MainCharacter::Draw() {
        main_char->DrawSteady();
    }

    void MainCharacter::UpdateAnimation() {

        //-----------------------------------------------------
        //this code above is about the caracter animation
        //the turning the character to the right direction
        //when the mouse direction changes
        //*
        //we get the angle in radiance and convert it to degrees
        //*
        //------------------------------------------------------

        double angle = atan2(yFollowPoint - *CameraY, xFollowPoint - *CameraX);
        angle = angle * (180/PI) + 180;

        //------------------------------------------------------
        //if distance is equals to zero(0) , then stop playing the animation
        //this is set when the character is not running
        //------------------------------------------------------

        std::cout << angle << std::endl;

        if (!stopAnimation) {
            if (angle > 45 &&  angle <= 135) {
                //down
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,0,200);
                else
                    main_char->PlayAnimation(1,1,0,200);
            }
            else if (angle > 135 && angle <= 225) {
                //left
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,1,200);
                else
                    main_char->PlayAnimation(1,1,1,200);
            }
            else if (angle > 225 && angle <= 315) {
                //up
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,3,200);
                else
                    main_char->PlayAnimation(1,1,3,200);
            }
            else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45)) {
                //right
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,2,200);
                else
                    main_char->PlayAnimation(1,1,2,200);

            }
        }


    }

    void MainCharacter::UpdateControllers() {

        if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN ||
            csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION) {

            if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT) {
                xFollowPoint = *CameraX - *MouseX + 300;
                yFollowPoint = *CameraY - *MouseY + 250;
                follow = true;
            }

        }

        if (timeCheck+10 < SDL_GetTicks() && follow) {

            distance = GetDistance(*CameraX, *CameraY, xFollowPoint, yFollowPoint);

            if (distance == 0)
                stopAnimation = true;
            else
                stopAnimation = false;

            if (distance > 15 ) {

                if (*CameraX != xFollowPoint) {
                    *CameraX = (*CameraX - ((*CameraX - xFollowPoint) / distance ) * 1.5f );
                }
                if (*CameraY != yFollowPoint) {
                    *CameraY = (*CameraY - ((*CameraY - yFollowPoint) / distance ) * 1.5f);
                }

                timeCheck = SDL_GetTicks();
            }

        }


    }

    void MainCharacter::Update() {

        //The method UpdateAnimation should be called before
        //the UpdateControllers

        UpdateAnimation();
        UpdateControllers();

    }

    double MainCharacter::GetDistance(int x1, int y1, int x2, int y2) {
        double diffX = x1 - x2;
        double diffY = y1 - y2;
        double distance = sqrt((diffX * diffX) + (diffY * diffY));
        return distance;
    }
}
