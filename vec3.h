#ifndef VEC3_H
#define VEC3_H

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

double vecMagnitude(struct vec3 Vector);
#endif
