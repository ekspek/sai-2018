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

    Data data_current;
    data_current.altitude = 3000;
    data_current.ias = 150;
    data_current.vspeed = 0;
    data_current.pitch = 0;
    data_current.roll = 0;
    data_current.heading = 0;
    //float i=0; //pitch test variable
    float j=1; //pitch test variable
    //float k=0; //roll test variable
    float l=1; //roll test variable
    //float m=1; //airspeed test variable
    float n=1; //airspeed test variable











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

    /* GENERATE TEXTURE TEST*/
    //create test checker image
    //    unsigned char texDat[64];
    //    for (int i = 0; i < 64; ++i)
    //        texDat[i] = ((i + (i / 8)) % 2) * 128 + 127;
    GLuint tex;
    //generate_altimeter_texture(&tex);


    /**/
    while (1) {
        SDL_Event event ;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(400,50,1.0);
        draw_text("0123456789",2);
        glTranslatef(0,20,0);
        draw_text("EMNOSWft .-?#",2);
        
        draw_artificial_horizon(data_current.pitch, data_current.roll);
        draw_airspeed_indicator(data_current.ias);
        draw_heading_indicator(data_current.pitch);
        draw_altitude_indicator(data_current.ias, tex);

        SDL_GL_SwapWindow(window);
        SDL_Delay(10);


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
        data_current.pitch = data_current.pitch + j*0.1;
        //printf("i=%f j=%f\n",i,j);
        if (90 - data_current.pitch <= 0.1)
        {
            j = -1;
        }

        if (90 + data_current.pitch <= -0.1){
            j = 1;
        }

        data_current.roll = data_current.roll + l*0.1;
        if (60 - data_current.roll <= 0.1)
        {
            l = -1;
        }

        if (60 + data_current.roll <= -0.1){
            l = 1;
        }

        data_current.ias=data_current.ias+n*0.1;
        if (400 - data_current.ias <= 0.1)
        {
            n = -1;
        }

        if (400 + data_current.ias <= -0.1){
            n = 1;
        }

        /* END DEBUG PITCH ROUTINE*/

    }
    SDL_Quit () ;
    return 0;
}
