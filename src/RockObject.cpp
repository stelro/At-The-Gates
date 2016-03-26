//
// Created by stel on 26/3/2016.
//

#include "RockObject.h"

namespace tok {

    RockObject::RockObject(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX,
                           double *passedCameraY, unsigned short rockType) :
        csdl_setup(passed_csdl_setup), x(passedX), y(passedY), CameraX(passedCameraX), CameraY(passedCameraY)
    {

        switch (rockType) {
            //Rock 1 mode
            case 1:
                rock = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/rock1.png", x, y, 40, 31,
                                                CameraX, CameraY, CollisionRect(0, 0, 40, 31));
                break;
            //Rock 2 mode
            case 2:
                rock = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/rock2.png", x, y, 29, 56,
                                                CameraX, CameraY, CollisionRect(0, 0, 29, 56));
                break;
        }


    }

    RockObject::~RockObject() {


    }

    int RockObject::GetX() const {
        return x;
    }

    int RockObject::GetY() const {
        return y;
    }

    void RockObject::DrawObject() {
        //if (100 >= *CameraX + tree->GetPositionRect().y)
        rock->Draw();
    }

    std::shared_ptr<Sprite> RockObject::GetObject() const {
        return rock;
    }

}