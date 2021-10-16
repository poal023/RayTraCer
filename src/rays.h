#ifndef RAYS_H
#define RAYS_H
#include "vec3.h"

struct ray{
    struct vec3 origin, direction;
};

//define as a parametric equation: P(t) = Direction*t + Origin
struct vec3 pointAlongRay(struct ray *R, double t);

#endif
