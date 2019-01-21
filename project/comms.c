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

void* thread_comms(void* ptr){
	while(1){
		printf("Hello from the other side\n");
	}
}

int main (){
	pthread_t thread_comms_id;

	pthread_create(&thread_comms_id,NULL,thread_comms,NULL);
	while(1){
		printf("Hello World!\n");
	}

	return 0;
}
