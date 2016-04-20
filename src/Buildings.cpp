/*
 *  src/Buildings.cpp - helper class to render buildings
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

#include "Buildings.h"

namespace atg {

    Buildings::Buildings(std::shared_ptr<SdlInitializer> passed_csdl_setup, const int passedX,const int passedY, double* const passedCameraX,
                         double *const passedCameraY) :
    csdl_setup(passed_csdl_setup), x(passedX), y(passedY), CameraX(passedCameraX), CameraY(passedCameraY)
    {



        building  = std::make_shared<Sprite>(csdl_setup->GetRenderer(), "assets/buildings/building2.png",x,y,340,314,
                                           CameraX,CameraY,CollisionRect(0,60,340,260));


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
        if (100 >= *CameraX + building->GetPositionRect().y)
            building->Draw();
    }

    std::shared_ptr<Sprite> Buildings::GetObject() const {
        return building;
    }



}