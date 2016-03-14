/*
 * src/Sprite.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Sprite class, used to "generate" all the sprites needed in
 * game (main character,npc's, background, walls, trees, etc..)
 *
 */

#ifndef TOK_SPRITE_H
#define TOK_SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

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
    public:
        Sprite();
        Sprite(SDL_Renderer *passed_renderer, const std::string filePath,int passedX,
                int passedY, int passedWidth, int passedHeight, double *passedCameraX, double *passedCameraY);
        Sprite(SDL_Renderer *passed_renderer,int tileType, SDL_Rect *tileClips, const std::string filePath, int passedX, int passedY,
                double *passedCameraX, double *passedCameraY);
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
        SDL_Rect GetPositionRect();
        void SetSpriteType(int type);
        int GetRectX() const ;
        int GetRectY() const ;

    };

}


#endif //TOK_SPRITE_H
