/*
 *  src/ErrorHandler.cpp - Error Handling for SDL2 and
 *  the entire game.
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

#include "ErrorHandler.h"

namespace atg {

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