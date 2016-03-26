//
// Created by stel on 26/3/2016.
//

#ifndef TOK_TREEOBJECT_H
#define TOK_TREEOBJECT_H

#include <memory>

#include "SdlInitializer.h"
#include "Sprite.h"
#include "EnviromentObjects.h"

namespace tok {

    class TreeObject : public EnviromentObjects {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;

        int x;
        int y;
        double *CameraX;
        double *CameraY;

        std::shared_ptr<Sprite> tree;

    public:
        TreeObject(std::shared_ptr<SdlInitializer> passed_csdl_setup, int passedX, int passedY, double *passedCameraX, double *passedCameraY);
        ~TreeObject();
        void DrawObject();
        int GetX() const;
        int GetY() const;
        std::shared_ptr<Sprite> GetObject() const;

    };
}


#endif //TOK_TREEOBJECT_H
