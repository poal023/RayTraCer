#ifndef MAT_H
#define MAT_H
#include "utils.h"
#include "hittable.h"

struct hitRecord;

struct material{
	union{
		struct lambertian{
			struct vec3 albedo;
		} lambertian;
		struct metal{
			struct vec3 albedo;
			double fuzz;
		} metal;
		struct dielectric{
			double refractionIndex;
		} dielectric;
	};
	enum matSelect{MAT_LAMB, MAT_METAL, MAT_DIE} mType;
};

int scatter(struct ray* R, struct hitRecord* HR, struct vec3* attenuation, struct ray* scattered);

#endif
