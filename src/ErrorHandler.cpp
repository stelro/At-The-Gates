//
// Created by stel on 2/3/2016.
//

#include "ErrorHandler.h"

namespace tok {

    ErrorHandler::ErrorHandler() :
        exception(), error_message(SDL_GetError()) { }

    ErrorHandler::ErrorHandler(const std::string &error) :
        exception(), error_message(error) { }

    ErrorHandler::~ErrorHandler() throw() { }

    void ErrorHandler::What() const throw()
    {
        std::cout << "Sdl throw an Error: " << error_message << "\n";
    }

}