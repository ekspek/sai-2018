/*-------------------------------------------------------+
|           SAI - Trabalho Experimental                  |
+--------------------------------------------------------+
|           Grupo 11 - Projecto E2                       |
|                                                        |
|Pedro Afonso                                            |
|João Manito                                             |
|Daniel Schiffart                                        |
+--------------------------------------------------------+
|Funções para gerar os diversos indicadores da aeronave  |
+-------------------------------------------------------*/

# include <GL/gl.h>
# include <SDL2/SDL.h>
# include <math.h>

#include "draw_functions.h"
#include "global_variables.h"

void draw_artificial_horizon(float pitch, float roll)
{
    int i=0; //Auxiliary counter
    float pitch_scale_factor=6;
    float pitch_pixels;

    float midX=(float) WINDOW_SIZE_X/2;
    float midY=(float) WINDOW_SIZE_Y/2;

    //Auxiliary position variables
    float x;
    float y;
    float z;

    //roll=0;
    //pitch=0;
    pitch_pixels = pitch * pitch_scale_factor;



    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable ( GL_SCISSOR_TEST ) ;
    glScissor (200 , 200 , 400 , 400 ) ;
    glTranslatef(midX, midY,1.0); //Move reference to the middle of the screen
    glRotatef (roll , 0 , 0 , 1) ;

    // Draw the blue section
    glBegin ( GL_POLYGON ) ;
    glColor3f (0.4 ,0.4 ,1) ;
    glVertex3f (-400 ,-1 + pitch_pixels ,0) ;
    glVertex3f (-400 ,-WINDOW_SIZE_Y + pitch_pixels,0) ;
    glVertex3f (400 ,-WINDOW_SIZE_Y + pitch_pixels,0) ;
    glVertex3f (400 ,-1 + pitch_pixels,0) ;
    glEnd () ;

    //Draw the brown section
    glBegin ( GL_POLYGON ) ;
    glColor3f (0.7 ,0.5 ,0) ;
    glVertex3f (-400 ,1+ pitch_pixels ,0) ;
    glVertex3f (-400 ,WINDOW_SIZE_Y + pitch_pixels,0) ;
    glVertex3f (400 ,WINDOW_SIZE_Y+ pitch_pixels,0) ;
    glVertex3f (400 ,1+ pitch_pixels,0) ;
    glEnd () ;

    //Draw the Horizon line
    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1,1) ;
    glVertex3f (-400 ,1+ pitch_pixels ,0) ;
    glVertex3f (-400 ,-1 + pitch_pixels,0) ;
    glVertex3f (400 ,-1+ pitch_pixels,0) ;
    glVertex3f (400 ,1+ pitch_pixels,0) ;
    glEnd () ;

    glDisable(GL_SCISSOR_TEST);


    //Draw the Plane Horizontal indicator
    glLoadIdentity();
    glEnable ( GL_SCISSOR_TEST ) ;
    glScissor (200 , 200 , 400 , 400 ) ;
    glTranslatef(midX, midY,1.5);

    //Left Wing
    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-150 ,0,0) ;
    glVertex3f (-50 ,0,0) ;
    glVertex3f (-50 ,2,0) ;
    glVertex3f (-150 ,2,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-50 ,0,0) ;
    glVertex3f (-50 ,29,0) ;
    glVertex3f (-48 ,29,0) ;
    glVertex3f (-48 ,0,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-50 ,27,0) ;
    glVertex3f (-50 ,29,0) ;
    glVertex3f (-56 ,29,0) ;
    glVertex3f (-56 ,27,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-54 ,29,0) ;
    glVertex3f (-56 ,29,0) ;
    glVertex3f (-56 ,6,0) ;
    glVertex3f (-54,6,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-54 ,6,0) ;
    glVertex3f (-54 ,8,0) ;
    glVertex3f (-150 ,8,0) ;
    glVertex3f (-150 ,6,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-150 ,8,0) ;
    glVertex3f (-150 ,0,0) ;
    glVertex3f (-148 ,0,0) ;
    glVertex3f (-148 ,8,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (0 ,0 ,0) ;
    glVertex3f (-148 ,2,0) ;
    glVertex3f (-50 ,2,0) ;
    glVertex3f (-50 ,6,0) ;
    glVertex3f (-148 ,6,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (0 ,0 ,0) ;
    glVertex3f (-54 ,2,0) ;
    glVertex3f (-50 ,2,0) ;
    glVertex3f (-50 ,27,0) ;
    glVertex3f (-54 ,27,0) ;
    glEnd () ;

    //Right Wing
    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (150 ,0,0) ;
    glVertex3f (50 ,0,0) ;
    glVertex3f (50 ,2,0) ;
    glVertex3f (150 ,2,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (50 ,0,0) ;
    glVertex3f (50 ,29,0) ;
    glVertex3f (48 ,29,0) ;
    glVertex3f (48 ,0,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (50 ,27,0) ;
    glVertex3f (50 ,29,0) ;
    glVertex3f (56 ,29,0) ;
    glVertex3f (56 ,27,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (54 ,29,0) ;
    glVertex3f (56 ,29,0) ;
    glVertex3f (56 ,6,0) ;
    glVertex3f (54,6,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (54 ,6,0) ;
    glVertex3f (54 ,8,0) ;
    glVertex3f (150 ,8,0) ;
    glVertex3f (150 ,6,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (150 ,8,0) ;
    glVertex3f (150 ,0,0) ;
    glVertex3f (148 ,0,0) ;
    glVertex3f (148 ,8,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (0 ,0 ,0) ;
    glVertex3f (148 ,2,0) ;
    glVertex3f (50 ,2,0) ;
    glVertex3f (50 ,6,0) ;
    glVertex3f (148 ,6,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (0 ,0 ,0) ;
    glVertex3f (54 ,2,0) ;
    glVertex3f (50 ,2,0) ;
    glVertex3f (50 ,27,0) ;
    glVertex3f (54 ,27,0) ;
    glEnd () ;

    //Nose
    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1 ,1) ;
    glVertex3f (-5 ,0,0) ;
    glVertex3f (5 ,0,0) ;
    glVertex3f (5 ,10,0) ;
    glVertex3f (-5 ,10,0) ;
    glEnd () ;

    glBegin ( GL_POLYGON ) ;
    glColor3f (0 ,0 ,0) ;
    glVertex3f (-3 ,2,0) ;
    glVertex3f (3 ,2,0) ;
    glVertex3f (3 ,8,0) ;
    glVertex3f (-3 ,8,0) ;
    glEnd () ;

    glDisable(GL_SCISSOR_TEST);

    //Draw the pitch angle lines
    glEnable(GL_SCISSOR_TEST);  //WARNING: está a manter a cor do horizonte artificial mesmo quando este desaparece!
    glLoadIdentity();
    glTranslatef(midX, midY,1);
    glRotatef (roll , 0 , 0 , 1) ;
    glScissor(300 , 200 , 200 , 350 ) ;



    glBegin(GL_LINES);
    glColor3f(1,1,1);
    for (i=1; i<=9; i=i+1){ //10 degree lines
        //Negative pitch
        glVertex3f(-50,-60*i+pitch_pixels,0);
        glVertex3f(50,-60*i+pitch_pixels,0);

        //Positive pitch
        glVertex3f(-50,60*i+pitch_pixels,0);
        glVertex3f(50,60*i+pitch_pixels,0);
    }

    for (i=1; i<=18; i=i+2){ //5 degree lines
        //Negative pitch
        glVertex3f(-25,-30*i+pitch_pixels,0);
        glVertex3f(25,-30*i+pitch_pixels,0);

        //Positive pitch
        glVertex3f(-25,30*i+pitch_pixels,0);
        glVertex3f(25,30*i+pitch_pixels,0);
    }

    for (i=1; i<=36; i=i+2){ //2.5 degree lines
        //Negative pitch
        glVertex3f(-10,-15*i+pitch_pixels,0);
        glVertex3f(10,-15*i+pitch_pixels,0);

        //Positive pitch
        glVertex3f(-10,15*i+pitch_pixels,0);
        glVertex3f(10,15*i+pitch_pixels,0);
    }
    glEnd();
    glDisable(GL_SCISSOR_TEST);


    //Draw the roll angle indicator
    glLoadIdentity();
    glEnable ( GL_SCISSOR_TEST ) ;
    glScissor (200 , 200 , 400 , 400 ) ;
    

    //Draw the fixed triangle
    glLoadIdentity();
    glTranslatef(midX, midY,1);
    glRotatef(roll,0,0,1);
    glTranslatef(0, -200,0);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-10,20,0);
    glVertex3f(10,20,0);
    glVertex3f(0,10,0);
    glEnd();

    glLoadIdentity();
    glTranslatef(midX,midY,1);
    glTranslatef(0, -200,0); //Move the matrix to the arc center
    //Draw the 0 degrees triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-10,0,0);
    glVertex3f(10,0,0);
    glVertex3f(0,10,0);
    glEnd();


    //Draw the arc
    /*
    glLoadIdentity();
    glTranslatef(midX, midY-30,1);
    glRotatef(roll,0,0,1);
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);


    for (i=-90;i<=90;i++){
        x = cos(i*PI/180 - PI/2);    //Define X position
        y = sin(i*PI/180 - PI/2);    //Define Y position
        glVertex3f(150*x,150*y,0);
        glVertex3f(150*x,150*y,0);

        //printf("x=%f,y=%f\n",x,y);  //DEBUG
    }
    glEnd();
    /**/

    //Draw the angle indicator lines
    //For angles of +-10 and +-20 degrees
    for (i=10;i<=20;i=i+10){
        glLoadIdentity();
        glTranslatef(midX, midY,1);
        //glRotatef(roll,0,0,1);
        glRotatef(i,0,0,1);
        glTranslatef(0, -190,0); //Move the matrix to the arc center
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-1,-10,0);
        glVertex3f(1,-10,0);
        glVertex3f(1,0,0);
        glVertex3f(-1,0,0);
        glEnd();

        glLoadIdentity();
        glTranslatef(midX, midY,1);
        //glRotatef(roll,0,0,1);
        glRotatef(-i,0,0,1);
        glTranslatef(0, -190,0); //Move the matrix to the arc center
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-1,-10,0);
        glVertex3f(1,-10,0);
        glVertex3f(1,0,0);
        glVertex3f(-1,0,0);
        glEnd();
    }

    //For angles of +-30 and +-60 degrees
    for (i=30;i<=60;i=i+30){
        glLoadIdentity();
        glTranslatef(midX, midY,1);
        //glRotatef(roll,0,0,1);
        glRotatef(i,0,0,1);
        glTranslatef(0, -190,0); //Move the matrix to the arc center
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-1,-20,0);
        glVertex3f(1,-20,0);
        glVertex3f(1,0,0);
        glVertex3f(-1,0,0);
        glEnd();

        glLoadIdentity();
        glTranslatef(midX, midY,1);
        //glRotatef(roll,0,0,1);
        glRotatef(-i,0,0,1);
        glTranslatef(0, -190,0); //Move the matrix to the arc center
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-1,-20,0);
        glVertex3f(1,-20,0);
        glVertex3f(1,0,0);
        glVertex3f(-1,0,0);
        glEnd();
    }

    //For angles of +-45 degrees
    i=45;
    glLoadIdentity();
    glTranslatef(midX, midY,1);
    //glRotatef(roll,0,0,1);
    glRotatef(i,0,0,1);
    glTranslatef(0, -190,0); //Move the matrix to the arc center
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-1,-10,0);
    glVertex3f(1,-10,0);
    glVertex3f(1,0,0);
    glVertex3f(-1,0,0);
    glEnd();

    glLoadIdentity();
    glTranslatef(midX, midY,1);
    //glRotatef(roll,0,0,1);
    glRotatef(-i,0,0,1);
    glTranslatef(0, -190,0); //Move the matrix to the arc center
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-1,-10,0);
    glVertex3f(1,-10,0);
    glVertex3f(1,0,0);
    glVertex3f(-1,0,0);
    glEnd();
}


void draw_test(){
    glTranslatef(1.0f,0.0f,0.0f);
    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,0 ,0) ;
    glVertex3f (110 ,100 ,0) ;
    glVertex3f (120 ,100 ,0) ;
    glVertex3f (120 ,110 ,0) ;
    glVertex3f (110 ,110 ,0) ;
    glEnd () ;
}

