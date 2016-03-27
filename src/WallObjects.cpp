//
// Created by stel on 26/3/2016.
//

#include "WallObjects.h"

namespace tok {

    WallObjects::WallObjects(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX,
                           double *passedCameraY, unsigned short rockType) :
        csdl_setup(passed_csdl_setup), x(passedX), y(passedY), CameraX(passedCameraX), CameraY(passedCameraY)
    {

        switch (rockType) {
            //down wall 1 mode
            case 1:
                wall = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/downwall.png", x, y, 1360, 36,
                                                CameraX, CameraY, CollisionRect(0, 0, 1360, 36));
                break;
                //right wall 2 mode
            case 2:
                wall = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/rightwall.png", x, y, 45, 1000,
                                                CameraX, CameraY, CollisionRect(0, 0, 45, 1000));
                break;
                //up wall
            case 3:
                wall = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/upwall.png", x, y, 1280, 97,
                                                CameraX, CameraY, CollisionRect(0, 0, 1280, 97));
                break;
                //left wall
            case 4:
                wall = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/leftwall.png", x, y, 45, 1000,
                                                CameraX, CameraY, CollisionRect(0, 0, 45, 1000));
                break;

        }


    }

    WallObjects::~WallObjects() {


    }

    int WallObjects::GetX() const {
        return x;
    }

    int WallObjects::GetY() const {
        return y;
    }

    void WallObjects::DrawObject() {
        //if (100 >= *CameraX + tree->GetPositionRect().y)
        wall->Draw();
    }

    std::shared_ptr<Sprite> WallObjects::GetObject() const {
        return wall;
    }

}