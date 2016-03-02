//
// Created by stel on 2/3/2016.
//

#ifndef TOK_MAINCLASS_H
#define TOK_MAINCLASS_H

#include <stack>
#include <string>
#include <iostream>

#include "StateMachine.h"
#include "SdlInitializer.h"
#include "Timer.h"

const int FRAMES_PER_SECOND = 26;

enum States {
    EXIT_STATE,
    NULL_STATE,
    MENU_STATE,
    LOCALMAP_STATE,
    GAME_STATE,
    FIGHT_STATE,
    WORLDMAP_STATE
};

namespace tok {

    class MainClass {
    private:
        SdlInitializer *csdl_setup;
        std::stack<StateMachine*> stateStack;
        Timer fps;
    public:
        MainClass(const char *title, int possitionX, int possitionY,
                    int passedWidth, int passedHeight);
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
