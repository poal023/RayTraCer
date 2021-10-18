#include "material.h"

int scatter(struct ray* R, struct hitRecord* HR, struct vec3* attenuation, struct ray* scattered){
	struct material* currMat = HR->mat;
	struct ray tempRay;
	switch(currMat->mType){
		case(MAT_LAMB):
			struct vec3 scatterDir = vecAddition(HR->normalVec, randomUnitVector());
			if(allNearZero(scatterDir)){
				scatterDir = HR->normalVec;
			}
			tempRay = (struct ray){.origin = HR->point, .direction = scatterDir};
			memcpy(scattered, &tempRay, sizeof(*scattered));
			memcpy(attenuation, &currMat->lambertian.albedo, sizeof(*scattered));
			return 1;

		case(MAT_METAL):
			if(currMat->metal.fuzz >= 1){
				currMat->metal.fuzz = 1;
			}
			struct vec3 reflected = reflection(unitVec(R->direction), HR->normalVec);
			tempRay = (struct ray){.origin = HR->point, .direction = vecAddition(reflected, scalarMultiplication(randomVectorInUnitSphere(),currMat->metal.fuzz))};
			memcpy(scattered, &tempRay, sizeof(*scattered));
			memcpy(attenuation, &currMat->metal.albedo, sizeof(*scattered));
			return (dotProduct(scattered->direction, HR->normalVec) > 0);
	}

}

