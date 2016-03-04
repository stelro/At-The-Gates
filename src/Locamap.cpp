//
// Created by stel on 4/3/2016.
//

#include "Locamap.h"

namespace tok {

    Localmap::Localmap(SdlInitializer *passed_csdl_setup,int screenWidth, int screenHeight, double *passedCameraX, double *passedCameraY,
                       int *passedMouseX, int *passedMouseY) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY), MouseX(passedMouseX), MouseY(passedMouseY)
    {


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {

                backgroundImage[i][j] = new Sprite(csdl_setup->GetRenderer(),
                "assets/grass.bmp",screenWidth * i,screenHeight * j,
                screenWidth,screenHeight,CameraX,CameraY);
            }
        }

        onPress = false;

        main_char = new MainCharacter(csdl_setup, MouseX, MouseY, CameraX, CameraY);
    }

    Localmap::~Localmap() {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {
                delete backgroundImage[i][j];
            }
        }

        delete main_char;
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