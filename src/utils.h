#ifndef RTUTILS_H
#define RTUTILS_H

#include "vec3.h"
#include <math.h>
#include <stdlib.h>

#define INF HUGE_VAL
#define NEGINF -HUGE_VAL

#define EPSILON 0.00001f

#define max(x,y) ((x > y) ? (x) : (y))
#define min(x,y) ((x < y) ? (x) : (y))

double degreesToRadians(double degrees);
double randomDouble();
double randomDoubleInRange(double min, double max);
double clamp(double x, double min, double max);
#endif
