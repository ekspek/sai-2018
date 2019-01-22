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

#include "global_variables.h"

#define BUFFER_SIZE 1024 

/* Global variable definitions */
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
Data data_current;

/* Function that contains the code run by the communications thread */
void* thread_comms(void* ptr){
	printf("Started communications thread\n");

	/* Setting up sockets and communications */
	struct sockaddr_in server_addr, client_addr;
	//int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

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

	/* Main incoming data loop */
	while(1){
		bytes_in = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, (socklen_t*)&clientlen);
		if(bytes_in)
			printf("Received message %s\n", buffer);
	}

	/* Mutex testing */
	//pthread_mutex_lock(&m);
	//sleep(3);
	//data_current.altitude = 2000;
	//printf("O valor da altitude é %f\n", data_current.altitude);
	//pthread_mutex_unlock(&m);
}

int main (){
	uint32_t port = 8500;
	pthread_t thread_comms_id;

	/* Initial values for the data structure */
	data_current.altitude = 3000;
	data_current.ias = 150;
	data_current.vspeed = 0;
	data_current.pitch = 0;
	data_current.roll = 0;
	data_current.heading = 0;

	/* Begin of communications thread */
	pthread_create(&thread_comms_id,NULL,thread_comms,&port);

	/* Mutex testing */
	//sleep(1);
	//pthread_mutex_lock(&m);
	//data_current.altitude = 4000;
	//printf("O valor da altitude é %f\n", data_current.altitude);
	//pthread_mutex_unlock(&m);
	while(1);

	pthread_cancel(thread_comms_id);

	return 0;
}
