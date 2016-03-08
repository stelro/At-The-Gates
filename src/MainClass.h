/*
 * src/MainClass.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * MainClass Class, contains the MOST Importan method,
 * GameLoop method, which renders all the states and
 * levels to the screen.
 * Contains also the Statemachine stack , and varius
 * methods to controlls the Statemachine stack!
 *
 */

#ifndef TOK_MAINCLASS_H
#define TOK_MAINCLASS_H

#include <stack>
#include <string>
#include <iostream>
#include <memory>

#include "ErrorHandler.h"
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "Timer.h"
#include "Locamap.h"
#include "MainCharacter.h"
#include "GameMenu.h"


enum {
    STATE_NULL,
    STATE_EXIT,
    STATE_MAIMMENU,
    STATE_LOCALMAP
};

const int FRAMES_PER_SECOND = 200;

namespace tok {

    class MainClass {
    private:
        void UpdateState();
        std::shared_ptr<SdlInitializer> csdl_setup;
        std::shared_ptr<Localmap> localmap;
        std::shared_ptr<GameMenu> gamemenu;

        std::stack<std::shared_ptr<StateMachine>> stateStack;

        Timer fps;

        double CameraX;
        double CameraY;
        int MouseX;
        int MouseY;

        int state;
        bool isPressed;
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
        if (!stateStack.empty()) {
            this->stateStack.pop();
        }
    }

    inline void MainClass::ChangeState(std::shared_ptr<StateMachine> state) {
        if (!this->stateStack.empty())
            this->stateStack.pop();
        PushState(state);
    }

    inline std::shared_ptr<StateMachine> MainClass::TopState() {
        if (this->stateStack.empty())
            return nullptr;
        else
            return this->stateStack.top();
    }
}




#endif //TOK_MAINCLASS_H
