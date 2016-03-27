/*
 *  src/NpcObjects.h - helper class to render NPC's
 *  on the screen.
 *
 *  This file is a part of At-The-Gates SDL2 Game
 *  Copyright (C) 2016  Stelmach Rostislav
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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