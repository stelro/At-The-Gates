/*
 *  src/TreeObject.h - helper class to render Trees
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

#ifndef atg_TREEOBJECT_H
#define atg_TREEOBJECT_H

#include <memory>

#include "SdlInitializer.h"
#include "Sprite.h"
#include "EnviromentObjects.h"

namespace atg {

    class TreeObject : public EnviromentObjects {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;

        int x;
        int y;
        double *CameraX;
        double *CameraY;

        std::shared_ptr<Sprite> tree;

    public:
        TreeObject(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX, double *passedCameraY);
        ~TreeObject();
        void DrawObject();
        int GetX() const;
        int GetY() const;
        std::shared_ptr<Sprite> GetObject() const;

    };
}


#endif //atg_TREEOBJECT_H
