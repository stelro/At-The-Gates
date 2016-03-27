/*
 *  src/RockObjects.cpp - helper class to render rocks/stones
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

#include "RockObject.h"

namespace atg {

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