/*
 * src/StateMachine.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * StateMachine, Abstract Class
 * used to hold all the various modes of game,
 * and allow us to move from one mode to another,
 * and updates / renders whatever the current mode is.
 *
 */

#ifndef TOK_STATEMACHINE_H
#define TOK_STATEMACHINE_H

#include <iostream>
#include <string>
#include <stack>


namespace tok {

    class StateMachine {
    public:
        virtual void Render() = 0;
        virtual void Update() = 0;
        virtual ~StateMachine();
    };
}

#endif //TOK_STATEMACHINE_H
