//
// Created by stel on 8/3/2016.
//

#ifndef TOK_GAMEMENU_H
#define TOK_GAMEMENU_H

#include <memory>
#include "StateMachine.h"
#include "SdlInitializer.h"
#include "Sprite.h"

enum {
    DEFAULT_BUTTON,
    MOUSEOVER_BUTTON,
    PRESSED_BUTTON
};

enum {
    NEWGAME,
    LOADGAME,
    EXITGAME
};

const int BUTTON_WIDTH = 290;
const int BUTTON_HEIGHT = 56;

namespace tok {

    class GameMenu : public StateMachine {
    private:
        void SetButtons();
        void InitializeButtons();
        std::shared_ptr<SdlInitializer> csdl_setup;
        std::shared_ptr<Sprite> backgroundImage;

        double *CameraX;
        double *CameraY;

        int *MouseX;
        int *MouseY;

        SDL_Rect Buttons[3];
        std::shared_ptr<Sprite> menuButtons[3];

    public:
        GameMenu(std::shared_ptr<SdlInitializer> passed_csdl_setup, double *passedCameraX, double *passedCameraY,int *passedMouseX, int *passedMouseY);
        ~GameMenu();
        void Render();
        void Update();


    };

}


#endif //TOK_GAMEMENU_H
