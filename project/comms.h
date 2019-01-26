/*-------------------------------------------------------+
|           SAI - Trabalho Experimental                  |
+--------------------------------------------------------+
|           Grupo 11 - Projecto E2                       |
|                                                        |
| Pedro Afonso                                           |
| João Manito                                            |
| Daniel de Schiffart                                    |
+--------------------------------------------------------+
| Funcoes da thread de recepcao de dados                 |
+-------------------------------------------------------*/

#ifndef __COMMS_H__
#define __COMMS_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>

float float_swap(float value);
void* thread_comms(void *ptr);

#endif
