/*
 * src/MainClass.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * This is the MainClass, contain the GAmeLoop function
 * and also manges the statemachine functions
 *
 */

#ifndef TOK_MAINCLASS_H
#define TOK_MAINCLASS_H

#include <stack>
#include <string>
#include <iostream>

#include "ErrorHandler.h"
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "Timer.h"
#include "Locamap.h"

const int FRAMES_PER_SECOND = 26;

namespace tok {

    class MainClass {
    private:
        SdlInitializer *csdl_setup;
        std::stack<StateMachine*> stateStack;
        Timer fps;

        double CameraX;
        double CameraY;
        int MouseX;
        int MouseY;

        Localmap *localmap;
    public:
        MainClass(const std::string &title, int possitionX, int possitionY,
                    int passedWidth, int passedHeight);
        ~MainClass();
        void ChangeState(StateMachine *stateMachine);
        void PushState(StateMachine *state);
        void PopState();
        void PopStateAndDelete();
        StateMachine *TopState();
        void GameLoop();
    };

    inline void MainClass::PushState(StateMachine *state) {
        this->stateStack.push(state);
    }

    inline void MainClass::PopState() {
        this->stateStack.pop();
    }

    inline void MainClass::PopStateAndDelete() {
        if (!stateStack.empty()) {
            delete this->stateStack.top();
            this->stateStack.pop();
        }
    }

    inline void MainClass::ChangeState(StateMachine *state) {
        if (!this->stateStack.empty())
            this->stateStack.pop();
        PushState(state);
    }

    inline StateMachine * MainClass::TopState() {
        if (this->stateStack.empty())
            return nullptr;
        else
            return this->stateStack.top();
    }
}




#endif //TOK_MAINCLASS_H
