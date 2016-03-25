//
// Created by stel on 8/3/2016.
//

#include "GameMenu.h"

namespace tok {

    GameMenu::GameMenu(std::shared_ptr<SdlInitializer> passed_csdl_setup,bool *quit_state,double *passedCameraX, double *passedCameraY,int *passedMouseX, int *passedMouseY) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY), MouseX(passedMouseX), MouseY(passedMouseY)
    {

        SetButtons();
        InitializeButtons();

        backgroundImage = std::make_shared<Sprite>(csdl_setup->GetRenderer(),"assets/wallpaper.png",0,0,1024,768, CameraX, CameraY);

        state = quit_state;
    }

    GameMenu::~GameMenu() {


    }

    void GameMenu::SetButtons() {

        Buttons[ DEFAULT_BUTTON ].x = 0;
        Buttons[ DEFAULT_BUTTON ].y = 112;
        Buttons[ DEFAULT_BUTTON ].w = BUTTON_WIDTH;
        Buttons[ DEFAULT_BUTTON ].h = BUTTON_HEIGHT;

        Buttons[ MOUSEOVER_BUTTON ].x = 0;
        Buttons[ MOUSEOVER_BUTTON ].y = 0;
        Buttons[ MOUSEOVER_BUTTON ].w = BUTTON_WIDTH;
        Buttons[ MOUSEOVER_BUTTON ].h = BUTTON_HEIGHT;

        Buttons[ PRESSED_BUTTON ].x = 0;
        Buttons[ PRESSED_BUTTON ].y = 56;
        Buttons[ PRESSED_BUTTON ].w = BUTTON_WIDTH;
        Buttons[ PRESSED_BUTTON ].h = BUTTON_HEIGHT;

    }

    void GameMenu::InitializeButtons() {
        // to place the buttons right to the center of the screen ( if we assume that the dimensions is 1024 x 768 )
        //we divide 1024/2 and divide the button image width with 2, and substruct the result with 512 ( the half
        //of the width screen , so  (1024/2 = 512, 290/2 = 145 , 512 - 145 = 367 )
        menuButtons[ NEWGAME ] = std::make_shared<Sprite>(csdl_setup->GetRenderer(), NEWGAME, Buttons, "assets/newgame.png",
                                                 367,456,CameraX,CameraY);

        menuButtons[ LOADGAME ]  = std::make_shared<Sprite>(csdl_setup->GetRenderer(), LOADGAME, Buttons, "assets/loadgame.png",
                                                 367,522,CameraX,CameraY);

        menuButtons[ EXITGAME ]  = std::make_shared<Sprite>(csdl_setup->GetRenderer(), EXITGAME, Buttons, "assets/exitgame.png",
                                                 367,588,CameraX,CameraY);
    }

    void GameMenu::Render() {
        backgroundImage->DrawSteady();
        for (auto button : menuButtons) {
            button->DrawSteady();
        }
    }

    void GameMenu::Update() {

        for (auto button : menuButtons) {

            if (csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION ||
                csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN ||
                csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONUP) {

                int x, y;
                SDL_GetMouseState(&x, &y);

                //Check if mouse is in button
                bool inside = true;

                //Mouse is left of the button
                if (x < button->GetRectX()) {
                    inside = false;
                }

                    //Mouse is right of the button
                else if (x > button->GetRectY() + BUTTON_WIDTH) {
                    inside = false;
                }

                    //Mouse above the button
                else if (y < button->GetRectY()) {
                    inside = false;
                }

                    //Mouse below the button
                else if (y > button->GetRectY() + BUTTON_HEIGHT) {
                    inside = false;
                }

                if (!inside) {
                    button->SetSpriteType(DEFAULT_BUTTON);
                }

                    //Mouse is inside the button
                else {


                    switch (csdl_setup->GetMainEvent()->type) {

                        case SDL_MOUSEMOTION:
                            button->SetSpriteType(MOUSEOVER_BUTTON);
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            button->SetSpriteType(PRESSED_BUTTON);
                            if ( button->GetTileType() == EXITGAME)
                                *state = true;
                            break;

                    }
                }

            }
        }

    }

}