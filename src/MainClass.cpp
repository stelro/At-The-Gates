/*
 * src/MainClass.cpp
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * This is the MainClass, contain the GAmeLoop function
 * and also manges the statemachine functions
 *
 */

#include "MainClass.h"

namespace  tok {

    MainClass::MainClass(const std::string &title, int possitionX, int possitionY, int passedWidth, int passedHeight) {

        try {
            csdl_setup = new SdlInitializer(SDL_INIT_EVERYTHING, title,
                                            possitionX, possitionY, passedWidth, passedHeight);
        }catch(ErrorHandler &e) {
            std::cerr << "Could not initialize SDL: " << e.what();
        }

        CameraX = 0;
        CameraY = 0;
        MouseX = 0;
        MouseY = 0;

        localmap = new Localmap(csdl_setup, passedWidth, passedHeight,&CameraX,&CameraY,&MouseX,&MouseY);

    }

    void MainClass::GameLoop() {

        while (csdl_setup->GetMainEvent()-> type != SDL_QUIT) {

            csdl_setup->SdlBegin();
            SDL_GetMouseState(&MouseX,&MouseY);

            localmap->Render();
            localmap->Update();
//            //-----------------------------------------------------------
//            if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
//                SDL_Delay((1000/FRAMES_PER_SECOND) - fps.get_ticks());
//            //------------------------------------------------------------


            csdl_setup->SdlEnd();
        }
    }

    MainClass::~MainClass() {
        delete localmap;
        delete csdl_setup;
    }
}

