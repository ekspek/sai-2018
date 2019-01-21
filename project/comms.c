#include<stdio.h>
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

#include "global_variables.h"

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
Data data_current;

void* thread_comms(void* ptr){
	printf("Started communications thread\n");
	
	pthread_mutex_lock(&m);
	sleep(3);
	data_current.altitude = 2000;
	printf("O valor da altitude é %f\n", data_current.altitude);
	pthread_mutex_unlock(&m);
}

int main (){
	pthread_t thread_comms_id;

	data_current.altitude = 3000;
	data_current.ias = 150;
	data_current.vspeed = 0;
	data_current.pitch = 0;
	data_current.roll = 0;
	data_current.heading = 0;

	pthread_create(&thread_comms_id,NULL,thread_comms,NULL);
	
	sleep(1);
	pthread_mutex_lock(&m);
	data_current.altitude = 4000;
	printf("O valor da altitude é %f\n", data_current.altitude);
	pthread_mutex_unlock(&m);

	pthread_cancel(thread_comms_id);

	return 0;
}
