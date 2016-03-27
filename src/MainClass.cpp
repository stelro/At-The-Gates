/*
 *  src/MainClass.cpp - contains the most importan functionality
 *  GameLoop method, which renders all the states and levels on
 *  the screen.
 *  Contains also the Statemachine stack!
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

#include "MainClass.h"

namespace  tok {

    MainClass::MainClass(const std::string &title, int possitionX, int possitionY, int passedWidth, int passedHeight) :
    CameraX(0), CameraY(0), MouseX(0), MouseY(0)
    {

        isPressed = false;


        try {
            csdl_setup = std::make_shared<SdlInitializer>(SDL_INIT_EVERYTHING, title,
                                            possitionX, possitionY, passedWidth, passedHeight);
        }catch(ErrorHandler &e) {
            std::cerr << "Could not initialize SDL: " << e.what();
        }

        localmap = std::make_shared<Localmap>(csdl_setup,passedWidth,passedHeight,&CameraX,&CameraY,&MouseX,&MouseY);
        gamemenu = std::make_shared<GameMenu>(csdl_setup,&quit_state,&CameraX, &CameraY,&MouseX,&MouseY);

        stateStack.push(localmap);
    }

    void MainClass::UpdateState() {

        if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN) {
            if (!isPressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_ESCAPE) {
                isPressed = true;
                std::cout << "is pressed" << std::endl;
                PushState(gamemenu);
            }
        }

         if (csdl_setup->GetMainEvent()->type == SDL_KEYUP) {
            if (isPressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_ESCAPE) {
                isPressed = false;
            }
        }

        if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN) {
            if (!isPressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_1) {
                isPressed = true;
                std::cout << " 1 is pressed" << std::endl;
                PopState();
            }
        }

        if (csdl_setup->GetMainEvent()->type == SDL_KEYUP) {
            if (isPressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_1) {
                isPressed = false;
            }
        }


    }

    void MainClass::GameLoop() {

        while ((csdl_setup->GetMainEvent()-> type != SDL_QUIT) && (!quit_state)) {

            csdl_setup->SdlBegin();
            SDL_GetMouseState(&MouseX,&MouseY);

            TopState()->Render();
            TopState()->Update();
            this->UpdateState();

            //-----------------------------------------------------------
            if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
                SDL_Delay((1000/FRAMES_PER_SECOND) - fps.get_ticks());
            //------------------------------------------------------------


            csdl_setup->SdlEnd();
        }
    }

    MainClass::~MainClass() {

    }
}

