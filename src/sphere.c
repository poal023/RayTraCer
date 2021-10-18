#include "sphere.h"

int intersectSphere(struct sphere *S, struct ray *R, double tMin, double tMax, struct hitRecord* HR){
	struct vec3 dist = vecSubtraction(R->origin, S->center); //Distance Vector, from the origin of our ray to the center of the sphere.
	

	double a = dotProduct(R->direction, R->direction);
	double b = 2.0 * dotProduct(dist, R->direction);
	double c = (dotProduct(dist, dist)) - (S->radius * S->radius);
	
	double discriminant = (b * b) - (4 * a * c); //Tells us if we do indeed have real roots (ie possible intersections)
	
	if(discriminant < 0) //if there is no intersection, don't even bother
		return 0;
	
	double t1 = (-b + sqrt(discriminant)) / (2 * a);
	double t2 = (-b - sqrt(discriminant)) / (2 * a);
	if((t1 > tMin && t1 < tMax) && (t2 > tMin && t2 < tMax)){
		HR->t = min(t1,t2);
		HR->point = pointAlongRay(R, HR->t);
		HR->normalVec = scalarDivision(vecSubtraction(HR->point, S->center), S->radius);
		HR->mat = &S->mat;
		if(dotProduct(R->direction, HR->normalVec) > 0.0){
			HR->normalVec = scalarMultiplication(HR->normalVec, -1);
		}

		return 1;
	}

	return 0;
}
