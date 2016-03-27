/*
 *  src/CollisonRect.h - Collision Rectangle , helper class
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


#ifndef TOK_COLLISIONRECT_H
#define TOK_COLLISIONRECT_H

#include <SDL2/SDL.h>

namespace tok {

    class CollisionRect {
    private:
        int offsetX;
        int offsetY;
        SDL_Rect CollisionRectangle;
    public:
        CollisionRect();
        CollisionRect(int passedX, int passedY, int passedWidth, int passedHeight);
        ~CollisionRect();
        void SetRectangle(int passedX, int passedY, int passedWidth, int passedHeight);
        const SDL_Rect &GetRectangle();
        void SetX(int x);
        void SetY(int y);
    };
}


#endif //TOK_COLLISIONRECT_H
