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

        std::ifstream gg("assets/localmap.map");


        int omg;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {

                gg >> omg;

                std::cout << omg << std::endl;
                    tiles[i][j] = new Sprite(csdl_setup->GetRenderer(), omg, gTileClips, "assets/assets.png",
                                             80 * i, 80 * j, CameraX, CameraY);

            }

        }
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






    }

    void Localmap::Update() {


    }

    void Localmap::Render() {


      for ( int i = 0; i < 8; i++) {
          for (int j = 0; j < 8; j++) {
              tiles[i][j]->Draw();
          }
      }

        main_char->Draw();
        main_char->Update();
    }
}