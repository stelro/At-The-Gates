/*
 * src/MainCharacter.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * MainCharacter, controlls the main's character
 * animatinos, mouse/move controllers and collision
 * with 'Localmap' object's!
 * The main character get rendered from Sprite class!
 *
 */

#include "MainCharacter.h"


namespace tok {
    MainCharacter::MainCharacter(std::shared_ptr<SdlInitializer> passed_csdl_setup, int *passedMouseX, int *passedMouseY,
                                 double *passedCameraX, double *passedCameraY,std::vector<std::shared_ptr<EnviromentObjects>> passed_envObjects) :
    csdl_setup(passed_csdl_setup), MouseX(passedMouseX), MouseY(passedMouseY) ,CameraX(passedCameraX), CameraY(passedCameraY),
    follow(false), stopAnimation(false)
    {

        main_char = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/death_scythe_ani.png", 300,250,50,80,
                                CameraX, CameraY,CollisionRect(280,260,35,30));

        //----------------------------------
        //set origin, set the half width and height
        //of the main character
        //----------------------------------

        main_char->SetupAnimation(4,4);
        main_char->SetOrigin(main_char->GetWidth() / 2.0f, main_char->GetHeight() / 2.0f);

        timeCheck = SDL_GetTicks();
        distance = 0;

        enviromentObjects = passed_envObjects;


    }

    MainCharacter::~MainCharacter() {

    }

    void MainCharacter::Draw() {
        main_char->DrawSteady();
    }

    void MainCharacter::UpdateAnimation() {

        //-----------------------------------------------------
        //this code above is about the character animation
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

        //std::cout << angle << std::endl;

        if (!stopAnimation) {
            if (angle > 45 &&  angle <= 135) {
                //down
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,0,SPEED);
                else
                    main_char->PlayAnimation(1,1,0,SPEED);
            }
            else if (angle > 135 && angle <= 225) {
                //left
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,1,SPEED);
                else
                    main_char->PlayAnimation(1,1,1,SPEED);
            }
            else if (angle > 225 && angle <= 315) {
                //up
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,3,SPEED);
                else
                    main_char->PlayAnimation(1,1,3,SPEED);
            }
            else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45)) {
                //right
                if ( distance > 15)
                    main_char->PlayAnimation(0,2,2,SPEED);
                else
                    main_char->PlayAnimation(1,1,2,SPEED);

            }
        }


    }

    void MainCharacter::UpdateControllers() {

        if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN ||
            csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION) {

            if(csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT) {
                xFollowPoint = (int)*CameraX - *MouseX + 300;
                yFollowPoint = (int)*CameraY - *MouseY + 250;
                follow = true;
            }

        }

        if (timeCheck+10 < SDL_GetTicks() && follow) {

            distance = GetDistance((int)*CameraX, (int)*CameraY, xFollowPoint, yFollowPoint);

            if (distance == 0)
                stopAnimation = true;
            else
                stopAnimation = false;

            if (distance > 15 ) {



                bool colliding = false;

                for (auto i : enviromentObjects) {

                    if(main_char->isColliding(i->GetObject()->GetCollisonRect())) {

                        if (*CameraX > xFollowPoint) {
                            *CameraX = *CameraX + 5;
                        }

                        if (*CameraX < xFollowPoint) {
                            *CameraX = *CameraX - 5;
                        }

                        if (*CameraY > yFollowPoint) {
                            *CameraY = *CameraY + 5;
                        }

                        if (*CameraY < yFollowPoint) {
                            *CameraY = *CameraY - 5;
                        }

                        xFollowPoint = (int)*CameraX;
                        yFollowPoint = (int)*CameraY;
                        distance = 0;
                        follow = false;
                        colliding = true;

                    }

                }

                //if player is colliding with any object, dont follow the follow_point

                if (!colliding) {

                    // 0.8f, determinates the speed of the character
                    if (*CameraX != xFollowPoint) {
                        *CameraX = (*CameraX - ((*CameraX - xFollowPoint) / distance) * 0.8f);
                    }

                    if (*CameraY != yFollowPoint) {
                        *CameraY = (*CameraY - ((*CameraY - yFollowPoint) / distance) * 0.8f);
                    }
                }


            }

            else
                follow = false;

            timeCheck = SDL_GetTicks();

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
