//
// Created by stel on 8/3/2016.
//

#include "GameMenu.h"

namespace tok {

    GameMenu::GameMenu(std::shared_ptr<SdlInitializer> passed_csdl_setup,double *passedCameraX, double *passedCameraY) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY)
    {

        SetButtons();
        InitializeButtons();


    }

    GameMenu::~GameMenu() {


    }

    void GameMenu::SetButtons() {

        Buttons[ DEFAULT_BUTTON ].x = 0;
        Buttons[ DEFAULT_BUTTON ].y = 140;
        Buttons[ DEFAULT_BUTTON ].w = 290;
        Buttons[ DEFAULT_BUTTON ].h = 70;

        Buttons[ MOUSEOVER_BUTTON ].x = 0;
        Buttons[ MOUSEOVER_BUTTON ].y = 0;
        Buttons[ MOUSEOVER_BUTTON ].w = 290;
        Buttons[ MOUSEOVER_BUTTON ].h = 70;

        Buttons[ PRESSED_BUTTON ].x = 0;
        Buttons[ PRESSED_BUTTON ].y = 70;
        Buttons[ PRESSED_BUTTON ].w = 290;
        Buttons[ PRESSED_BUTTON ].h = 70;

    }

    void GameMenu::InitializeButtons() {
        // to place the buttons right to the center of the screen ( if we assume that the dimensions is 1024 x 768 )
        //we divide 1024/2 and divide the button image width with 2, and substruct the result with 512 ( the half
        //of the width screen , so  (1024/2 = 512, 290/2 = 145 , 512 - 145 = 367 )
        newGameButton = std::make_shared<Sprite>(csdl_setup->GetRenderer(), 0, Buttons, "assets/newgame.png",
                                                 367,300,CameraX,CameraY);

        loadGameButton = std::make_shared<Sprite>(csdl_setup->GetRenderer(), 0, Buttons, "assets/loadgame.png",
                                                 367,370,CameraX,CameraY);

        exitGameButton = std::make_shared<Sprite>(csdl_setup->GetRenderer(), 0, Buttons, "assets/exitgame.png",
                                                 367,440,CameraX,CameraY);
    }

    void GameMenu::Render() {
        newGameButton->DrawSteady();
        loadGameButton->DrawSteady();
        exitGameButton->DrawSteady();
    }

    void GameMenu::Update() {


    }

}