/*
 *  src/Sprite.h - used to "generate" all the sprites/graphics needed
 *  in the game.
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

#ifndef TOK_SPRITE_H
#define TOK_SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "CollisionRect.h"

namespace tok {

    class Sprite {
    private:
        SDL_Renderer *renderer;

        double *CameraX;
        double *CameraY;

        SDL_Texture *texture;
        SDL_Texture *collisionTexture;

        SDL_Rect cameraRect;
        SDL_Rect t_Rect;
        SDL_Rect cropRect;

        int textureWidth;
        int textureHeight;
        int currentFrame;
        int animationDelay;

        int frameAmountX;
        int frameAmountY;

        double xPossition;
        double yPossition;
        double xOrigin;
        double yOrigin;

        int _tileType;
        SDL_Rect *_tileClips;

        CollisionRect Collison_Rect;
        bool debugMode;

    public:
        Sprite();
        Sprite(SDL_Renderer *passed_renderer, const std::string filePath,int passedX,
                int passedY, int passedWidth, int passedHeight, double *passedCameraX, double *passedCameraY,CollisionRect passed_CollisonRect);
        Sprite(SDL_Renderer *passed_renderer,int tileType, SDL_Rect *tileClips, const std::string filePath, int passedX, int passedY,
                double *passedCameraX, double *passedCameraY,CollisionRect passed_CollisonRect);
        Sprite(const Sprite &rhs);
        Sprite &operator =(const Sprite &rhs);
        ~Sprite();
        void SetX(double passedX);
        void SetY(double passedY);
        void SetPossition(double passedX,double passedY);
        double GetX() const;
        double GetY() const;
        void SetWidth(int passedWidth);
        void SetHeight(int passedHeight);
        int GetWidth() const;
        int GetHeight() const;
        void SetOrigin(double passedX, double passedY);
        void PlayAnimation(int beginFrame, int endFrame, int row, unsigned speed);
        void cropTile(int row, int col, int tileWidth, int tileHeight);
        void SetupAnimation(int passedX, int passedY);
        void Draw();
        void DrawSteady();
        void SetSpriteType(int type);
        int GetRectX() const;
        int GetRectY() const;
        int GetTileType() const;
        CollisionRect GetCollisonRect() const;
        bool isColliding(CollisionRect collider);
        SDL_Rect GetPositionRect() const;
        void SetDebugMode(bool mode);

    };

}


#endif //TOK_SPRITE_H
