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
| O tipo de letra utilizado e Press Start 2P              |
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

		case '1':
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

		case '2':
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

		case '3':
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

		case '4':
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

		case '5':
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

		case '6':
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

		case '7':
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

		case '8':
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

		case '9':
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

		case 'E':
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
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
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			draw_square(6,6,scale);
			break;

		case 'M':
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(2,1,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(3,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(5,6,scale);
			draw_square(6,6,scale);
			break;

		case 'N':
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(2,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(4,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(5,6,scale);
			draw_square(6,6,scale);
			break;

		case 'O':
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
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
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

		case 'S':
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(1,3,scale);
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

		case 'W':
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(3,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(2,5,scale);
			draw_square(4,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(5,6,scale);
			draw_square(6,6,scale);
			break;

		case 'f':
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(3,1,scale);
			draw_square(4,1,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(3,5,scale);
			draw_square(4,5,scale);
			break;

		case 't':
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(3,1,scale);
			draw_square(4,1,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(3,5,scale);
			draw_square(4,5,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			break;

		case '.':
			draw_square(3,5,scale);
			draw_square(4,5,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			break;

		case '-':
			draw_square(1,4,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			break;

		case ' ':
			break;

		case '#':
			draw_square(0,0,scale);
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(6,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(2,1,scale);
			draw_square(3,1,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(2,2,scale);
			draw_square(3,2,scale);
			draw_square(4,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(0,3,scale);
			draw_square(1,3,scale);
			draw_square(2,3,scale);
			draw_square(3,3,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(6,3,scale);
			draw_square(0,4,scale);
			draw_square(1,4,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(5,4,scale);
			draw_square(6,4,scale);
			draw_square(0,5,scale);
			draw_square(1,5,scale);
			draw_square(2,5,scale);
			draw_square(3,5,scale);
			draw_square(4,5,scale);
			draw_square(5,5,scale);
			draw_square(6,5,scale);
			draw_square(0,6,scale);
			draw_square(1,6,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			draw_square(5,6,scale);
			draw_square(6,6,scale);
			break;

		default:
			draw_square(1,0,scale);
			draw_square(2,0,scale);
			draw_square(3,0,scale);
			draw_square(4,0,scale);
			draw_square(5,0,scale);
			draw_square(0,1,scale);
			draw_square(1,1,scale);
			draw_square(2,1,scale);
			draw_square(3,1,scale);
			draw_square(4,1,scale);
			draw_square(5,1,scale);
			draw_square(6,1,scale);
			draw_square(0,2,scale);
			draw_square(1,2,scale);
			draw_square(5,2,scale);
			draw_square(6,2,scale);
			draw_square(4,3,scale);
			draw_square(5,3,scale);
			draw_square(2,4,scale);
			draw_square(3,4,scale);
			draw_square(4,4,scale);
			draw_square(2,6,scale);
			draw_square(3,6,scale);
			draw_square(4,6,scale);
			break;
	}
}
