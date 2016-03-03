//
// Created by stel on 4/3/2016.
//

#include "Locamap.h"

namespace tok {

    Localmap::Localmap(int screenWidth, int screenHeight, double *passedCameraX, double *passedCameraY,
                       SdlInitializer *passed_csdl_setup) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY)
    {


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {

                backgroundImage[i][j] = new Sprite(csdl_setup->GetRenderer(),
                "assets/grass.bmp",screenWidth * i,screenHeight * j,
                screenWidth,screenHeight,CameraX,CameraY);
            }
        }

        onPress = false;
    }

    Localmap::~Localmap() {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 7; j++) {
                delete backgroundImage[i][j];
            }
        }
    }

    void Localmap::Update() {


    }

    void Localmap::Render() {
        
    }
}