/*
 *  src/MainCharacter.h - Controlls the main's character
 *  animations (crop image), mouse/move controllers and collision
 *  detection with enviroment objects.
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

#ifndef atg_MAINCHARACTER_H
#define atg_MAINCHARACTER_H

#include <cmath>
#include <memory>
#include <vector>

#include "Sprite.h"
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "EnviromentObjects.h"

const double PI = 3.14159265359;
//speed of animation when caracter is running
const int SPEED = 120;

namespace atg {

    class MainCharacter {
    private:
        void UpdateAnimation();
        void UpdateControllers();

        std::shared_ptr<Sprite> main_char;

        std::shared_ptr<SdlInitializer> csdl_setup;

        int *MouseX;
        int *MouseY;

        double *CameraX;
        double *CameraY;

        size_t timeCheck;
        bool follow;

        int xFollowPoint;
        int yFollowPoint;

        double distance;
        bool stopAnimation;

        //We pass all enviroment object form the LocalMap to MainCharacter
        //to detect the collision of player with the objects
        std::vector<std::shared_ptr<EnviromentObjects>> enviromentObjects;

    public:
        MainCharacter(std::shared_ptr<SdlInitializer> passed_csdl_setup, int *passedMouseX, int *passedMouseY,
                    double *passedCameraX, double *passedCameraY, std::vector<std::shared_ptr<EnviromentObjects>> passed_envObjects);
        ~MainCharacter();
        void Update();
        void Draw();
        double GetDistance(int x1, int y1, int x2, int y2);

    };
}


#endif //atg_MAINCHARACTER_H
