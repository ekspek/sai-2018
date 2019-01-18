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
# include <math.h>

#include "global_variables.h"
#include "draw_functions.h"
#include "font.h"


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
    float i=0;
    float j=1;
    float k=0;
    float l=1;


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

    /*
    * Draws until user orders to quit
    */
    while (1) {
        SDL_Event event ;
        //draw () ;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //draw_test();
        //draw_artificial_horizon(i,k);
		    draw_text("Why2",100,100,45,2);
        draw_artificial_horizon(i,k);
        draw_airspeed_indicator(i);

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
        i=i+j*0.1;
        //printf("i=%f j=%f\n",i,j);
        if (90-i<=0.1)
        {
            j=-1;
        }

        if (90+i<=-0.1){
            j=1;
        }

        k=k+l*0.1;
        if (90-k<=0.1)
        {
            l=-1;
        }

        if (90+k<=-0.1){
            l=1;
        }

        /* END DEBUG PITCH ROUTINE*/

    }
    //SDL_FreeSurface(surfaceMessage);
    //SDL_DestroyTexture(Message);
    SDL_Quit () ;
    return 0;
}
