//
// Created by stel on 8/3/2016.
//

#ifndef TOK_GAMEMENU_H
#define TOK_GAMEMENU_H

#include <memory>
#include "StateMachine.h"
#include "SdlInitializer.h"

namespace tok {

    class GameMenu : public StateMachine {
    private:
        std::shared_ptr<SdlInitializer> csdl_setup;
    public:
        GameMenu(std::shared_ptr<SdlInitializer> passed_csdl_setup);
        ~GameMenu();
        void Render();
        void Update();


    };

}


#endif //TOK_GAMEMENU_H
