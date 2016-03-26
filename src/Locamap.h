/*
 * src/Locamap.h
 *
 * Copyright (c) 2016 Stelmach Rostislav
 *
 * Localmap game STATE, this is the one of the main classes
 * which called after the menu STATE!
 * Localmap class renders the main character, all the needed
 * NPC's, background image and anything it need's in the
 * character's enviroment!
 * Inherits from Statemachine abstract class, thus Render() and Update()
 * must be implemented!
 * */


#ifndef TOK_LOCAMAP_H
#define TOK_LOCAMAP_H

#include <SDL2/SDL.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>


#include "SdlInitializer.h"
#include "Sprite.h"
#include "StateMachine.h"
#include "MainCharacter.h"
#include "EnviromentObjects.h"
#include "Buildings.h"

//const int TILE_ASSET_WIDTH = 160;
//const int TILE_ASSET_HEIGHT = 240;


//------------------------------------
//MAP SIZE, 24 x 34 , 816 TILES
const int TILES_ROW = 24;
const int TILES_COL = 34;
//------------------------------------

const int TILE_WIDTH = 40;
const int TILE_HEIGHT = 40;

const int TOTAL_TILES = 27;


namespace tok {
    class Localmap : public StateMachine {
    private:
        void InitializeTiles();
        void SetTiles();
        std::shared_ptr<SdlInitializer> csdl_setup;
        std::shared_ptr<MainCharacter> main_char;

        bool onPress;

        double *CameraX;
        double *CameraY;
        int *MouseX;
        int *MouseY;

        std::shared_ptr<Sprite> tiles[TILES_ROW][TILES_COL];
        SDL_Rect gTileClips[TOTAL_TILES];

        std::shared_ptr<Buildings> building;

        std::vector<std::shared_ptr<EnviromentObjects>> enviromentObjects;

    public:
        Localmap(std::shared_ptr<SdlInitializer> passed_csdl_setup,int screenWidth,int screenHeight, double *passedCameraX,
                double *passedCameraY,int *passedMouseX, int *passedMouseY);
        ~Localmap();
        void Render();
        void Update();



    };
}

#endif //TOK_LOCAMAP_H
