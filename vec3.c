#include <math.h>
#include "vec3.h"

double dotProduct(struct vec3 V1, struct vec3 V2){
    return (V1.x * V2.x + V1.y * V2.y + V1.z * V2.z);
}

struct vec3 scalarMultiplication(struct vec3 Vector, double k){
    return (struct vec3) {Vector.x * k, Vector.y * k, Vector.z * k};
}

struct vec3 scalarDivision(struct vec3 Vector, double k){
    return (struct vec3) {Vector.x / k, Vector.y / k, Vector.z / k};
}


struct vec3 vecAddition(struct vec3 V1, struct vec3 V2){
    return (struct vec3) {V1.x + V2.x, V1.y + V2.y, V1.z + V2.z};
}

struct vec3 vecSubtraction(struct vec3 V1, struct vec3 V2){
    return (struct vec3) {V1.x - V2.x, V1.y - V2.y, V1.z - V2.z};
}

struct vec3 vecMultiplication(struct vec3 V1, struct vec3 V2){
    return (struct vec3) {V1.x * V2.x, V1.y * V2.y, V1.z * V2.z};
}

struct vec3 vecDivision(struct vec3 V1, struct vec3 V2){
    return (struct vec3) {V1.x / V2.x, V1.y / V2.y, V1.z / V2.z};
}


struct vec3 crossProduct(struct vec3 V1, struct vec3 V2){
    return (struct vec3) {(V1.y * V2.z) - (V1.z * V2.y), (V1.z * V2.x) - (V1.x * V2.z), (V1.x * V2.y) - (V1.y * V2.x)};
}

double vecMagnitude(struct vec3 Vector){
    return sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y) + (Vector.z * Vector.z));
}

struct vec3 unitVec(struct vec3 Vector){
    double vMag = vecMagnitude(Vector);
    return scalarDivision(Vector, vMag);
}
