/*-------------------------------------------------------+
|           SAI - Trabalho Experimental                  |
+--------------------------------------------------------+
|           Grupo 11 - Projecto E2                       |
|                                                        |
|Pedro Afonso                                            |
|João Manito                                             |
|Daniel Schiffart                                        |
+--------------------------------------------------------+
| Definicao do tipo de letra utilizando poligonos OpenGL |
| O tipo de letra utilizado e Press Start 2P             |
+-------------------------------------------------------*/

#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "font.h"

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

void draw_character(char n, int scale){
	switch(n){
		case '0':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(1*scale,1*scale);
				glVertex2f(2*scale,1*scale);
				glVertex2f(2*scale,4*scale);
				glVertex2f(1*scale,4*scale);
				glVertex2f(1*scale,1*scale);
			glEnd();
			break;

		case '1':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(2*scale,0*scale);
				glVertex2f(2*scale,5*scale);
				glVertex2f(1*scale,5*scale);
				glVertex2f(1*scale,1*scale);
				glVertex2f(0*scale,1*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			break;

		case '2':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,3*scale);
				glVertex2f(1*scale,3*scale);
				glVertex2f(1*scale,4*scale);
				glVertex2f(3*scale,4*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,2*scale);
				glVertex2f(2*scale,2*scale);
				glVertex2f(2*scale,1*scale);
				glVertex2f(0*scale,1*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			break;

		case '3':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,4*scale);
				glVertex2f(2*scale,4*scale);
				glVertex2f(2*scale,3*scale);
				glVertex2f(1*scale,3*scale);
				glVertex2f(1*scale,2*scale);
				glVertex2f(2*scale,2*scale);
				glVertex2f(2*scale,1*scale);
				glVertex2f(0*scale,1*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			break;

		case '4':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(1*scale,0*scale);
				glVertex2f(1*scale,2*scale);
				glVertex2f(2*scale,2*scale);
				glVertex2f(2*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(2*scale,5*scale);
				glVertex2f(2*scale,3*scale);
				glVertex2f(0*scale,3*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			break;

		case '5':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,1*scale);
				glVertex2f(1*scale,1*scale);
				glVertex2f(1*scale,2*scale);
				glVertex2f(3*scale,2*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,4*scale);
				glVertex2f(2*scale,4*scale);
				glVertex2f(2*scale,3*scale);
				glVertex2f(0*scale,3*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			break;

		case '6':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(1*scale,0*scale);
				glVertex2f(1*scale,2*scale);
				glVertex2f(3*scale,2*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(1*scale,3*scale);
				glVertex2f(2*scale,3*scale);
				glVertex2f(2*scale,4*scale);
				glVertex2f(1*scale,4*scale);
				glVertex2f(1*scale,3*scale);
			glEnd();
			break;

		case '7':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(2*scale,5*scale);
				glVertex2f(2*scale,1*scale);
				glVertex2f(0*scale,1*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			break;

		case '8':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(1*scale,1*scale);
				glVertex2f(2*scale,1*scale);
				glVertex2f(2*scale,2*scale);
				glVertex2f(1*scale,2*scale);
				glVertex2f(1*scale,1*scale);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(1*scale,3*scale);
				glVertex2f(2*scale,3*scale);
				glVertex2f(2*scale,4*scale);
				glVertex2f(1*scale,4*scale);
				glVertex2f(1*scale,3*scale);
			glEnd();
			break;

		case '9':
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(3*scale,0*scale);
				glVertex2f(3*scale,5*scale);
				glVertex2f(2*scale,5*scale);
				glVertex2f(2*scale,3*scale);
				glVertex2f(0*scale,3*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(1*scale,1*scale);
				glVertex2f(2*scale,1*scale);
				glVertex2f(2*scale,2*scale);
				glVertex2f(1*scale,2*scale);
				glVertex2f(1*scale,1*scale);
			glEnd();
			break;

		default:
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,0*scale);
				glVertex2f(1*scale,0*scale);
				glVertex2f(1*scale,3*scale);
				glVertex2f(0*scale,3*scale);
				glVertex2f(0*scale,0*scale);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(0*scale,4*scale);
				glVertex2f(1*scale,4*scale);
				glVertex2f(1*scale,5*scale);
				glVertex2f(0*scale,5*scale);
				glVertex2f(0*scale,4*scale);
			glEnd();
			break;
	}
}
