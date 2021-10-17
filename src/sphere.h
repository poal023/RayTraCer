#ifndef SPHERE_H
#define SPHERE_H

#include "utils.h"
#include "rays.h"
#include "hittable.h"

struct sphere {
	struct vec3 center;
	double radius;
};


int intersectSphere(struct sphere *S, struct ray *R, double tmin, double tmax, struct hitRecord *HR);

#endif
