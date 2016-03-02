//
// Created by stel on 2/3/2016.
//

#ifndef TOK_ERRORHANDLER_H
#define TOK_ERRORHANDLER_H

#include <exception>
#include <iostream>
#include <SDL2/SDL.h>

namespace tok {

    class ErrorHandler : public std::exception {
    private:
        std::string error_message;
    public:
        ErrorHandler();
        ErrorHandler(const std::string&);
    public:
        virtual ~ErrorHandler() throw();
        virtual void What() const throw();
    };
}

#endif //TOK_ERRORHANDLER_H
