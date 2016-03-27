/*
 *  src/GameMenu.h - Main Game Menu class with
 *  game options, inherit from StateMachine class
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

#ifndef atg_GAMEMENU_H
#define atg_GAMEMENU_H

#include <memory>
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "Sprite.h"

enum {
    DEFAULT_BUTTON,
    MOUSEOVER_BUTTON,
    PRESSED_BUTTON
};

enum {
    NEWGAME,
    LOADGAME,
    EXITGAME
};

const int BUTTON_WIDTH = 290;
const int BUTTON_HEIGHT = 56;

namespace atg {

    class GameMenu : public StateMachine {
    private:
        void SetButtons();
        void InitializeButtons();
        std::shared_ptr<SdlInitializer> csdl_setup;
        std::shared_ptr<Sprite> backgroundImage;

        double *CameraX;
        double *CameraY;

        int *MouseX;
        int *MouseY;

        SDL_Rect Buttons[3];
        std::shared_ptr<Sprite> menuButtons[3];
        bool *state;

    public:
        GameMenu(std::shared_ptr<SdlInitializer> passed_csdl_setup,bool *quit_state,double *passedCameraX, double *passedCameraY,int *passedMouseX, int *passedMouseY);
        ~GameMenu();
        void Render();
        void Update();


    };

}


#endif //atg_GAMEMENU_H
