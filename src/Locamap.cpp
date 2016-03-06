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
    }

    Localmap::~Localmap() {


    }

    void Localmap::InitializeTiles() {

        tiles[TILE_ROCKMAIN] = new Sprite(csdl_setup->GetRenderer(), "assets/assets.png",
                                          TILE_ASSET_WIDTH ,TILE_ASSET_HEIGHT ,
                                             TILE_WIDTH,TILE_HEIGHT,0,0,CameraX,CameraY,TILE_ROCKMAIN);

        tiles[TILE_ROCKCORN_LU] = new Sprite(csdl_setup->GetRenderer(), "assets/assets.png",
                                             TILE_ASSET_WIDTH ,TILE_ASSET_HEIGHT ,
                                             TILE_WIDTH,TILE_HEIGHT,0,80,CameraX,CameraY,TILE_ROCKCORN_LU);

        tiles[TILE_ROCKCORN_LD] = new Sprite(csdl_setup->GetRenderer(), "assets/assets.png",
                                             TILE_ASSET_WIDTH ,TILE_ASSET_HEIGHT ,
                                             TILE_WIDTH,TILE_HEIGHT,0,160,CameraX,CameraY,TILE_ROCKCORN_LD);

        tiles[TILE_ROCKCORN_RU] = new Sprite(csdl_setup->GetRenderer(), "assets/assets.png",
                                             TILE_ASSET_WIDTH ,TILE_ASSET_HEIGHT ,
                                             TILE_WIDTH,TILE_HEIGHT,80,80,CameraX,CameraY,TILE_ROCKCORN_RU);

        tiles[TILE_ROCKCORN_RD] = new Sprite(csdl_setup->GetRenderer(), "assets/assets.png",
                                             TILE_ASSET_WIDTH ,TILE_ASSET_HEIGHT ,
                                             TILE_WIDTH,TILE_HEIGHT,80,160,CameraX,CameraY,TILE_ROCKCORN_RD);
    }

    void Localmap::Update() {


    }

    void Localmap::Render() {


        tiles[TILE_ROCKMAIN]->Draw();

        main_char->Draw();
        main_char->Update();
    }
}