//
// Created by stel on 5/3/2016.
//

#ifndef TOK_LTEXTURE_H
#define TOK_LTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace tok {

    class LTexture {
    private:
        SDL_Renderer *gRenderer;
        SDL_Texture *mTexture;
        int mWidth;
        int mHeight;
    public:
        //Initializes variables
        LTexture(SDL_Renderer *passed_renderer );

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path );

#ifdef _SDL_TTF_H
        //Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
#endif

        //Deallocates texture
        void free();

        //Set color modulation
        void setColor( Uint8 red, Uint8 green, Uint8 blue );

        //Set blending
        void setBlendMode( SDL_BlendMode blending );

        //Set alpha modulation
        void setAlpha( Uint8 alpha );

        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    };
}


#endif //TOK_LTEXTURE_H
