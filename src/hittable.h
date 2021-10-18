#ifndef HITTABLE_H
#define HITTABLE_H
#include "utils.h"
#include "material.h"
#include "rays.h"


struct hitRecord{
	struct vec3 point;
	struct vec3 normalVec;
	double t;
	struct material* mat;
};


#endif
