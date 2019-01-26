/*-------------------------------------------------------+
|           SAI - Trabalho Experimental                  |
+--------------------------------------------------------+
|           Grupo 11 - Projecto E2                       |
|                                                        |
| Pedro Afonso                                           |
| João Manito                                            |
| Daniel de Schiffart                                    |
+--------------------------------------------------------+
| Codigo principal do programa                           |
+-------------------------------------------------------*/

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
#include "comms.h"

/* Mutex variables for data synchronization */
pthread_mutex_t mutex_main = PTHREAD_MUTEX_INITIALIZER;

/* Main data global variable */
Data data_current;

int main ( int argc , char * argv [] ) {
    Data data_display;

    if(argc != 2){
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    uint32_t port = atoi(argv[1]);
    if(port <= 0 || port > 99999){
        fprintf(stderr, "Error with port input.\n");
        exit(1);
    } 

    pthread_t thread_comms_id;
    pthread_create(&thread_comms_id,NULL,thread_comms,&port);

    char test_string[20];

    /* Window for the primary flight display */
    SDL_Window* window;
    SDL_Renderer* renderer;

    data_current.altitude = 0;
    data_current.pitch = 0;
    data_current.heading = 0;
    data_current.roll = 0;
    data_current.ias = 0;
    data_current.vspeed = 0;

    SDL_Init(SDL_INIT_VIDEO) ;

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    window = SDL_CreateWindow("Primary Flight Display",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_SIZE_X,WINDOW_SIZE_Y,SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, 0);

    glViewport(0,0,WINDOW_SIZE_X,WINDOW_SIZE_Y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,WINDOW_SIZE_X,WINDOW_SIZE_Y,0,-2,2);
    glClearColor(0,0,0,0);
    glClearDepth(2);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    /* Main graphics loop */
    while(1){
        SDL_Event event ;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glMatrixMode(GL_MODELVIEW);
        
        /* Drawing functions, locked by a mutex to prevent printing data
         * while their values are being changed by the communications
         * thread */
        pthread_mutex_lock(&mutex_main);
        data_display = data_current;
        pthread_mutex_unlock(&mutex_main);

        draw_artificial_horizon(data_display.pitch, data_display.roll);
        draw_airspeed_indicator(data_display.ias);
        draw_heading_indicator(data_display.heading);
        draw_altitude_indicator(data_display.altitude);
        draw_vspeed_indicator(data_display.vspeed);

        /* Debug value display */
        glLoadIdentity();
        glTranslatef(20,20,1.0);
        sprintf(test_string,"A %f",data_display.altitude);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"S %f",data_display.ias);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"V %f",data_display.vspeed);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(180,-40,0);
        sprintf(test_string,"P %f",data_display.pitch);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"R %f",data_display.roll);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"H %f",data_display.heading);
        draw_text(test_string,2);
        test_string[0] = '\0';
        /* End debug value display */

        SDL_GL_SwapWindow(window);
        SDL_Delay(10);

        while(SDL_PollEvent(&event)>0){
            if(event.type==SDL_QUIT)
                break;
            if (event.type==SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    break;
                }
            }
        }
        if (event.type==SDL_QUIT){
            break;
        }

        if(event.type==SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_ESCAPE){
                break;
            }
        }

    }
    SDL_Quit();
    pthread_cancel(thread_comms_id);
    return 0;
}
