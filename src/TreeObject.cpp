//
// Created by stel on 26/3/2016.
//

#include "TreeObject.h"

namespace tok {

    TreeObject::TreeObject(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX,
                         double *passedCameraY) :
        csdl_setup(passed_csdl_setup), x(passedX), y(passedY), CameraX(passedCameraX), CameraY(passedCameraY)
    {

        tree = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/objects/tree1.png",x,y,68,108,
                                             CameraX,CameraY,CollisionRect(0,50,68,50));


    }

    TreeObject::~TreeObject() {


    }

    int TreeObject::GetX() const {
        return x;
    }

    int TreeObject::GetY() const {
        return y;
    }

    void TreeObject::DrawObject() {
        //if (100 >= *CameraX + tree->GetPositionRect().y)
            tree->Draw();
    }

    std::shared_ptr<Sprite> TreeObject::GetObject() const {
        return tree;
    }

}