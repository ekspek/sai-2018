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
    float i=1; //altitude test variable
    float j=1; //pitch test variable
    float k=1; //heading test variable
    float l=1; //roll test variable
    float n=1; //airspeed test variable
    float m=1; //vspeed test variable

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
        draw_artificial_horizon(data_current.pitch, data_current.roll);
        draw_airspeed_indicator(data_current.ias);
        draw_heading_indicator(data_current.heading);
        draw_altitude_indicator(data_current.altitude);
        draw_vspeed_indicator(data_current.vspeed);
        pthread_mutex_unlock(&mutex_main);

        /* Debug value display */
        glLoadIdentity();
        glTranslatef(20,20,1.0);
        sprintf(test_string,"A %f",data_current.altitude);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"S %f",data_current.ias);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"V %f",data_current.vspeed);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(150,-40,0);
        sprintf(test_string,"P %f",data_current.pitch);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"R %f",data_current.roll);
        draw_text(test_string,2);
        test_string[0] = '\0';
        glTranslatef(0,20,0);
        sprintf(test_string,"H %f",data_current.heading);
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


        /* DEBUG ROUTINEs
        data_current.altitude = data_current.altitude + 2*i;
        if (1000 - data_current.altitude <= 0.1)
            i = -1;
        if (1000 + data_current.altitude <= -0.1)
            i = 1;

        data_current.pitch = data_current.pitch + j;
        if (90 - data_current.pitch <= 0.1)
            j = -1;
        if (90 + data_current.pitch <= -0.1)
            j = 1;

        data_current.heading = data_current.heading + k;
        if (359 - data_current.heading <= 0.1)
            k = -1;

        if (359 + data_current.heading <= -0.1)
            k = 1;

        data_current.roll = data_current.roll + l;
        if (60 - data_current.roll <= 0.1)
            l = -1;
        if (60 + data_current.roll <= -0.1)
            l = 1;

        data_current.ias=data_current.ias+n*0.1;
        if (400 - data_current.ias <= 0.1)
            n = -1;

        if (400 + data_current.ias <= -0.1)
            n = 1;

        data_current.vspeed=data_current.vspeed+m*0.1;
        if (9 - data_current.vspeed <= 0.1)
            m = -1;

        if (9 + data_current.vspeed <= -0.1)
            m = 1;
        /**/
        //printf("Altitude is %f, IAS is %f, vertical speed is %f, pitch is %f, roll is %f, heading is %f\n", data_current.altitude, data_current.ias, data_current.vspeed, data_current.pitch, data_current.roll, data_current.heading);
        /* END DEBUG PITCH ROUTINE*/
    }
    SDL_Quit();
    pthread_cancel(thread_comms_id);
    return 0;
}
