//
// Created by stel on 27/3/2016.
//

#include "NpcObjects.h"

namespace tok {

    NpcObjects::NpcObjects(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX,
                           double *passedCameraY, unsigned short rockType) :
        csdl_setup(passed_csdl_setup), x(passedX), y(passedY), CameraX(passedCameraX), CameraY(passedCameraY)
    {

        switch (rockType) {
            //npc 1 mode
            case 1:
                npc = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/tuxedokamen.png", x,y,50,80,
                                               CameraX, CameraY,CollisionRect(0,0,35,30));
                break;
        }

        npc->SetupAnimation(4,4);
        npc->PlayAnimation(0,2,0,0);


    }

    NpcObjects::~NpcObjects() {


    }

    int NpcObjects::GetX() const {
        return x;
    }

    int NpcObjects::GetY() const {
        return y;
    }

    void NpcObjects::DrawObject() {
        //if (100 >= *CameraX + tree->GetPositionRect().y)
        npc->Draw();
    }

    std::shared_ptr<Sprite> NpcObjects::GetObject() const {
        return npc;
    }

}