/*
 * src/Locamap.cpp
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

#include "Locamap.h"

namespace tok {

    Localmap::Localmap(std::shared_ptr<SdlInitializer> passed_csdl_setup,int screenWidth, int screenHeight, double *passedCameraX, double *passedCameraY,
                       int *passedMouseX, int *passedMouseY) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY), MouseX(passedMouseX), MouseY(passedMouseY)
    {


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {

                backgroundImage[i][j] = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/grass.bmp",
                                                           screenWidth * i,screenHeight * j,
                                                           screenWidth,screenHeight,CameraX,CameraY);
            }
        }

        onPress = false;

        main_char = std::make_shared<MainCharacter>(csdl_setup, MouseX, MouseY, CameraX, CameraY);
    }

    Localmap::~Localmap() {


    }

    void Localmap::Update() {


    }

    void Localmap::Render() {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {
                backgroundImage[i][j]->Draw();
            }
        }

        main_char->Draw();
        main_char->Update();
    }
}