#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define EARTH_RADIUS 6378000

#define ALTRATE_MOD 0.001	/* Altitude rate modifier */
#define FT2METER 0.3048		/* Feet to meter ratio */
#define CHARBUFFER 100		/* Character buffer */
#define TIMESPAN 600		/* Period between segments in seconds */

/* Coordinate structure, with latitude and longitude in radians and altitude in meters. */
typedef struct {
	double latitude;
	double longitude;
	double altitude;
} Coord ;

/* Coordinate structure, with latitude and longitude in radians and altitude in meters. */
typedef struct {
	double latitude;
	double longitude;
	double altitude;
	double tas;
	char location[CHARBUFFER];
} Waypoint ;

double coord_dist(Coord coord1, Coord coord2);
double coord_dist_linear(Coord coord1, Coord coord2, double heading);
Coord coord_fromdist(Coord coord1, double dist, double heading, double climb);
double depheading(Coord coord1, Coord coord2);
double appheading(Coord coord1, Coord coord2);
double depheading_linear(Coord coord1, Coord coord2);
int read_file(Waypoint* waypoint);
Waypoint csv_waypoint_parse(char line[]);
double gen_subpoints(Coord* subpointlist, Coord waypoint_prev, Coord waypoint_next, double tas);
Coord iter(Coord pos1, double v, double deltat, double theta, double heading);
