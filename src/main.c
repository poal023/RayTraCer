#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vec3.h"
#include "rays.h"
#include "sphere.h"
#include "utils.h"
#include "camera.h"
#include "scene.h"
#include "material.h"


void beginSceneA(struct scene* sc){	
    sc->numObjects = 4;
    sc->spheres = calloc(sizeof(struct sphere), 4);
    sc->spheres[0] = (struct sphere){.center = {0,0,-1}, .radius = 0.5, .mat = {.lambertian = {0.7,0.3,0.3}, .mType = MAT_LAMB}};
    sc->spheres[1] = (struct sphere){.center = {0,-100.5,-1}, .radius = 100, .mat = {.lambertian = {0.8,0.8,0}, .mType = MAT_LAMB}};
    sc->spheres[2] = (struct sphere){.center = {-1,0,-1}, .radius = 0.5, .mat = {.metal = {.albedo = {0.8,0.8,0.8}, .fuzz = 0.3}, .mType = MAT_METAL}};
    sc->spheres[3] = (struct sphere){.center = {1,0,-1}, .radius = 0.5, .mat = {.metal = {.albedo = {0.8,0.6,0.2}, .fuzz = 1.0}, .mType = MAT_METAL}};
}

void beginSceneB(struct scene* sc){	
    sc->numObjects = 3;
    sc->spheres = calloc(sizeof(struct sphere), 3);
    sc->spheres[0] = (struct sphere){.center = {0.75,0,-0.85}, .radius = 0.4, .mat = {.lambertian = {0.2,0.7,0.3}, .mType = MAT_LAMB}};
    sc->spheres[1] = (struct sphere){.center = {0,-100.5,-1}, .radius = 100, .mat = {.lambertian = {0.2,0.2,0.6}, .mType = MAT_METAL}};
    sc->spheres[2] = (struct sphere){.center = {0,0,-1}, .radius = 0.32, .mat = {.metal = {.albedo = {0.2,0.8,0.8}, .fuzz = 0.2}, .mType = MAT_METAL}};
}


int anySceneIntersection(struct ray *r, struct scene *sc, double tMin, double tMax, struct hitRecord* HR){
	double closest = tMax;
	struct hitRecord tempRec;
	int hitFlag = 0;
	for(int i = 0; i < sc->numObjects; i++){
		if(intersectSphere(&sc->spheres[i], r, EPSILON, closest, &tempRec)){
			hitFlag = 1;
			closest = tempRec.t;
			memcpy(HR, &tempRec, sizeof(tempRec));
		}
	}
	return hitFlag;
}

struct vec3 ray_color(struct ray *r, struct scene* sc, int maxRecursionDepth) {
	struct hitRecord HR;
	if(maxRecursionDepth <= 0){
		return (struct vec3){0,0,0};
	}

   	if(anySceneIntersection(r, sc, EPSILON, INF, &HR)){
		//struct vec3 target = vecAddition(vecAddition(HR.point, HR.normalVec), randomUnitVector());
		//return scalarMultiplication(ray_color(&(struct ray){.origin = HR.point, .direction = vecSubtraction(target, HR.point)}, sc ,maxRecursionDepth - 1), 0.5);

		struct ray scattered;
		struct vec3 attenuation;
		if(scatter(r, &HR, &attenuation, &scattered)){
			return vecMultiplication(attenuation, ray_color(&scattered, sc, maxRecursionDepth - 1));
		}else{
			return (struct vec3) {0,0,0};
		}
	
		//return scalarMultiplication(vecAddition(HR.normalVec, (struct vec3){1,1,1}), 0.5);
	} 
	double t = 0.5*(unitVec(r->direction).y + 1.0);
	return vecAddition(scalarMultiplication((struct vec3){1.0, 1.0, 1.0},(1.0-t)), scalarMultiplication((struct vec3){0.5, 0.7, 1.0}, t));
}

void writeColor(struct vec3 pColor, int samplesPerPixel){
	double scale = 1.0 / samplesPerPixel;

	double red = sqrt(pColor.x * scale);
	double green = sqrt(pColor.y * scale);
	double blue = sqrt(pColor.z * scale);
	
	printf("%d %d %d\n", (int)(256 * clamp(red, 0.0, 0.999)), (int)(256 * clamp(green, 0.0, 0.999)), (int)(256 * clamp(blue, 0.0, 0.999)));

}

int main(int argc, char *argv[]){
    
    const double aspect_ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int)(width / aspect_ratio);
    int samplesPerPixel = 100;
    int maxRecursionDepth = 50;

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;
    
    struct camera cam = initCam(aspect_ratio, viewport_height, viewport_width, focal_length);
    struct scene sc;
    beginSceneA(&sc);

    printf("P3\n%d %d\n255\n", width, height);

    for(int i = height-1; i >= 0; i--){
        for(int j = 0; j < width; j++){
		struct vec3 p_col = {.x = 0, .y = 0, .z = 0};
        	for(int s = 0; s < samplesPerPixel; s++){
			
			double u = (double)(i + randomDouble()) / (height - 1);
			double v = (double)(j + randomDouble()) / (width - 1);

			struct ray tempRay = newRay(cam, u, v);
			/*tempRay.origin = origin;
			  tempRay.direction = vecAddition(llcorner, scalarMultiplication(horizontal, v));
			  tempRay.direction = vecAddition(tempRay.direction, scalarMultiplication(vertical, u));
			  tempRay.direction = vecSubtraction(tempRay.direction, origin);*/

			p_col = vecAddition(p_col, ray_color(&tempRay, &sc, maxRecursionDepth));

		}
			writeColor(p_col, samplesPerPixel);
	}

    }
    free(sc.spheres);
}
