#include "rays.h"

struct vec3 pointAlongRay(struct ray *R, double t){
    return vecAddition(scalarMultiplication(R->direction, t), R->origin);
}
