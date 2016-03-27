/*
 *  src/ErrorHandler.h - Error Handling for SDL2 and
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

#ifndef atg_ERRORHANDLER_H
#define atg_ERRORHANDLER_H

#include <exception>
#include <iostream>
#include <SDL2/SDL.h>

namespace atg {

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

#endif //atg_ERRORHANDLER_H
