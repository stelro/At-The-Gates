//
// Created by stel on 26/3/2016.
//

#ifndef TOK_ROCKOBJECT_H
#define TOK_ROCKOBJECT_H

#include <memory>

#include "SdlInitializer.h"
#include "Sprite.h"
#include "EnviromentObjects.h"

namespace tok {

    class RockObject : public EnviromentObjects {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;

        int x;
        int y;
        double *CameraX;
        double *CameraY;

        std::shared_ptr<Sprite> rock;

    public:
        RockObject(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX, double *passedCameraY,unsigned short rockType);
        ~RockObject();
        void DrawObject();
        int GetX() const;
        int GetY() const;
        std::shared_ptr<Sprite> GetObject() const;

    };
}

#endif //TOK_ROCKOBJECT_H
