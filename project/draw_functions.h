/*-------------------------------------------------------+
|           SAI - Trabalho Experimental                  |
+--------------------------------------------------------+
|           Grupo 11 - Projecto E2                       |
|                                                        |
|Pedro Afonso                                            |
|João Manito                                             |
|Daniel Schiffart                                        |
+--------------------------------------------------------+
|Protótipos das funções para gerar os diversos           |
|indicadores da aeronave                                 |
+-------------------------------------------------------*/

#ifndef __DRAW_FUNCTIONS_H__
#define __DRAW_FUNCTIONS_H__

int draw_text(char* string, int scale);
void draw_artificial_horizon(float pitch, float roll);
void draw_airspeed_indicator(float airspeed);
void draw_altitude_indicator(float draw_altitude,GLuint texture);
void draw_test(GLuint texture);
void drawCircle (GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides);
void draw_heading_indicator(float heading);
void generate_altimeter_texture(GLuint* tex);

#endif
