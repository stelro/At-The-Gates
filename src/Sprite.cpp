//
// Created by stel on 3/3/2016.
//

#include "Sprite.h"

namespace tok {

    Sprite::Sprite(SDL_Renderer *passed_renderer, const std::string &filePath, int passedX, int passedY,
                   int passedWidth, int passedHeight, double *passedCameraX, double *passedCameraY) :
    renderer(passed_renderer), texture(nullptr)

    {

        texture = IMG_LoadTexture(renderer, filePath.c_str());

        if (texture == nullptr) {
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

        cameraRect.x = t_Rect.x + *CameraX;
        cameraRect.y = t_Rect.y + *CameraY;
        cameraRect.w = t_Rect.w;
        cameraRect.h = t_Rect.h;

    }

    void Sprite::PlayAnimation(int beginFrame, int endFrame, int row, int speed) {

        if (animationDelay + speed < SDL_GetTicks()) {
            currentFrame = beginFrame;
        }
        else {
            currentFrame++;
        }

        cropRect.x = currentFrame * ( textureWidth / frameAmountX);
        cropRect.y = row * ( textureHeight / frameAmountY);
        cropRect.w = textureWidth / frameAmountX;
        cropRect.y = textureHeight / frameAmountY;

        animationDelay = SDL_GetTicks();
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

        cameraRect.x = t_Rect.x + *CameraX;
        cameraRect.y = t_Rect.y + *CameraY;

        SDL_RenderCopy(renderer,texture,&cropRect,&cameraRect);

    }

    void Sprite::DrawSteady() {

        //With this method, main character wont be affected of
        //the camera.

        SDL_RenderCopy(renderer,texture,&cropRect,&t_Rect);
    }

    Sprite::~Sprite() {
        SDL_DestroyTexture(texture);
    }
}