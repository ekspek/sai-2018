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

    float midX=(float) WINDOW_SIZE_X/2;
    float midY=(float) WINDOW_SIZE_Y/2;

    roll=0;

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable ( GL_SCISSOR_TEST ) ;
    glScissor (200 , 200 , 400 , 400 ) ;
    glTranslatef(midX, midY,1.0); //Move reference to the middle of the screen
    glRotatef (roll , 0 , 0 , 1) ;

    // Draw the blue section
    glBegin ( GL_POLYGON ) ;
    glColor3f (0.4 ,0.4 ,1) ;
    glVertex3f (-400 ,-1 + pitch ,0) ;
    glVertex3f (-400 ,-WINDOW_SIZE_Y + pitch,0) ;
    glVertex3f (400 ,-WINDOW_SIZE_Y + pitch,0) ;
    glVertex3f (400 ,-1 + pitch,0) ;
    glEnd () ;

    //Draw the brown section
    glBegin ( GL_POLYGON ) ;
    glColor3f (0.7 ,0.5 ,0) ;
    glVertex3f (-400 ,1+ pitch ,0) ;
    glVertex3f (-400 ,WINDOW_SIZE_Y + pitch,0) ;
    glVertex3f (400 ,WINDOW_SIZE_Y+ pitch,0) ;
    glVertex3f (400 ,1+ pitch,0) ;
    glEnd () ;

    //Draw the Horizon line
    glBegin ( GL_POLYGON ) ;
    glColor3f (1 ,1,1) ;
    glVertex3f (-400 ,1+ pitch ,0) ;
    glVertex3f (-400 ,-1 + pitch,0) ;
    glVertex3f (400 ,-1+ pitch,0) ;
    glVertex3f (400 ,1+ pitch,0) ;
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
    glScissor(200 , 200 , 400 , 350 ) ;
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    for (i=1; i<=9; i=i+1){ //10 degree lines
        //Negative pitch
        glVertex3f(-50,-60*i+pitch,0);
        glVertex3f(50,-60*i+pitch,0);

        //Positive pitch
        glVertex3f(-50,60*i+pitch,0);
        glVertex3f(50,60*i+pitch,0);
    }

    for (i=1; i<=18; i=i+2){ //5 degree lines
        //Negative pitch
        glVertex3f(-25,-30*i+pitch,0);
        glVertex3f(25,-30*i+pitch,0);

        //Positive pitch
        glVertex3f(-25,30*i+pitch,0);
        glVertex3f(25,30*i+pitch,0);
    }

    for (i=1; i<=36; i=i+2){ //2.5 degree lines
        //Negative pitch
        glVertex3f(-10,-15*i+pitch,0);
        glVertex3f(10,-15*i+pitch,0);

        //Positive pitch
        glVertex3f(-10,15*i+pitch,0);
        glVertex3f(10,15*i+pitch,0);
    }
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

void draw_text(){
	int scale = 10;
	draw_character(9,3); 
}

void draw_square(int x, int y, int size){
	x = x * size;
	y = y * size;
	glBegin(GL_QUADS);
		glVertex2f(x,y);
		glVertex2f(x + size,y);
		glVertex2f(x + size,y + size);
		glVertex2f(x,y + size);
	glEnd();
}

void draw_character(int num, int scale){
	switch(num){
		case 0:
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(1,1,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(1,5,scale);
			draw_square(2,5,scale);
			draw_square(5,5,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			break;

		case 1:
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(1,1,scale);
			draw_square(2,1,scale);
			draw_square(3,1,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(2,5,scale);
			draw_square(3,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case 2:
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(1,4,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(2,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			draw_square(6,6,scale);
			break;

		case 3:
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(3,2,scale);
			draw_square(4,2,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case 4:
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(2,1,scale);
			draw_square(3,1,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(4,5,scale);
			draw_square(5,5,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case 5:
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case 6:
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(1,1,scale);
			draw_square(2,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case 7:
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(2,5,scale);
			draw_square(3,5,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			break;

		case 8:
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(5,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(5,2,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(0,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case 9:
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(4,5,scale);
			draw_square(5,5,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			break;
	}
}
