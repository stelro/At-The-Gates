//
// Created by stel on 2/3/2016.
//

#ifndef TOK_STATEINTERFACE_H
#define TOK_STATEINTERFACE_H


class StateInterface {
public:
    virtual void Render() = 0;
    virtual ~StateInterface();
};


#endif //TOK_STATEINTERFACE_H
