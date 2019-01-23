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

#include "comms.h"

#define BUFFER_SIZE 1024

extern pthread_mutex_t mutex_main;
extern Data data_current;

/* Reverses endianess of a floating point value
 *
 * Data received by the project arrives in big-endian
 * mode, needs to be swapped for every variable */
float float_swap(float value){
	union v {
		float f;
		unsigned int i;
	};
	 
	union v val;
	 
	val.f = value;
	val.i = htonl(val.i);
	               
	return val.f;
}

/* Function that contains the code run by the communications thread
 *
 * The port is defined in the main program and passed into this function.
 * Opens up a socket for receiving UDP data and listens to it in the main
 * loop of the thread.
 *
 * Whenever data arrives, changes the shared main variable data_current,
 * which is locked beforehand via a mutex. */
void* thread_comms(void* ptr){

    double gs, vpath, vspeed_kts;

	/* Setting up sockets and communications */
	struct sockaddr_in server_addr, client_addr;

	// Setup UDP socket
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0){
		fprintf(stderr, "Error starting socket\n");
		exit(1);
	}

	// Port Reusing
	int optval = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval,sizeof(int));

	// Configure port
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(*(uint32_t*)ptr);

	// Bind to given port
	if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0){
		perror("bind");
		exit(1);
	}

	char buffer[BUFFER_SIZE];
	size_t bytes_in;

	int clientlen = sizeof(client_addr);

	// Sender's API places each variable on a given position
	const int wordsize = 4;

	/* Main incoming data loop */
	while(1){
		bytes_in = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, (socklen_t*)&clientlen);

		if(bytes_in){
			pthread_mutex_lock(&mutex_main);
			data_current.altitude = float_swap(*(float*)(buffer + 2 * wordsize));
			data_current.ias = float_swap(*(float*)(buffer + 6 * wordsize));
			data_current.pitch = float_swap((*(float*)(buffer + 7 * wordsize)));
			data_current.roll = float_swap((*(float*)(buffer + 8 * wordsize)));
			data_current.heading = float_swap((*(float*)(buffer + 9 * wordsize)));
			gs = float_swap((*(float*)(buffer + 5 * wordsize)));
			vpath = float_swap((*(float*)(buffer + 3 * wordsize)));
            vspeed_kts = gs * tan(vpath * M_PI / 180);
            data_current.vspeed = vspeed_kts*101.2685914252;
			pthread_mutex_unlock(&mutex_main);
		}
	}
}
