/*
 *  src/MainClass.h - contains the most importan functionality
 *  GameLoop method, which renders all the states and levels on
 *  the screen.
 *  Contains also the Statemachine stack!
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

#ifndef atg_MAINCLASS_H
#define atg_MAINCLASS_H

#include <string>
#include <iostream>
#include <memory>

#include "ErrorHandler.h"
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "Timer.h"
#include "Localmap.h"
#include "MainCharacter.h"
#include "GameMenu.h"

#include "../lib/dstack.h"


enum {
    STATE_NULL,
    STATE_EXIT,
    STATE_MAIMMENU,
    STATE_LOCALMAP
};

const int FRAMES_PER_SECOND = 200;

namespace atg {

    class MainClass {
    private:
        void UpdateState();
        std::shared_ptr<SdlInitializer> csdl_setup;
        std::shared_ptr<Localmap> localmap;
        std::shared_ptr<GameMenu> gamemenu;

        atg::Stack<std::shared_ptr<StateMachine>> stateStack;

        Timer fps;

        double CameraX;
        double CameraY;
        int MouseX;
        int MouseY;

        int state;
        bool isPressed;
        bool quit_state;
    public:
        MainClass(const std::string &title, int possitionX, int possitionY,
                    int passedWidth, int passedHeight);
        ~MainClass();
        void ChangeState(std::shared_ptr<StateMachine> state);
        void PushState(std::shared_ptr<StateMachine> state);
        void PopState();
        void PopStateAndDelete();
        std::shared_ptr<StateMachine> TopState();
        void GameLoop();
    };

    inline void MainClass::PushState(std::shared_ptr<StateMachine> state) {
        this->stateStack.push(state);
    }

    inline void MainClass::PopState() {
        this->stateStack.pop();
    }

    inline void MainClass::PopStateAndDelete() {
        if (!stateStack.IsEmpty()) {
            this->stateStack.pop();
        }
    }

    inline void MainClass::ChangeState(std::shared_ptr<StateMachine> state) {
        if (!this->stateStack.IsEmpty())
            this->stateStack.pop();
        PushState(state);
    }

    inline std::shared_ptr<StateMachine> MainClass::TopState() {
        if (this->stateStack.IsEmpty())
            return nullptr;
        else
            return this->stateStack.top();
    }
}




#endif //atg_MAINCLASS_H
