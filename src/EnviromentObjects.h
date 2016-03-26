//
// Created by stel on 26/3/2016.
//

#ifndef TOK_ENVIROMENTOBJECTS_H
#define TOK_ENVIROMENTOBJECTS_H

#include <memory>
#include "Sprite.h"

namespace tok {

    class EnviromentObjects {
    public:
        virtual int GetX() const = 0;
        virtual int GetY() const = 0;
        virtual void DrawObject() = 0;
        virtual std::shared_ptr<Sprite> GetObject() const = 0;
        virtual ~EnviromentObjects();
    };
}


#endif //TOK_ENVIROMENTOBJECTS_H
