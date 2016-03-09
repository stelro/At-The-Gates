/*
 * src/Locamap.cpp
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
 *
 */

#include "Locamap.h"

namespace tok {

    Localmap::Localmap(std::shared_ptr<SdlInitializer> passed_csdl_setup,int screenWidth, int screenHeight, double *passedCameraX, double *passedCameraY,
                       int *passedMouseX, int *passedMouseY) :
    csdl_setup(passed_csdl_setup), CameraX(passedCameraX), CameraY(passedCameraY), MouseX(passedMouseX), MouseY(passedMouseY)
    {

        InitializeTiles();

        onPress = false;

        main_char = std::make_shared<MainCharacter>(csdl_setup, MouseX, MouseY, CameraX, CameraY);

        SetTiles();

    }

    Localmap::~Localmap() {


    }

    void Localmap::InitializeTiles() {

        gTileClips[ TILE_ROCKMAIN ].x = 0;
        gTileClips[ TILE_ROCKMAIN ].y = 0;
        gTileClips[ TILE_ROCKMAIN ].w = TILE_WIDTH;
        gTileClips[ TILE_ROCKMAIN ].h = TILE_HEIGHT;

        gTileClips[ TILE_ROCKCORN_LU ].x = 0;
        gTileClips[ TILE_ROCKCORN_LU ].y = 80;
        gTileClips[ TILE_ROCKCORN_LU ].w = TILE_WIDTH;
        gTileClips[ TILE_ROCKCORN_LU ].h = TILE_HEIGHT;

        gTileClips[ TILE_ROCKCORN_LD ].x = 0;
        gTileClips[ TILE_ROCKCORN_LD ].y = 160;
        gTileClips[ TILE_ROCKCORN_LD ].w = TILE_WIDTH;
        gTileClips[ TILE_ROCKCORN_LD ].h = TILE_HEIGHT;

        gTileClips[ TILE_ROCKCORN_RU ].x = 80;
        gTileClips[ TILE_ROCKCORN_RU ].y = 80;
        gTileClips[ TILE_ROCKCORN_RU ].w = TILE_WIDTH;
        gTileClips[ TILE_ROCKCORN_RU ].h = TILE_HEIGHT;

        gTileClips[ TILE_ROCKCORN_RD ].x = 80;
        gTileClips[ TILE_ROCKCORN_RD ].y = 160;
        gTileClips[ TILE_ROCKCORN_RD ].w = TILE_WIDTH;
        gTileClips[ TILE_ROCKCORN_RD ].h = TILE_HEIGHT;
    }

    void Localmap::SetTiles() {

        std::ifstream map("maps/localmap.map");


        int tileType;
        for (int i = 0; i < TILES_ROW; i++) {
            for (int j = 0; j < TILES_COL; j++) {

                map >> tileType;

                //std::cout << tileType << " ";

                tiles[i][j] = std::make_shared<Sprite>(csdl_setup->GetRenderer(), tileType, gTileClips, "assets/assets.png",
                                         TILE_WIDTH * j, TILE_HEIGHT * i, CameraX, CameraY);

            }

            std::cout << std::endl;
        }

        map.close();

    }

    void Localmap::Update() {


    }

    void Localmap::Render() {


      for ( int i = 0; i < TILES_ROW; i++) {
          for (int j = 0; j < TILES_COL; j++) {
              tiles[i][j]->Draw();
          }
      }

        main_char->Draw();
        main_char->Update();
    }
}