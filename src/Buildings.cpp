//
// Created by stel on 25/3/2016.
//

#include "Buildings.h"

namespace tok {

    Buildings::Buildings(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX,
                         double *passedCameraY) :
    csdl_setup(passed_csdl_setup), x(passedX), y(passedY), CameraX(passedCameraX), CameraY(passedCameraY)
    {

        building1 = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/buildings/building1.png",x,y,340,314,
                                             CameraX,CameraY,CollisionRect(0,0,340,314));


    }

    Buildings::~Buildings() {


    }

    int Buildings::GetX() const {
        return x;
    }

    int Buildings::GetY() const {
        return y;
    }

    void Buildings::DrawObject() {
        if (100 >= *CameraX + building1->GetPositionRect().y)
            building1->Draw();
    }

    std::shared_ptr<Sprite> Buildings::GetObject() const {
        return building1;
    }



}