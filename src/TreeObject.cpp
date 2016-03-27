/*
 *  src/TreeObject.cpp - helper class to render Trees
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