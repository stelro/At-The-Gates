/*
 * src/ErrorHandler.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * This is the Error Handling class for SDL and
 * Template of Katharsis game
 * call What() for show exception error.
 *
 */

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