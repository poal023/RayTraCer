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

double lengthSquared(struct vec3 Vector){
	return (Vector.x * Vector.x) + (Vector.y * Vector.y) + (Vector.z * Vector.z);
}


struct vec3 crossProduct(struct vec3 V1, struct vec3 V2){
    return (struct vec3) {(V1.y * V2.z) - (V1.z * V2.y), (V1.z * V2.x) - (V1.x * V2.z), (V1.x * V2.y) - (V1.y * V2.x)};
}

double vecMagnitude(struct vec3 Vector){
    return sqrt(lengthSquared(Vector));
}

struct vec3 unitVec(struct vec3 Vector){
    double vMag = vecMagnitude(Vector);
    return scalarDivision(Vector, vMag);
}

struct vec3 randomVector(){
	return (struct vec3){.x = randomDouble(), .y = randomDouble(), .z = randomDouble()};
}

struct vec3 randomVectorInRange(double min, double max){
	return (struct vec3){.x = randomDoubleInRange(min, max), .y = randomDoubleInRange(min, max), .z = randomDoubleInRange(min, max)};
}

struct vec3 randomVectorInUnitSphere(){
	while(1){
		struct vec3 rVec = randomVectorInRange(-1.0,1.0);
		if(lengthSquared(rVec) >= 1.0){
			continue;
		} else {
			return rVec;
		}
	}
}

struct vec3 randomUnitVector(){
	return unitVec(randomVectorInUnitSphere());
}


int allNearZero(struct vec3 Vector){
	return ((Vector.x < EPSILON) && (Vector.y < EPSILON) && (Vector.z < EPSILON));
}

struct vec3 reflection(struct vec3 Vector, struct vec3 unit){
	return vecSubtraction(Vector, scalarMultiplication(scalarMultiplication(unit,dotProduct(Vector,unit)),2));
}

struct vec3 refraction(struct vec3 refRay, struct vec3 normal, double etaEtaPrimeRatio){
	double cost = min(dotProduct(scalarMultiplication(refRay, -1), normal), 1.0);
	struct vec3 refRayPerpen = scalarMultiplication(vecAddition(refRay, scalarMultiplication(normal, cost)), etaEtaPrimeRatio);
	struct vec3 refRayParallel = scalarMultiplication(normal, -1*sqrt(1 - lengthSquared(refRayPerpen)));
	return vecAddition(refRayPerpen , refRayParallel);
}
