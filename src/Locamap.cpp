/*
 *  src/Localmap.cpp - Localmap game State, this is the one of the main
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

#include "Locamap.h"

namespace tok {

    Localmap::Localmap(std::shared_ptr<SdlInitializer> passed_csdl_setup,int screenWidth, int screenHeight, double *passedCameraX, double *passedCameraY,
                       int *passedMouseX, int *passedMouseY) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY), MouseX(passedMouseX), MouseY(passedMouseY)
    {

        InitializeTiles();

        onPress = false;

        building = std::make_shared<Buildings>(csdl_setup,512,80,CameraX,CameraY);
        tree1 = std::make_shared<TreeObject>(csdl_setup,450,280,CameraX,CameraY);
        tree2 = std::make_shared<TreeObject>(csdl_setup,850,280,CameraX,CameraY);
        rock1 = std::make_shared<RockObject>(csdl_setup,200,300,CameraX,CameraY,1);
        rock2 = std::make_shared<RockObject>(csdl_setup,150,320,CameraX,CameraY,2);
        downWall = std::make_shared<WallObjects>(csdl_setup,0,960,CameraX,CameraY,1);
        rightWall = std::make_shared<WallObjects>(csdl_setup,0,0,CameraX,CameraY,2);
        upWall = std::make_shared<WallObjects>(csdl_setup,40,-10,CameraX,CameraY,3);
        leftWall = std::make_shared<WallObjects>(csdl_setup,1315,0,CameraX,CameraY,4);
        npc = std::make_shared<NpcObjects>(csdl_setup,560,350,CameraX,CameraY,1);

        enviromentObjects.push_back(building);
        enviromentObjects.push_back(tree1);
        enviromentObjects.push_back(tree2);
        enviromentObjects.push_back(rock1);
        enviromentObjects.push_back(rock2);
        enviromentObjects.push_back(downWall);
        enviromentObjects.push_back(rightWall);
        enviromentObjects.push_back(upWall);
        enviromentObjects.push_back(leftWall);
        enviromentObjects.push_back(npc);

        main_char = std::make_shared<MainCharacter>(csdl_setup, MouseX, MouseY, CameraX, CameraY,enviromentObjects);

        isPressed = false;
        debMode = false;

        SetTiles();

    }

    Localmap::~Localmap() {


    }

    void Localmap::InitializeTiles() {

        gTileClips[ 0 ].x = 0;
        gTileClips[ 0 ].y = 0;
        gTileClips[ 0 ].w = TILE_WIDTH;
        gTileClips[ 0 ].h = TILE_HEIGHT;

        gTileClips[ 1 ].x = 40;
        gTileClips[ 1 ].y = 0;
        gTileClips[ 1 ].w = TILE_WIDTH;
        gTileClips[ 1 ].h = TILE_HEIGHT;

        gTileClips[ 2 ].x = 80;
        gTileClips[ 2 ].y = 0;
        gTileClips[ 2 ].w = TILE_WIDTH;
        gTileClips[ 2 ].h = TILE_HEIGHT;

        gTileClips[ 3 ].x = 120;
        gTileClips[ 3 ].y = 0;
        gTileClips[ 3 ].w = TILE_WIDTH;
        gTileClips[ 3 ].h = TILE_HEIGHT;

        gTileClips[ 4 ].x = 160;
        gTileClips[ 4 ].y = 0;
        gTileClips[ 4 ].w = TILE_WIDTH;
        gTileClips[ 4 ].h = TILE_HEIGHT;

        gTileClips[ 5 ].x = 0;
        gTileClips[ 5 ].y = 40;
        gTileClips[ 5 ].w = TILE_WIDTH;
        gTileClips[ 5 ].h = TILE_HEIGHT;

        gTileClips[ 6 ].x = 40;
        gTileClips[ 6 ].y = 40;
        gTileClips[ 6 ].w = TILE_WIDTH;
        gTileClips[ 6 ].h = TILE_HEIGHT;

        gTileClips[ 7 ].x = 80;
        gTileClips[ 7 ].y = 40;
        gTileClips[ 7 ].w = TILE_WIDTH;
        gTileClips[ 7 ].h = TILE_HEIGHT;

        gTileClips[ 8 ].x = 120;
        gTileClips[ 8 ].y = 40;
        gTileClips[ 8 ].w = TILE_WIDTH;
        gTileClips[ 8 ].h = TILE_HEIGHT;

        gTileClips[ 9 ].x = 160;
        gTileClips[ 9 ].y = 40;
        gTileClips[ 9 ].w = TILE_WIDTH;
        gTileClips[ 9 ].h = TILE_HEIGHT;

        gTileClips[ 10 ].x = 0;
        gTileClips[ 10 ].y = 80;
        gTileClips[ 10 ].w = TILE_WIDTH;
        gTileClips[ 10 ].h = TILE_HEIGHT;

        gTileClips[ 11 ].x = 40;
        gTileClips[ 11 ].y = 80;
        gTileClips[ 11 ].w = TILE_WIDTH;
        gTileClips[ 11 ].h = TILE_HEIGHT;

        gTileClips[ 12 ].x = 80;
        gTileClips[ 12 ].y = 80;
        gTileClips[ 12 ].w = TILE_WIDTH;
        gTileClips[ 12 ].h = TILE_HEIGHT;

        gTileClips[ 13 ].x = 120;
        gTileClips[ 13 ].y = 80;
        gTileClips[ 13 ].w = TILE_WIDTH;
        gTileClips[ 13 ].h = TILE_HEIGHT;

        gTileClips[ 14 ].x = 160;
        gTileClips[ 14 ].y = 80;
        gTileClips[ 14 ].w = TILE_WIDTH;
        gTileClips[ 14 ].h = TILE_HEIGHT;

        gTileClips[ 15 ].x = 0;
        gTileClips[ 15 ].y = 120;
        gTileClips[ 15 ].w = TILE_WIDTH;
        gTileClips[ 15 ].h = TILE_HEIGHT;

        gTileClips[ 16 ].x = 40;
        gTileClips[ 16 ].y = 120;
        gTileClips[ 16 ].w = TILE_WIDTH;
        gTileClips[ 16 ].h = TILE_HEIGHT;

        gTileClips[ 17 ].x = 80;
        gTileClips[ 17 ].y = 120;
        gTileClips[ 17 ].w = TILE_WIDTH;
        gTileClips[ 17 ].h = TILE_HEIGHT;

        gTileClips[ 18 ].x = 0;
        gTileClips[ 18 ].y = 160;
        gTileClips[ 18 ].w = TILE_WIDTH;
        gTileClips[ 18 ].h = TILE_HEIGHT;

        gTileClips[ 19 ].x = 40;
        gTileClips[ 19 ].y = 160;
        gTileClips[ 19 ].w = TILE_WIDTH;
        gTileClips[ 19 ].h = TILE_HEIGHT;

        gTileClips[ 20 ].x = 80;
        gTileClips[ 20 ].y = 160;
        gTileClips[ 20 ].w = TILE_WIDTH;
        gTileClips[ 20 ].h = TILE_HEIGHT;

        gTileClips[ 21 ].x = 0;
        gTileClips[ 21 ].y = 200;
        gTileClips[ 21 ].w = TILE_WIDTH;
        gTileClips[ 21 ].h = TILE_HEIGHT;

        gTileClips[ 22 ].x = 40;
        gTileClips[ 22 ].y = 200;
        gTileClips[ 22 ].w = TILE_WIDTH;
        gTileClips[ 22 ].h = TILE_HEIGHT;

        gTileClips[ 23 ].x = 80;
        gTileClips[ 23 ].y = 200;
        gTileClips[ 23 ].w = TILE_WIDTH;
        gTileClips[ 23 ].h = TILE_HEIGHT;

        gTileClips[ 24 ].x = 0;
        gTileClips[ 24 ].y = 240;
        gTileClips[ 24 ].w = TILE_WIDTH;
        gTileClips[ 24 ].h = TILE_HEIGHT;

        gTileClips[ 25 ].x = 40;
        gTileClips[ 25 ].y = 240;
        gTileClips[ 25 ].w = TILE_WIDTH;
        gTileClips[ 25 ].h = TILE_HEIGHT;

        gTileClips[ 26 ].x = 80;
        gTileClips[ 26 ].y = 240;
        gTileClips[ 26 ].w = TILE_WIDTH;
        gTileClips[ 26 ].h = TILE_HEIGHT;

        gTileClips[ 27 ].x = 120;
        gTileClips[ 27 ].y = 240;
        gTileClips[ 27 ].w = TILE_WIDTH;
        gTileClips[ 27 ].h = TILE_HEIGHT;

    }

    void Localmap::SetTiles() {

        std::ifstream map("maps/localmap.map");


        int tileType;
        for (int i = 0; i < TILES_ROW; i++) {
            for (int j = 0; j < TILES_COL; j++) {

                map >> tileType;

                //std::cout << tileType << " ";

                tiles[i][j] = std::make_shared<Sprite>(csdl_setup->GetRenderer(), tileType, gTileClips, "assets/tiles1.png",
                                         TILE_WIDTH * j, TILE_HEIGHT * i, CameraX, CameraY,CollisionRect());

            }

            std::cout << std::endl;
        }

        map.close();

    }

    void Localmap::Update() {

        //Debuggin Mode
        //Show collisoin image
        if (csdl_setup->GetMainEvent()->type == SDL_KEYDOWN) {
            if (!isPressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1) {
                isPressed = true;

                if (!debMode) {
                    std::cout << "Debugging Mode" << std::endl;
                    debMode = true;
                }
                else {
                    std::cout << "Exit Debugging Mode" << std::endl;
                    debMode = false;
                }

            }
        }

        if (csdl_setup->GetMainEvent()->type == SDL_KEYUP) {
            if (isPressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_F1) {
                isPressed = false;
            }
        }


    }

    void Localmap::Render() {


        for ( int i = 0; i < TILES_ROW; i++) {
              for (int j = 0; j < TILES_COL; j++) {
              tiles[i][j]->Draw();
            }
         }

        //Draw all the enviroment object like buildings,
        //trees etc.
        for (auto i: enviromentObjects) {
            i->DrawObject();
            i->GetObject()->SetDebugMode(debMode);
        }

        main_char->Draw();
        main_char->Update();

    }
}