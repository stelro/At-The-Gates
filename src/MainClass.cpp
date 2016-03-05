/*
 * src/MainClass.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * MainClass Class, contains the MOST Importan method,
 * GameLoop method, which renders all the states and
 * levels to the screen.
 * Contains also the Statemachine stack , and varius
 * methods to controlls the Statemachine stack!
 *
 */

#include "MainClass.h"

namespace  tok {

    MainClass::MainClass(const std::string &title, int possitionX, int possitionY, int passedWidth, int passedHeight) :
    CameraX(0), CameraY(0), MouseX(0), MouseY(0)
    {

        try {
            csdl_setup = std::make_shared<SdlInitializer>(SDL_INIT_EVERYTHING, title,
                                            possitionX, possitionY, passedWidth, passedHeight);
        }catch(ErrorHandler &e) {
            std::cerr << "Could not initialize SDL: " << e.what();
        }

        localmap = std::make_shared<Localmap>(csdl_setup, passedWidth, passedHeight,&CameraX,&CameraY,&MouseX,&MouseY);
    }

    void MainClass::GameLoop() {

        while (csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

            csdl_setup->SdlBegin();
            SDL_GetMouseState(&MouseX,&MouseY);

            localmap->Render();
            localmap->Update();

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

