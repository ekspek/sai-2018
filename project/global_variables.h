/*-------------------------------------------------------+
|           SAI - Trabalho Experimental                  |
+--------------------------------------------------------+
|           Grupo 11 - Projecto E2                       |
|                                                        |
| Pedro Afonso                                           |
| João Manito                                            |
| Daniel de Schiffart                                    |
+--------------------------------------------------------+
| Protótipos das funções para gerar os diversos          |
| indicadores da aeronave                                |
+-------------------------------------------------------*/

#ifndef __GLOBAL_VARIABLES_H__
#define __GLOBAL_VARIABLES_H__

#include <pthread.h>

#define WINDOW_SIZE_X 900
#define WINDOW_SIZE_Y 800
#define PI 3.14159
#define CHAR_WIDTH 5
#define CHAR_SKIP 1

/* Main data structure that the program uses to process
 * incoming and display data.
 *
 * Altitude is defined in feet.
 * IAS is defined in knots.
 * Vertical speed is feet per minute.
 * Pitch, roll and heading are defined in degrees. */
typedef struct data {
	double altitude;
	double ias;
	double vspeed;
	double pitch;
	double roll;
	double heading;
} Data;

#endif
