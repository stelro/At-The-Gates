/*
 * src/Sprite.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Sprite class, used to "generate" all the sprites needed in
 * game (main character,npc's, background, walls, trees, etc..)
 *
 */
#include "Sprite.h"

namespace tok {

    Sprite::Sprite() :
        renderer(nullptr), texture(nullptr)
    {


        //texture rectangle
        t_Rect.x = 0;
        t_Rect.y = 0;
        t_Rect.w = 0;
        t_Rect.h = 0;

        SDL_QueryTexture(texture,nullptr,nullptr,&textureWidth,&textureHeight);

        cropRect.x = 0;
        cropRect.y = 0;
        cropRect.w = 0;
        cropRect.h = 0;

        xPossition = 0;
        yPossition = 0;

        xOrigin = 0;
        yOrigin = 0;

        currentFrame = 0;

        frameAmountX = 0;
        frameAmountY = 0;

        CameraX = 0;
        CameraY = 0;

        cameraRect.x = t_Rect.x + (int)*CameraX;
        cameraRect.y = t_Rect.y + (int)*CameraY;
        cameraRect.w = t_Rect.w;
        cameraRect.h = t_Rect.h;
    }

    Sprite::Sprite(const Sprite &rhs)
    {

        if ( this != &rhs ) {

            renderer = rhs.renderer;
            texture = rhs.texture;


            //texture rectangle
            t_Rect.x = rhs.t_Rect.x;
            t_Rect.y = rhs.t_Rect.y;
            t_Rect.w = rhs.t_Rect.w;
            t_Rect.h = rhs.t_Rect.h;

            SDL_QueryTexture(texture,nullptr,nullptr,&textureWidth,&textureHeight);

            cropRect.x = rhs.cropRect.x;
            cropRect.y = rhs.cropRect.y;
            cropRect.w = rhs.cropRect.w;
            cropRect.h = rhs.cropRect.h;

            xPossition = rhs.xPossition;
            yPossition = rhs.yPossition;

            xOrigin = rhs.xOrigin;
            yOrigin = rhs.yOrigin;

            currentFrame = rhs.currentFrame;

            frameAmountX = rhs.frameAmountX;
            frameAmountY = rhs.frameAmountY;

            CameraX = rhs.CameraX;
            CameraY = rhs.CameraY;

            cameraRect.x = rhs.cameraRect.x;
            cameraRect.y = rhs.cameraRect.y;
            cameraRect.w = rhs.cameraRect.w;
            cameraRect.h = rhs.cameraRect.h;

        }

    }

    Sprite::Sprite(SDL_Renderer *passed_renderer, const std::string filePath, int passedX, int passedY,
                   int passedWidth, int passedHeight, double *passedCameraX, double *passedCameraY,CollisionRect passed_CollisonRect) :
    renderer(passed_renderer), texture(nullptr)

    {

        Collison_Rect = passed_CollisonRect;
        texture = IMG_LoadTexture(renderer, filePath.c_str());

        if (texture == nullptr) {
            std::cerr << "Couldn't load image, path: " << filePath << std::endl;
        }

        collisionTexture = nullptr;
        collisionTexture = IMG_LoadTexture(renderer, "assets/collision.png");


        if (collisionTexture == nullptr) {
            std::cerr << "Couldn't load image" << std::endl;
        }

        //texture rectangle
        t_Rect.x = passedX;
        t_Rect.y = passedY;
        t_Rect.w = passedWidth;
        t_Rect.h = passedHeight;

        SDL_QueryTexture(texture,nullptr,nullptr,&textureWidth,&textureHeight);

        cropRect.x = 0;
        cropRect.y = 0;
        cropRect.w = textureWidth;
        cropRect.h = textureHeight;

        xPossition = passedX;
        yPossition = passedY;

        xOrigin = 0;
        yOrigin = 0;

        currentFrame = 0;

        frameAmountX = 0;
        frameAmountY = 0;

        CameraX = passedCameraX;
        CameraY = passedCameraY;

        cameraRect.x = t_Rect.x + (int)*CameraX;
        cameraRect.y = t_Rect.y + (int)*CameraY;
        cameraRect.w = t_Rect.w;
        cameraRect.h = t_Rect.h;


    }

    Sprite::Sprite(SDL_Renderer *passed_renderer,int tileType, SDL_Rect *tileClips, const std::string filePath, int passedX, int passedY,
                   double *passedCameraX, double *passedCameraY,CollisionRect passed_CollisonRect) :
        renderer(passed_renderer), _tileType(tileType), _tileClips(tileClips)
    {

        Collison_Rect = passed_CollisonRect;
        texture = nullptr;
        texture = IMG_LoadTexture(renderer, filePath.c_str());

        if (texture == nullptr) {
            std::cerr << "Couldn't load image, path: " << filePath << std::endl;
        }

        collisionTexture = nullptr;
        collisionTexture = IMG_LoadTexture(renderer, "assets/collision.png");


        if (collisionTexture == nullptr) {
            std::cerr << "Couldn't load image" << std::endl;
        }

        t_Rect.x = passedX;
        t_Rect.y = passedY;
        t_Rect.w = _tileClips[_tileType].w;
        t_Rect.h = _tileClips[_tileType].h;

        SDL_QueryTexture(texture,nullptr,nullptr,&textureWidth,&textureHeight);

        cropRect.x = _tileClips[_tileType].x;
        cropRect.y = _tileClips[_tileType].y;
        cropRect.w = _tileClips[_tileType].w;
        cropRect.h = _tileClips[_tileType].h;


        CameraX = passedCameraX;
        CameraY = passedCameraY;

        cameraRect.x = t_Rect.x + (int)*CameraX;
        cameraRect.y = t_Rect.y + (int)*CameraY;
        cameraRect.w = t_Rect.w;
        cameraRect.h = t_Rect.h;


    }

    void Sprite::PlayAnimation(int beginFrame, int endFrame, int row, unsigned speed) {

        if (animationDelay + speed < SDL_GetTicks()) {
            if (endFrame <= currentFrame)
                currentFrame = beginFrame;
            else
                currentFrame++;


            cropRect.x = currentFrame * (textureWidth / frameAmountX);
            cropRect.y = row * (textureHeight / frameAmountY);
            cropRect.w = textureWidth / frameAmountX;
            cropRect.h = textureHeight / frameAmountY;

            animationDelay = SDL_GetTicks();
        }
    }

    void Sprite::cropTile(int row, int col, int tileWidth, int tileHeight) {

            cropRect.x = row;
            cropRect.y = col;
            cropRect.w = tileWidth;
            cropRect.h = tileHeight;

    }


    void Sprite::SetX(double passedX) {
        xPossition = passedX;
        t_Rect.x = int(xPossition - xOrigin);
    }

    void Sprite::SetY(double passedY) {
        yPossition = passedY;
        t_Rect.y = int(yPossition - yOrigin);
    }

    void Sprite::SetPossition(double passedX, double passedY) {
        xPossition = passedX;
        t_Rect.x = int(xPossition - xOrigin);
        yPossition = passedY;
        t_Rect.y = int(yPossition - yOrigin);
    }

    double Sprite::GetX() const {
        return xPossition;
    }

    double Sprite::GetY() const {
        return yPossition;
    }

    int Sprite::GetRectX() const {
        return t_Rect.x;
    }

    int Sprite::GetRectY() const {
        return t_Rect.y;
    }

    void Sprite::SetWidth(int passedWidth) {
        t_Rect.w = passedWidth;
    }

    void Sprite::SetHeight(int passedHeight) {
        t_Rect.h = passedHeight;
    }

    int Sprite::GetWidth() const {
        return t_Rect.w;
    }

    int Sprite::GetHeight() const {
        return t_Rect.h;
    }

    void Sprite::SetOrigin(double passedX, double passedY) {
        xOrigin = passedX;
        yOrigin = passedY;

        SetPossition(GetX(),GetY());
    }

    void Sprite::SetupAnimation(int passedX, int passedY) {
        frameAmountX = passedX;
        frameAmountY = passedY;
    }


    void Sprite::Draw() {

        cameraRect.x = t_Rect.x + (int)*CameraX;
        cameraRect.y = t_Rect.y + (int)*CameraY;

        Collison_Rect.SetX(t_Rect.x + (int)*CameraX);
        Collison_Rect.SetY(t_Rect.y + (int)*CameraY);

        SDL_RenderCopy(renderer,texture,&cropRect,&cameraRect);
        SDL_RenderCopy(renderer,collisionTexture,nullptr,&Collison_Rect.GetRectangle());

    }

    void Sprite::DrawSteady() {

        //With this method, main character wont be affected of
        //the camera.

        SDL_RenderCopy(renderer,collisionTexture,nullptr,&Collison_Rect.GetRectangle());
        SDL_RenderCopy(renderer,texture,&cropRect,&t_Rect);

    }


    Sprite::~Sprite() {
        SDL_DestroyTexture(texture);
    }


    void Sprite::SetSpriteType(int type) {

        t_Rect.w = _tileClips[type].w;
        t_Rect.h = _tileClips[type].h;

        cropRect.x = _tileClips[type].x;
        cropRect.y = _tileClips[type].y;
        cropRect.w = _tileClips[type].w;
        cropRect.h = _tileClips[type].h;
    }

    int Sprite::GetTileType() const {
        return _tileType;
    }

    SDL_Rect Sprite::GetPositionRect() const {
        return t_Rect;
    }

    CollisionRect Sprite::GetCollisonRect() const {
        return Collison_Rect;
    }

    bool Sprite::isColliding(CollisionRect collider) {

        return !(Collison_Rect.GetRectangle().x +
        Collison_Rect.GetRectangle().w < collider.GetRectangle().x ||
        Collison_Rect.GetRectangle().y + Collison_Rect.GetRectangle().h <
        collider.GetRectangle().y || Collison_Rect.GetRectangle().x >
        collider.GetRectangle().x + collider.GetRectangle().w ||
        Collison_Rect.GetRectangle().y > collider.GetRectangle().y +
        collider.GetRectangle().h);
    }

}