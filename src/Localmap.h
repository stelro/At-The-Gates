/*
 *  src/Localmap.h - Localmap game State, this is the one of the main
 *  classes which called after the menu state!
 *  Localmap class renders the main character, and its all needed
 *  enviroment objects ( NPC's, tiles, buildings, etc..).
 *  Inherit from Statemachine abstract class.
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


#ifndef atg_LOCAMAP_H
#define atg_LOCAMAP_H

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
#include "TreeObject.h"
#include "RockObject.h"
#include "WallObjects.h"
#include "NpcObjects.h"




//------------------------------------
//MAP SIZE, 24 x 34 , 816 TILES
const int TILES_ROW = 24;
const int TILES_COL = 34;
//------------------------------------

const int TILE_WIDTH = 40;
const int TILE_HEIGHT = 40;

const int TOTAL_TILES = 28;


namespace atg {

    class Localmap : public StateMachine {
    private:
        void InitializeTiles();
        void SetTiles();

        std::shared_ptr<SdlInitializer> csdl_setup;
        std::unique_ptr<MainCharacter> main_char;

        double *CameraX;
        double *CameraY;
        int *MouseX;
        int *MouseY;

        std::shared_ptr<Sprite> tiles[TILES_ROW][TILES_COL];
        SDL_Rect gTileClips[TOTAL_TILES];

        std::shared_ptr<Buildings> building;
        std::shared_ptr<TreeObject> tree1;
        std::shared_ptr<TreeObject> tree2;
        std::shared_ptr<RockObject> rock1;
        std::shared_ptr<RockObject> rock2;
        std::shared_ptr<WallObjects> downWall;
        std::shared_ptr<WallObjects> rightWall;
        std::shared_ptr<WallObjects> upWall;
        std::shared_ptr<WallObjects> leftWall;
        std::shared_ptr<NpcObjects> npc;

        std::vector<std::shared_ptr<EnviromentObjects>> enviromentObjects;

        bool isPressed;
        bool debMode;

    public:
        Localmap(std::shared_ptr<SdlInitializer> passed_csdl_setup,int screenWidth,int screenHeight, double *passedCameraX,
                double *passedCameraY,int *passedMouseX, int *passedMouseY);
        Localmap(const Localmap &rhs) = delete;
        Localmap &operator =(const Localmap &rhs) = delete;
        ~Localmap();
        void Render();
        void Update();

    };
}

#endif //atg_LOCAMAP_H
