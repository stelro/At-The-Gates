//
// Created by stel on 25/3/2016.
//

#ifndef TOK_BUILDINGS_H
#define TOK_BUILDINGS_H

#include <memory>

#include "SdlInitializer.h"
#include "Sprite.h"
#include "EnviromentObjects.h"

namespace  tok {

    class Buildings : public EnviromentObjects {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;

        int x;
        int y;
        double *CameraX;
        double *CameraY;

        std::shared_ptr<Sprite> building1;

    public:
        Buildings(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX, double *passedCameraY);
        ~Buildings();
        void DrawObject();
        int GetX() const;
        int GetY() const;
        std::shared_ptr<Sprite> GetObject() const;
    };
}

#endif //TOK_BUILDINGS_H
