#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define M_PI 3.14159265358979323846
#define TIMESTEP 1
#define GAIN 0.001

int main(void){
	
	double x, h, vx, vh, gamma;
	double T, aoa;
	double v;
	double href;
	
	x = 0;
	h = 1;
	v = 100;
	gamma = 20 * M_PI / 180;
	
	href = 200;
	
	aoa = -5 * M_PI / 180;
	T = 40;
	
	while(1){
		vx = v * cos(gamma) + T * cos(gamma + aoa) * TIMESTEP;
		vh = v * sin(gamma) + T * sin(gamma + aoa) * TIMESTEP;
		
		x = x + vx * TIMESTEP;
		h = h + vh * TIMESTEP;
		gamma = atan2(vh,vx);
		
		aoa = aoa + (GAIN * href - h);
		
		if(h < 0){
			printf("CRASH\n");
			break;
		}
		
		printf("x is %f, height is %f\n", x, h);
		sleep(1);
	}
	
	return 0;
}
