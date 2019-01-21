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

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <string.h>

#include "font.h"
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

    glDisable(GL_SCISSOR_TEST);
}

void draw_airspeed_indicator(float airspeed){

    int i=0; //Auxiliary counter
    float max_airspeed = 400; //Maximum airspeed of the aircraft in knots
    float max_airspeed_pixels;
    float airspeed_scale_factor=5; //2 pixels per knot
    float airspeed_pixels;

    //Auxiliary position variables
    float x;
    float y;
    float z;

    //roll=0;
    //pitch=0;
    airspeed_pixels = airspeed * airspeed_scale_factor;
    max_airspeed_pixels= max_airspeed * airspeed_scale_factor;



    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable ( GL_SCISSOR_TEST ) ;
    glScissor (50,100,100,600 ) ;
    glTranslatef(50, 400,-2.0); //Move reference to the middle left of the box

    //Move the entire slider for the amount of pixels corresponding to current airspeed
    glTranslatef(0,airspeed_pixels,0);

    // Draw the indicator background
    glBegin ( GL_POLYGON ) ;
    glColor3f (0.470, 0.470, 0.470);
    glVertex3f (0,350,0);
    glVertex3f (75 ,350,0) ;
    glVertex3f (75 ,-max_airspeed_pixels,0) ;
    glVertex3f (0,-max_airspeed_pixels,0) ;
    glEnd () ;

    // Draw the indicator scale
    glTranslatef(75,0,1);
    for (i=-30;i<=max_airspeed;i=i+10){
        glTranslatef(0,-10*airspeed_scale_factor,0);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,1,0);
        glVertex3f(-10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();
    }

    glDisable(GL_SCISSOR_TEST);

}

void draw_altitude_indicator(float altitude){

    int i=0; //Auxiliary counter
    float max_altitude = 50000; //Maximum altitude of the aircraft in feet
    float max_altitude_pixels;
    float altitude_scale_factor=5; //2 pixels per knot
    float altitude_pixels;

    //Auxiliary position variables
    float x;
    float y;
    float z;

    //roll=0;
    //pitch=0;
    altitude_pixels = altitude * altitude_scale_factor;
    max_altitude_pixels= max_altitude * altitude_scale_factor;



    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable ( GL_SCISSOR_TEST ) ;
    glScissor (675,100,75,600 ) ;
    glTranslatef(675,400,-2.0); //Move reference to the middle left of the box

    //Move the entire slider for the amount of pixels corresponding to current airspeed
    glTranslatef(0,altitude_pixels,0);

    // Draw the indicator background
    glBegin ( GL_POLYGON ) ;
    glColor3f (0.470, 0.470, 0.470);
    glVertex3f (75,350,0);
    glVertex3f (0 ,350,0) ;
    glVertex3f (0 ,-max_altitude_pixels,0) ;
    glVertex3f (75,-max_altitude_pixels,0) ;
    glEnd () ;

    // Draw the indicator scale
    glTranslatef(0,0,1);
    for (i=-30;i<=max_altitude;i=i+10){
        glTranslatef(0,-10*altitude_scale_factor,0);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(10,1,0);
        glVertex3f(10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();
    }

    glDisable(GL_SCISSOR_TEST);

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

/* Draw a string of characters using OpenGL and the Press Start font
 * Accepts the string, its screen coordinates x and y, an angle, and
 * a scaling value.
 *
 * When set to scale 1, each character is 7 pixels tall and wide. */
void draw_text(char* string, int x, int y, int angle, int scale){
	//char string[10] = "218417241";
	int aux = 0;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x,y,0);
	glRotatef(-angle, 0, 0, 1);

	while(string[aux] != '\0'){
		draw_character(string[aux],scale); 

		if(string[aux+1] != '\0'){
			glTranslatef(8*scale,0,0);
		}

		aux++;
	}
}




void drawCircle (GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides)
{
 GLint numberOfVertices = numberOfSides + 2;
 GLfloat doublePi = 2.0f * PI;
 GLfloat circleVerticesX[numberOfVertices];
 GLfloat circleVerticesY[numberOfVertices];
 GLfloat circleVerticesZ[numberOfVertices];

 circleVerticesX[0]=x;
 circleVerticesY[0]=y;
 circleVerticesZ[0]=z;


for (int i = 1; i < numberOfVertices; i++)
    {
    circleVerticesX[i] = x + (radius*cos(i + doublePi/numberOfSides));
    circleVerticesY[i] = y + (radius*sin(i + doublePi/numberOfSides));
    circleVerticesZ[i] = z;
    }

GLfloat allCircleVertices[numberOfVertices * 3];

for(int i = 0; i< numberOfVertices; i++)
    {
    allCircleVertices[i*3] = circleVerticesX[i];
    allCircleVertices[(i*3)+1] = circleVerticesY[i];
    allCircleVertices[(i*3)+2] = circleVerticesZ[i];
    }

glEnableClientState( GL_VERTEX_ARRAY);
glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
glDisableClientState(GL_VERTEX_ARRAY);


}



void draw_heading_indicator(float heading)
{
    int u;
    char numb [360][3]; //numbers in characters
    int i=0; //Auxiliary counter
    char string_aux[3];

    float midX = (float) WINDOW_SIZE_X/2;

    printf("1\n");
    for(u=0;u<360;u=u+1)
    {
        //printf("%d\n",u);
        //sprintf(&numb[u][3],"%d", u);
        sprintf(string_aux,"%d", u);
        strcpy(numb[u],string_aux);
        //printf("%3s\n",numb[u]);
        //getchar();
    }

    /*
    for (i=0;i<=359;i++){
        printf("%3s\n",numb[i]);
        //getchar();
    }
    */
    //getchar();


    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glColor3f (0.3 , 0.4 , 0.1);
    drawCircle(400,850, 1, 200, 500);


    glLoadIdentity();
    glTranslatef(midX,640,1.5);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-10,0,0);
    glVertex3f(10,0,0);
    glVertex3f(0,15,0);
    glEnd();




    for (i=0;i<=359;i=i+10)
    {
            glLoadIdentity();
            glTranslatef(midX, 850,2);
            glRotatef(-heading,0,0,1);
            glRotatef(i,0,0,2);
            glTranslatef(0, -200,0); //Move the matrix to the arc center
            glBegin(GL_POLYGON);
            glColor3f(1,1,1);
            glVertex3f(-1,20,0);
            glVertex3f(1,20,0);
            glVertex3f(1,0,0);
            glVertex3f(-1,0,0);
            glEnd();
            glTranslatef(-5,21,0);
            draw_character(numb[i][0],1);
            glTranslatef(6,0,0);
            draw_character(numb[i][1],1);
            glTranslatef(6,0,0);
            draw_character(numb[i][2],1);





        }


    for (i=5;i<=359;i=i+10)
    {
            glLoadIdentity();
            glTranslatef(midX, 850,2);
            glRotatef(-heading,0,0,1);
            glRotatef(i,0,0,2);
            glTranslatef(0, -200,0); //Move the matrix to the arc center
            glBegin(GL_POLYGON);
            glColor3f(1,1,1);
            glVertex3f(-1,10,0);
            glVertex3f(1,10,0);
            glVertex3f(1,0,0);
            glVertex3f(-1,0,0);
            glEnd();
        }


}









