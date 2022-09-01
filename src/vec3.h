#ifndef VEC3_H
#define VEC3_H
#include "utils.h"

struct vec3{
    double x,y,z;
};

struct vec3 scalarMultiplication(struct vec3 Vector, double k);
struct vec3 scalarDivision(struct vec3 Vector, double k);

struct vec3 vecAddition(struct vec3 V1, struct vec3 V2);
struct vec3 vecSubtraction(struct vec3 V1, struct vec3 V2);
struct vec3 vecMultiplication(struct vec3 V1, struct vec3 V2);
struct vec3 vecDivision(struct vec3 V1, struct vec3 V2);

double dotProduct(struct vec3 V1, struct vec3 V2);
struct vec3 crossProduct(struct vec3 V1, struct vec3 V2);
struct vec3 unitVec(struct vec3 Vector);

struct vec3 randomVectorInUnitSphere();
struct vec3 randomVectorInRange(double min, double max);
struct vec3 randomVector();
struct vec3 randomUnitVector();

int allNearZero(struct vec3 Vector);
struct vec3 reflection(struct vec3 Vector, struct vec3 unit);
struct vec3 refraction(struct vec3 refRay, struct vec3 normal, double etaEtaPrimeRatio);

double lengthSquared(struct vec3 Vector);
double vecMagnitude(struct vec3 Vector);
#endif
