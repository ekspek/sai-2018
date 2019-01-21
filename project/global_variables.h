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

#ifndef __GLOBAL_VARIABLES_H__
#define __GLOBAL_VARIABLES_H__

#define WINDOW_SIZE_X 800
#define WINDOW_SIZE_Y 800
#define PI 3.14159
#define CHAR_WIDTH 7
#define CHAR_SKIP 1

typedef struct Data {
	double altitude;
	double ias;
	double vspeed;
	double pitch;
	double roll;
	double heading;
} Data;

#endif
