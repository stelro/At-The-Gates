/*
 *  src/WallObjects.cpp - helper class to render Walls
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