//
// Created by stel on 25/3/2016.
//

#include "CollisionRect.h"

namespace tok {

    CollisionRect::CollisionRect() :
    offsetX(0), offsetY(0)
    {
        SetRectangle(0,0,0,0);
    }

    CollisionRect::CollisionRect(int passedX, int passedY, int passedWidth, int passedHeight) :
    offsetX(passedX), offsetY(passedY)
    {
        SetRectangle(0,0,passedWidth,passedHeight);
    }

    CollisionRect::~CollisionRect() {

    }

    void CollisionRect::SetRectangle(int passedX, int passedY, int passedWidth, int passedHeight) {

        CollisionRectangle.x = passedX + offsetX;
        CollisionRectangle.y = passedY + offsetY;
        CollisionRectangle.w = passedWidth;
        CollisionRectangle.h = passedHeight;
    }

    void CollisionRect::SetX(int x) {
        CollisionRectangle.x = x + offsetX;
    }

    void CollisionRect::SetY(int y) {
        CollisionRectangle.y = y + offsetY;
    }

    const SDL_Rect &CollisionRect::GetRectangle() {
        return CollisionRectangle;
    }

}