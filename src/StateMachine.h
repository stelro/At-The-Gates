//
// Created by stel on 2/3/2016.
//

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
