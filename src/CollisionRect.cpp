/*
 *  src/CollisonRect.cpp - Collision Rectangle , helper class
 *  to detect collision between different objects on the screen.
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


#include "CollisionRect.h"

namespace atg {

    CollisionRect::CollisionRect() :
    offsetX(0), offsetY(0)
    {
        SetRectangle(0,0,0,0);
    }

    CollisionRect::CollisionRect(const int passedX, const int passedY, const int passedWidth, const int passedHeight) :
    offsetX(passedX), offsetY(passedY)
    {
        SetRectangle(0,0,passedWidth,passedHeight);
    }

    CollisionRect::~CollisionRect() {

    }

    void CollisionRect::SetRectangle(const int passedX, const int passedY, const int passedWidth, const int passedHeight) {

        CollisionRectangle.x = passedX + offsetX;
        CollisionRectangle.y = passedY + offsetY;
        CollisionRectangle.w = passedWidth;
        CollisionRectangle.h = passedHeight;
    }

    void CollisionRect::SetX(const int x) {
        CollisionRectangle.x = x + offsetX;
    }

    void CollisionRect::SetY(const int y) {
        CollisionRectangle.y = y + offsetY;
    }

    const SDL_Rect &CollisionRect::GetRectangle() {
        return CollisionRectangle;
    }

}