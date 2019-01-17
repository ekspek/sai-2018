// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle.

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <GL/gl.h>
# include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
# include <math.h>

#include "global_variables.h"
#include "draw_functions.h"


int main ( int argc , char * argv [] ) {

    //_ERROR = 1;    /* initialization ; always start in error mode */
    //_in_package.Heading = 0;
    //_in_package.Pitch   = 0;
    //_in_package.Roll    = 0;
    //_in_package.timestamp.tv_sec = 0;
    //_in_package.timestamp.tv_usec = 0;

    /*
    * Window for the primary flight display
    */

    SDL_Window* window;
    SDL_Renderer* renderer;
    int i=0;
    int j=1;
    int k=0;
    int l=1;

    SDL_Init ( SDL_INIT_VIDEO ) ;

    SDL_GL_SetAttribute ( SDL_GL_RED_SIZE , 8) ;
    SDL_GL_SetAttribute ( SDL_GL_GREEN_SIZE , 8) ;
    SDL_GL_SetAttribute ( SDL_GL_BLUE_SIZE , 8) ;
    SDL_GL_SetAttribute ( SDL_GL_DEPTH_SIZE , 8) ;
    SDL_GL_SetAttribute ( SDL_GL_DOUBLEBUFFER , 1) ;

    //SDL_WM_SetCaption (  , "Primary Flight Display" ) ;
    //SDL_SetVideoMode ( WINDOW_SIZE_X , WINDOW_SIZE_Y , 24 , SDL_WINDOW_OPENGL | SDL_HWSURFACE ) ;
    window = SDL_CreateWindow("Primary Flight Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WINDOW_SIZE_X,WINDOW_SIZE_Y, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, 0);



    glViewport (0 , 0 , WINDOW_SIZE_X , WINDOW_SIZE_Y ) ;
    glMatrixMode ( GL_PROJECTION ) ;
    glLoadIdentity () ;
    glOrtho (0 , WINDOW_SIZE_X , WINDOW_SIZE_Y , 0 , -2 , 2) ;
    glClearColor (0 , 0 , 0 , 0) ;
    glClearDepth (2) ;
    glEnable ( GL_DEPTH_TEST ) ;
    glDepthFunc ( GL_LEQUAL ) ;

    TTF_Init();
    //TTF_Font* Mono = TTF_OpenFont("Inconsolata-Bold.ttf", 10);
    TTF_Font* Mono = TTF_OpenFont("monaco.ttf", 24);
    if(Mono == NULL){
        printf("Font not found.\n");
    }
    SDL_Color White = {255, 255, 255};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Mono, "Test text", White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = 200;
    Message_rect.y = 200;
    // Message_rect.w = 100;
    // Message_rect.h = 15;
    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);

    SDL_Surface* surfaceMessage2 = TTF_RenderText_Solid(Mono, "Another test text", White);
    SDL_Texture* Message2 = SDL_CreateTextureFromSurface(renderer, surfaceMessage2);
    SDL_Rect Message_rect2;
    Message_rect.x = 200;
    Message_rect.y = 200;
    // Message_rect.w = 100;
    // Message_rect.h = 15;
    SDL_QueryTexture(Message2, NULL, NULL, &Message_rect2.w, &Message_rect2.h);


    /*
    * Draws until user orders to quit
    */
    while (1) {
        SDL_Event event ;
        //draw () ;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //draw_test();
        //SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
        //SDL_RenderCopy(renderer, Message2, NULL, &Message_rect2);
        draw_artificial_horizon(i,k);

        SDL_GL_SwapWindow(window);


        while ( SDL_PollEvent (& event ) > 0) {
            if ( event . type == SDL_QUIT ) {
                break ;
            }
            if ( event . type == SDL_KEYDOWN ) {
                if ( event . key . keysym . sym == SDLK_ESCAPE ) {
                    break ;
                }
            }
        }
        if ( event . type == SDL_QUIT ) {
            break ;
        }

        if ( event . type == SDL_KEYDOWN ) {
            if ( event . key . keysym . sym == SDLK_ESCAPE ) {
                break ;
            }
        }

        /* DEBUG PITCH AND ROLL ROUTINE */
        i=i+j*1;
        if (i==6*90)
        {
            j=-1;
        }

        if (i==-6*90){
            j=1;
        }

        k=i+j*1;
        if (k==6*90)
        {
            l=-1;
        }

        if (k==-6*90){
            l=1;
        }

        /* END DEBUG PITCH ROUTINE*/

    }
    //SDL_FreeSurface(surfaceMessage);
    //SDL_DestroyTexture(Message);
    SDL_Quit () ;
    return 0;
}
