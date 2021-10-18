#ifndef SPHERE_H
#define SPHERE_H

#include "utils.h"
#include "rays.h"
#include "hittable.h"
#include "material.h"

struct hitRecord;

struct sphere {
	struct vec3 center;
	double radius;
	struct material mat;
};


int intersectSphere(struct sphere *S, struct ray *R, double tmin, double tmax, struct hitRecord *HR);

#endif
