//
// Created by stel on 27/3/2016.
//

#ifndef TOK_NPCOBJECTS_H
#define TOK_NPCOBJECTS_H

#include <memory>

#include "SdlInitializer.h"
#include "Sprite.h"
#include "EnviromentObjects.h"

namespace tok {

    class NpcObjects : public EnviromentObjects {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;

        int x;
        int y;
        double *CameraX;
        double *CameraY;

        std::shared_ptr<Sprite> npc;

    public:
        NpcObjects(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX, double *passedCameraY,unsigned short rockType);
        ~NpcObjects();
        void DrawObject();
        int GetX() const;
        int GetY() const;
        std::shared_ptr<Sprite> GetObject() const;

    };
}



#endif //TOK_NPCOBJECTS_H
