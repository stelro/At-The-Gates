//
// Created by stel on 25/3/2016.
//

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
