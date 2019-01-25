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

#include "font.h"
#include "draw_functions.h"
#include "global_variables.h"

/* Draw a string of characters using OpenGL. Accepts the string and a
 * scaling value.
 *
 * The character width and skip are fixed(CHAR_WIDTH and CHAR_SKIP) on
 * draw_functions.h. The CHAR_WIDTH is dependent on the font used which
 * is defined in font.c.
 *
 * This function returns the total width(in SDL coordinates) of the
 * drawn text as an int value. */
int draw_text(char* string, int scale){
    int aux = 0;

    while(string[aux] != '\0'){
        draw_character(string[aux],scale);

        if(string[aux+1] != '\0')
            glTranslatef((CHAR_WIDTH + CHAR_SKIP)*scale,0,0);

        aux++;
    }

    glTranslatef(-(CHAR_WIDTH + CHAR_SKIP)*scale*(aux - 1),0,0);

    return(aux - 1) *(CHAR_WIDTH + CHAR_SKIP) + CHAR_WIDTH;
}

void draw_artificial_horizon(float pitch, float roll)
{
    int i=0; //Auxiliary counter
    float pitch_scale_factor=6;
    float pitch_pixels;
    char pitch_str[2];

    float midX=(float) WINDOW_SIZE_X/2;
    float midY=(float) WINDOW_SIZE_Y/2;

    //Auxiliary position variables
    float x;
    float y;
    float z;

    pitch_pixels = pitch * pitch_scale_factor;



    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(200,200,400,400);
    glTranslatef(midX-50, midY,1.0); //Move reference to the middle of the screen
    glRotatef(roll,0,0,1);

    // Draw the blue section
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,1);
    glVertex3f(-400,-1 + pitch_pixels,0);
    glVertex3f(-400,-WINDOW_SIZE_Y-50 + pitch_pixels,0);
    glVertex3f(400,-WINDOW_SIZE_Y-50 + pitch_pixels,0);
    glVertex3f(400,-1 + pitch_pixels,0);
    glEnd();

    //Draw the brown section
    glBegin(GL_POLYGON);
    glColor3f(0.7 ,0.5 ,0);
    glVertex3f(-400 ,1+ pitch_pixels ,0);
    glVertex3f(-400 ,WINDOW_SIZE_Y+50 + pitch_pixels,0);
    glVertex3f(400 ,WINDOW_SIZE_Y+50+ pitch_pixels,0);
    glVertex3f(400 ,1+ pitch_pixels,0);
    glEnd();

    //Draw the Horizon line
    glBegin(GL_POLYGON);
    glColor3f(1 ,1,1);
    glVertex3f(-400 ,1+ pitch_pixels ,0);
    glVertex3f(-400 ,-1 + pitch_pixels,0);
    glVertex3f(400 ,-1+ pitch_pixels,0);
    glVertex3f(400 ,1+ pitch_pixels,0);
    glEnd();

    glDisable(GL_SCISSOR_TEST);


    //Draw the Plane Horizontal indicator
    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(200 , 200 , 400 , 400);
    glTranslatef(midX-50, midY,1.5);

    //Left Wing
    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-150 ,0,0);
    glVertex3f(-50 ,0,0);
    glVertex3f(-50 ,2,0);
    glVertex3f(-150 ,2,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-50 ,0,0);
    glVertex3f(-50 ,29,0);
    glVertex3f(-48 ,29,0);
    glVertex3f(-48 ,0,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-50 ,27,0);
    glVertex3f(-50 ,29,0);
    glVertex3f(-56 ,29,0);
    glVertex3f(-56 ,27,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-54 ,29,0);
    glVertex3f(-56 ,29,0);
    glVertex3f(-56 ,6,0);
    glVertex3f(-54,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-54 ,6,0);
    glVertex3f(-54 ,8,0);
    glVertex3f(-150 ,8,0);
    glVertex3f(-150 ,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-150 ,8,0);
    glVertex3f(-150 ,0,0);
    glVertex3f(-148 ,0,0);
    glVertex3f(-148 ,8,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0 ,0 ,0);
    glVertex3f(-148 ,2,0);
    glVertex3f(-50 ,2,0);
    glVertex3f(-50 ,6,0);
    glVertex3f(-148 ,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0 ,0 ,0);
    glVertex3f(-54 ,2,0);
    glVertex3f(-50 ,2,0);
    glVertex3f(-50 ,27,0);
    glVertex3f(-54 ,27,0);
    glEnd();

    //Right Wing
    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(150 ,0,0);
    glVertex3f(50 ,0,0);
    glVertex3f(50 ,2,0);
    glVertex3f(150 ,2,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(50 ,0,0);
    glVertex3f(50 ,29,0);
    glVertex3f(48 ,29,0);
    glVertex3f(48 ,0,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(50 ,27,0);
    glVertex3f(50 ,29,0);
    glVertex3f(56 ,29,0);
    glVertex3f(56 ,27,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(54 ,29,0);
    glVertex3f(56 ,29,0);
    glVertex3f(56 ,6,0);
    glVertex3f(54,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(54 ,6,0);
    glVertex3f(54 ,8,0);
    glVertex3f(150 ,8,0);
    glVertex3f(150 ,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(150 ,8,0);
    glVertex3f(150 ,0,0);
    glVertex3f(148 ,0,0);
    glVertex3f(148 ,8,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0 ,0 ,0);
    glVertex3f(148 ,2,0);
    glVertex3f(50 ,2,0);
    glVertex3f(50 ,6,0);
    glVertex3f(148 ,6,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0 ,0 ,0);
    glVertex3f(54 ,2,0);
    glVertex3f(50 ,2,0);
    glVertex3f(50 ,27,0);
    glVertex3f(54 ,27,0);
    glEnd();

    //Nose
    glBegin(GL_POLYGON);
    glColor3f(1 ,1 ,1);
    glVertex3f(-5 ,0,0);
    glVertex3f(5 ,0,0);
    glVertex3f(5 ,10,0);
    glVertex3f(-5 ,10,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0 ,0 ,0);
    glVertex3f(-3 ,2,0);
    glVertex3f(3 ,2,0);
    glVertex3f(3 ,8,0);
    glVertex3f(-3 ,8,0);
    glEnd();

    glDisable(GL_SCISSOR_TEST);

    //Draw the pitch angle lines and numbers
    glEnable(GL_SCISSOR_TEST);
    glLoadIdentity();
    glTranslatef(midX-50, midY,1);
    glRotatef(roll , 0 , 0 , 1);
    glScissor(300 , 200 , 200 , 350);



    glBegin(GL_LINES);
    glColor3f(1,1,1);
    //10 degree lines
    for(i=1; i<=9; i=i+1){
        //Negative pitch
        glVertex3f(-50,-60*i+pitch_pixels,0);
        glVertex3f(50,-60*i+pitch_pixels,0);

        //Positive pitch
        glVertex3f(-50,60*i+pitch_pixels,0);
        glVertex3f(50,60*i+pitch_pixels,0);
    }
    //5 degree lines
    for(i=1; i<=18; i=i+2){
        //Negative pitch
        glVertex3f(-25,-30*i+pitch_pixels,0);
        glVertex3f(25,-30*i+pitch_pixels,0);

        //Positive pitch
        glVertex3f(-25,30*i+pitch_pixels,0);
        glVertex3f(25,30*i+pitch_pixels,0);
    }

    //2.5 degree lines
    for(i=1; i<=36; i=i+2){
        //Negative pitch
        glVertex3f(-10,-15*i+pitch_pixels,0);
        glVertex3f(10,-15*i+pitch_pixels,0);

        //Positive pitch
        glVertex3f(-10,15*i+pitch_pixels,0);
        glVertex3f(10,15*i+pitch_pixels,0);
    }
    glEnd();

    //Print pitch numbers
    for(i=1; i<=9; i=i+1){
        //Positive pitch
        //Align left
        glTranslatef(-88,-60*i+pitch_pixels-7,0);
        sprintf(pitch_str,"%d",i*10);
        draw_text(pitch_str,2);
        glTranslatef(88,60*i-pitch_pixels+7,0);
        //Align right
        glTranslatef(60,-60*i+pitch_pixels-7,0);
        sprintf(pitch_str,"%d",i*10);
        draw_text(pitch_str,2);
        glTranslatef(-60,60*i-pitch_pixels+7,0);

        //Negative pitch
        //Align left
        glTranslatef(-88,60*i+pitch_pixels-7,0);
        sprintf(pitch_str,"%d",i*10);
        draw_text(pitch_str,2);
        glTranslatef(88,-60*i-pitch_pixels+7,0);
        //Align right
        glTranslatef(60,60*i+pitch_pixels-7,0);
        sprintf(pitch_str,"%d",i*10);
        draw_text(pitch_str,2);
        glTranslatef(-60,-60*i-pitch_pixels+7,0);
    }
    glDisable(GL_SCISSOR_TEST);


    //Draw the roll angle indicator
    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(200 , 200 , 400 , 400);


    //Draw the roll indicator cursor
    glLoadIdentity();
    glTranslatef(midX-50, midY,1);
    glRotatef(roll,0,0,1);
    glTranslatef(0, -200,0);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-10,20,0);
    glVertex3f(10,20,0);
    glVertex3f(0,10,0);
    glEnd();

    glLoadIdentity();
    glTranslatef(midX-50,midY,1);
    glTranslatef(0, -200,0); //Move the matrix to the arc center

    //Draw the 0 degrees triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-10,0,0);
    glVertex3f(10,0,0);
    glVertex3f(0,10,0);
    glEnd();


    //Draw the angle indicator lines
    //For angles of +-10 and +-20 degrees
    for(i=10;i<=20;i=i+10){
        glLoadIdentity();
        glTranslatef(midX-50, midY,1);
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
        glTranslatef(midX-50, midY,1);
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
    for(i=30;i<=60;i=i+30){
        glLoadIdentity();
        glTranslatef(midX-50, midY,1);
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
        glTranslatef(midX-50, midY,1);
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
    glTranslatef(midX-50, midY,1);
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
    glTranslatef(midX-50, midY,1);
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
    char airspeed_str[9];

    //Auxiliary variables for the decimals,units, tens and hundreds
    float d;
    float u;
    float t;
    float h;

    airspeed_pixels = airspeed * airspeed_scale_factor;
    max_airspeed_pixels= max_airspeed * airspeed_scale_factor;

    //Airspeed sanity check
    if (airspeed > max_airspeed){
        airspeed = max_airspeed;
    } else if (airspeed < 0) {
        airspeed = 0;
    }


    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(50,100,100,600);
    glTranslatef(50, 400,-2.0); //Move reference to the middle left of the box

    // Draw the indicator background
    glBegin(GL_POLYGON);
    glColor3f(0.470, 0.470, 0.470);
    glVertex3f(0,350,0);
    glVertex3f(75 ,350,0);
    glVertex3f(75 ,-350,0);
    glVertex3f(0,-350,0);
    glEnd();

    //Translate the entire scale according to current airspeed
    glTranslatef(75,airspeed_pixels+10*airspeed_scale_factor,1);

    //Draw the airspeed indicator scale
    for(i=0;i<=max_airspeed;i=i+10){
        glTranslatef(0,-10*airspeed_scale_factor,0);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,1,0);
        glVertex3f(-10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();

        if(i%20 == 0 || i==0){
            glTranslatef(-75,-7,0);
            sprintf(airspeed_str,"%4d",i);
            draw_text(airspeed_str,2);
            glTranslatef(75,7,0);
        }
    }
    glDisable(GL_SCISSOR_TEST);


    //Draw the current airspeed meter
    glLoadIdentity();
    glTranslatef(50, 400,1.0); //Move reference to the middle left of the box

    //Draw the white outline
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-40,40,0);
    glVertex3f(60,40,0);
    glVertex3f(60,10,0);
    glVertex3f(70,0,0);
    glVertex3f(60,-10,0);
    glVertex3f(60,-40,0);
    glVertex3f(-40,-40,0);
    glEnd();

    //Draw the black fill
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(-38,38,0);
    glVertex3f(58,38,0);
    glVertex3f(58,8,0);
    glVertex3f(67,0,0);
    glVertex3f(58,-8,0);
    glVertex3f(58,-38,0);
    glVertex3f(-38,-38,0);
    glEnd();


    //Divide the IAS into 3 separate, single digits
    h=floorf(airspeed/100);
    t=floorf((airspeed-h*100)/10);
    u=floorf(airspeed-h*100-t*10);
    d=airspeed-h*100-t*10-u;

    //Draw the hundreds digit
    glColor3f(1,1,1);
    glTranslatef(-35,-15,1);
    sprintf(airspeed_str,"%1.0f",h);
    draw_text(airspeed_str,5);

    //Draw the tens digit
    glColor3f(1,1,1);
    glTranslatef(32,0,0);
    sprintf(airspeed_str,"%1.0f",t);
    draw_text(airspeed_str,5);


    //Draw the units digit
    //Draw four numbers, two above and two below the current rounded airspeed. Use a scissor box for croping the excess of the numbers
    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(47,360,100,80);
    glTranslatef(50-35+32, 400-15,1); //Move reference to the middle left of the box
    glTranslatef(0,d*40,0);

    glColor3f(1,1,1);                   //u
    glTranslatef(32,0,0);
    sprintf(airspeed_str,"%1.0f",u);
    draw_text(airspeed_str,5);

    glColor3f(1,1,1);                   //u+2
    glTranslatef(0,-80,0);
    if(u+2 >= 10){        //Avoid 2 digit strings
        sprintf(airspeed_str,"%01.0f",u+2-10);
    } else{
        sprintf(airspeed_str,"%01.0f",u+2);
    }
    if(airspeed < max_airspeed){
        draw_text(airspeed_str,5);
    }

    glColor3f(1,1,1);                   //u+1
    glTranslatef(0,40,0);
    if(u+1 >= 10){        //Avoid 2 digit strings
        sprintf(airspeed_str,"%01.0f",u+1-10);
    } else{
        sprintf(airspeed_str,"%01.0f",u+1);
    }
    if(airspeed < max_airspeed){
        draw_text(airspeed_str,5);
    }

    glColor3f(1,1,1);                   //u-1
    glTranslatef(0,80,0);
    if(10+u-1 >= 10){        //Avoid 2 digit strings
        sprintf(airspeed_str,"%01.0f",u-1);
    } else{
        sprintf(airspeed_str,"%01.0f",(10+u-1));
    }
    if(airspeed > 1){
        draw_text(airspeed_str,5);
    }

    glColor3f(1,1,1);                   //u-2
    glTranslatef(0,40,0);
    if(10+u-2 >= 10){        //Avoid 2 digit strings
        sprintf(airspeed_str,"%01.0f",u-2);
    } else{
        sprintf(airspeed_str,"%01.0f",(10+u-2));
    }
    if(airspeed > 1){
        draw_text(airspeed_str,5);
    }
    glDisable(GL_SCISSOR_TEST);


}

void draw_altitude_indicator(float altitude){

    int i=0; //Auxiliary counter
    float max_altitude = 50000; //Maximum altitude of the aircraft in feet
    float max_altitude_pixels;
    float altitude_scale_factor=5; //5 pixels per 10 feet
    float altitude_pixels;
    char altitude_str[6];
    float sign;

    //Auxiliary variables for the tens, hundreds and thousands
    float t;
    float t_precise;
    float h;
    float th;

    altitude_pixels = altitude*0.1 * altitude_scale_factor;
    max_altitude_pixels= max_altitude*0.1 * altitude_scale_factor;

    //Altitude sanity check
    if (altitude > max_altitude){
        altitude = max_altitude;
    } else if (altitude < -1000) {
        altitude = 0;
    }



    glMatrixMode(GL_MODELVIEW);

    //Define the altitude slider visible window
    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(675,100,110,600);
    glTranslatef(675,400,-2.0); //Move reference to the middle left of the box

    //Draw the altitude background
    glBegin(GL_POLYGON);
    glColor3f(0.470, 0.470, 0.470);
    glVertex3f(110,350,0);
    glVertex3f(-100 ,350,0);
    glVertex3f(-100 ,-350,0);
    glVertex3f(110,-350,0);
    glEnd();


    //Draw the indicator scale
    //Move the entire slider for the amount of pixels corresponding to current altitude
    glTranslatef(0,altitude_pixels + 110*altitude_scale_factor,0);
    for(i=-1000;i<=50000;i=i+100){
        glTranslatef(0,-10*altitude_scale_factor,0);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(10,1,0);
        glVertex3f(10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();
        if(i%20 == 0 || i==0){
            glTranslatef(13,-7,0);
            sprintf(altitude_str,"%5d",i);
            draw_text(altitude_str,2);
            glTranslatef(-13,7,0);
        }
    }
    glDisable(GL_SCISSOR_TEST);

    //Draw the altitude below limit indicator
    if (altitude < -400) {
        glLoadIdentity();
        glTranslatef(675,700,-1.5); //Move the reference to the lower left corner of the box
        glBegin(GL_POLYGON); //Draw the red indicator, 1 pixel below the -1000ft scale mark
        glColor3f(1,0,0);
        glVertex3f(0,(altitude+400)*0.1*altitude_scale_factor+1,0);
        glVertex3f(10,(altitude+400)*0.1*altitude_scale_factor+1,0);
        glVertex3f(10,0,0);
        glVertex3f(0,0,0);
        glEnd();
    }

    //Draw the altitude below limit indicator
    if (altitude > 46000) {
        glLoadIdentity();
        glTranslatef(675,100,-1.5); //Move the reference to the upper left corner of the box
        glBegin(GL_POLYGON); //Draw the red indicator, 1 pixel above the 50000ft scale mark
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,((altitude-49400)*0.1*altitude_scale_factor-1),0);
        glVertex3f(10,((altitude-49400)*0.1*altitude_scale_factor-1),0);
        glVertex3f(10,0,0);

        glEnd();
    }


    //Draw the current altitude meter
    glLoadIdentity();
    glTranslatef(675,400,-1); //Move reference to the middle left of the box

    //Draw the white outline
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(150,40,0);
    glVertex3f(20,40,0);
    glVertex3f(20,10,0);
    glVertex3f(10,0,0);
    glVertex3f(20,-10,0);
    glVertex3f(20,-40,0);
    glVertex3f(150,-40,0);
    glEnd();

    //Draw the black fill
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(148,38,0);
    glVertex3f(22,38,0);
    glVertex3f(22,10,0);
    glVertex3f(13,0,0);
    glVertex3f(22,-10,0);
    glVertex3f(22,-38,0);
    glVertex3f(148,-38,0);
    glEnd();

    //Determine altitude sign
    if(altitude>=0){
        sign=1; //Y axis is upside down
    } else {
        sign=-1;
    }

    //Divide the altitude into 3 separate groups(thousands, hundreds and tens)
    th=floorf(fabs(altitude)/1000);
    h=floorf((fabs(altitude)-th*1000)/100);
    t=floorf(fabs(altitude)-th*1000-h*100);
    t_precise=t;

    if(fmodf(t,20) != 0 && t != 0){
        t=floor(t/20)*20;
    }

    //Draw the thousands digit
    glColor3f(1,1,1);
    glTranslatef(25,-15,1);
    sprintf(altitude_str,"%2.0f",th);
    if(sign != -1){
        draw_text(altitude_str,4);
    } else {
        strncpy(altitude_str,"-",1);
        draw_text(altitude_str,4);
    }

    //Draw the hundreds digit
    glColor3f(1,1,1);
    glTranslatef(48,0,0);
    sprintf(altitude_str,"%1.0f",h);
    draw_text(altitude_str,4);


    //Draw the tens digits
    //Draw four numbers, two above and two below the current rounded altitude. Use a scisor box for croping the excess of the numbers
    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(695,360,130,80);
    glTranslatef(675+25+32,400-15,0); //Move reference to the middle left of the box
    glTranslatef(0,2*fmodf(t_precise,20),0);

    glColor3f(1,1,1);                   //t
    glTranslatef(42,0,0);
    sprintf(altitude_str,"%02.0f",t);
    draw_text(altitude_str,4);

    glColor3f(1,1,1);                   //t+40
    glTranslatef(0,-80,0);
    if(t+40 >= 100){        //Avoid 3 digit strings
        sprintf(altitude_str,"%02.0f",t+40-100);
    } else{
        sprintf(altitude_str,"%02.0f",t+40);
    }
    if(altitude < max_altitude){
        draw_text(altitude_str,4);
    }

    glColor3f(1,1,1);                   //t+20
    glTranslatef(0,40,0);
    if(t+20 >= 100){        //Avoid 3 digit strings
        sprintf(altitude_str,"%02.0f",t+20-100);
    } else{
        sprintf(altitude_str,"%02.0f",t+20);
    }
    if(altitude < max_altitude){
        draw_text(altitude_str,4);
    }

    glColor3f(1,1,1);                   //t-20
    glTranslatef(0,80,0);
    if(100+t-20 >= 100){        //Avoid 3 digit strings
        sprintf(altitude_str,"%02.0f",t-20);
    } else{
        sprintf(altitude_str,"%02.0f",(100+t-20));
    }
    if(altitude > -1000){
        draw_text(altitude_str,4);
    }

    glColor3f(1,1,1);                   //t-20
    glTranslatef(0,40,0);
    if(100+t-40 >= 100){        //Avoid 3 digit strings
        sprintf(altitude_str,"%02.0f",t-40);
    } else{
        sprintf(altitude_str,"%02.0f",(100+t-40));
    }
    if(altitude > -1000){
        draw_text(altitude_str,4);
    }

    glDisable(GL_SCISSOR_TEST);
}

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides)
{
    GLint numberOfVertices = numberOfSides + 2;
    GLfloat doublePi = 2.0f * PI;
    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    circleVerticesX[0]=x;
    circleVerticesY[0]=y;
    circleVerticesZ[0]=z;


    for(int i = 1; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = x +(radius*cos(i + doublePi/numberOfSides));
        circleVerticesY[i] = y +(radius*sin(i + doublePi/numberOfSides));
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

    float midX =(float) WINDOW_SIZE_X/2 - 50;

    for(u=0;u<360;u=u+10)
    {
        sprintf(string_aux,"%d", u);
        strcpy(numb[u],string_aux);
    }

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glColor3f(0 , 0 , 0.8);
    drawCircle(400,850, 1, 200, 500);


    glLoadIdentity();
    glTranslatef(midX,640,1.1);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(-15,-4,0);
    glVertex3f(15,-4,0);
    glVertex3f(0,18,0);
    glEnd();

    glLoadIdentity();
    glTranslatef(midX,640,1.1);
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex3f(-10,-1,0);
    glVertex3f(10,-1,0);
    glVertex3f(0,12,0);
    glEnd();


    for(i=0;i<=359;i=i+10)
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

        if(i==0){
            draw_character('N',3);
        }else{
            if(i==90){
                draw_character('E',3);
            }else{
                if(i==180){
                    draw_character('S',3);
                }else{

                    if(i==270){
                        draw_character('W',3);
                    }else{
                        if(i>99)
                        {

                            draw_character(numb[i][0],1);
                            glTranslatef(6,0,0);
                            draw_character(numb[i][1],1);
                            glTranslatef(6,0,0);
                            draw_character(numb[i][2],1);
                        }
                        else
                        {
                            if(i>9){
                                draw_character(numb[i][0],1);
                                glTranslatef(6,0,0);
                                draw_character(numb[i][1],1);
                            }else{
                                draw_character(numb[i][0],1);

                            }

                        }


                    }
                }
            }
        }
    }


    for(i=5;i<=359;i=i+10)
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


void draw_vspeed_indicator(float vspeed){

    int i=0; //Auxiliary counter
    float vspeed_scale_factor[3] = {70, 40, 7.5};
    float vspeed_capped;
    float sign;
    float midY=(float) WINDOW_SIZE_Y/2;


    glLoadIdentity();
    glTranslatef(WINDOW_SIZE_X-90, midY,-2.0); //Move reference to the middle of the screen

    // Draw the background section
    glBegin(GL_POLYGON);
    glColor3f(0.470, 0.470, 0.470);
    glVertex3f(60 ,100,0);
    glVertex3f(40 ,150,0);
    glVertex3f(0,150,0);
    glVertex3f(0 ,-150,0);
    glVertex3f(40 ,-150,0);
    glVertex3f(60 ,-100,0);
    glEnd();

    //Display the indicator scale
    //Draw the 0 indicator
    glLoadIdentity();
    glTranslatef(WINDOW_SIZE_X-60, midY,-1.5);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-10,2,0);
    glVertex3f(-10,-2,0);
    glVertex3f(10,-2,0);
    glVertex3f(10,2,0);
    glEnd();

    glTranslatef(-25,-7,0);
    draw_character('0',2);

    //Draw the +-6 indicator
    for(i=-1;i<=1;i=i+2){
        glLoadIdentity();
        glTranslatef(WINDOW_SIZE_X-60, midY+i*140,-1.5);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,2,0);
        glVertex3f(-10,-2,0);
        glVertex3f(0,-2,0);
        glVertex3f(0,2,0);
        glEnd();

        glTranslatef(-25,-7,0);
        draw_character('6',2);
    }

    //Draw the +-4 indicator
    for(i=-1;i<=1;i=i+2){
        glLoadIdentity();
        glTranslatef(WINDOW_SIZE_X-60, midY+i*125,-1.5);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,1,0);
        glVertex3f(-10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();
    }

    //Draw the +-2 indicator
    for(i=-1;i<=1;i=i+2){
        glLoadIdentity();
        glTranslatef(WINDOW_SIZE_X-60, midY+i*110,-1.5);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,2,0);
        glVertex3f(-10,-2,0);
        glVertex3f(0,-2,0);
        glVertex3f(0,2,0);
        glEnd();

        glTranslatef(-25,-7,0);
        draw_character('2',2);
    }

    //Draw the +-1.5 indicator
    for(i=-1;i<=1;i=i+2){
        glLoadIdentity();
        glTranslatef(WINDOW_SIZE_X-60, midY+i*90,-1.5);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,1,0);
        glVertex3f(-10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();
    }

    //Draw the +-1 indicator
    for(i=-1;i<=1;i=i+2){
        glLoadIdentity();
        glTranslatef(WINDOW_SIZE_X-60, midY+i*70,-1.5);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,2,0);
        glVertex3f(-10,-2,0);
        glVertex3f(0,-2,0);
        glVertex3f(0,2,0);
        glEnd();

        glTranslatef(-25,-7,0);
        draw_character('1',2);
    }

    //Draw the +-0.5 indicator
    for(i=-1;i<=1;i=i+2){
        glLoadIdentity();
        glTranslatef(WINDOW_SIZE_X-60, midY+i*35,-1.5);
        glBegin(GL_POLYGON);
        glColor3f(1,1,1);
        glVertex3f(-10,1,0);
        glVertex3f(-10,-1,0);
        glVertex3f(0,-1,0);
        glVertex3f(0,1,0);
        glEnd();
    }

    //Determine vspeed sign
    if(vspeed>=0){
        sign=-1; //Y axis is upside down
    } else {
        sign=1;
    }

    if(fabs(vspeed)<=1){
        vspeed_capped=vspeed_scale_factor[0]*fabs(vspeed);
        i=0;
    } else if(fabs(vspeed)<=2){
        vspeed_capped=vspeed_scale_factor[0]*1+vspeed_scale_factor[1]*(fabs(vspeed)-1);
        i=1;
    } else if(fabs(vspeed)<=6.5){
        vspeed_capped=vspeed_scale_factor[0]*1+vspeed_scale_factor[1]*1+vspeed_scale_factor[2]*(fabs(vspeed)-2);
        i=2;
    } else {
        vspeed_capped=vspeed_scale_factor[0]*1+vspeed_scale_factor[1]*1+vspeed_scale_factor[2]*(6.5-2);
        i=2;
    }

    glLoadIdentity();
    glTranslatef(WINDOW_SIZE_X-10, midY,-1.0);

    //Draw the cursor
    glEnable(GL_SCISSOR_TEST);
    glScissor(WINDOW_SIZE_X-90,midY-150,60,300);

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-50,vspeed_capped*sign+2,0);
    glVertex3f(-50,vspeed_capped*sign-2,0);
    glVertex3f(0,-2,0);
    glVertex3f(0,2,0);
    glEnd();
    glDisable(GL_SCISSOR_TEST);
}


