/*
 *  src/EnviromentObjects.cpp - Enviroment Objects, Abstract Base class
 *  from which all objects ( trees, buildings, etc..) inhert.
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

#ifndef atg_ENVIROMENTOBJECTS_H
#define atg_ENVIROMENTOBJECTS_H

#include <memory>
#include "Sprite.h"

namespace atg {

    class EnviromentObjects {
    public:
        virtual int GetX() const = 0;
        virtual int GetY() const = 0;
        virtual void DrawObject() = 0;
        virtual std::shared_ptr<Sprite> GetObject() const = 0;
        virtual ~EnviromentObjects();
    };
}


#endif //atg_ENVIROMENTOBJECTS_H
