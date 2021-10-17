#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vec3.h"
#include "rays.h"
#include "sphere.h"
#include "utils.h"
#include "camera.h"
#include "scene.h"

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

struct vec3 ray_color(struct ray *r, struct scene* sc) {
	struct hitRecord HR;
   	if(anySceneIntersection(r, sc, EPSILON, INF, &HR)){
		return scalarMultiplication(vecAddition(HR.normalVec, (struct vec3){1,1,1}), 0.5);
	} 
	double t = 0.5*(unitVec(r->direction).y + 1.0);
	return vecAddition(scalarMultiplication((struct vec3){1.0, 1.0, 1.0},(1.0-t)), scalarMultiplication((struct vec3){0.5, 0.7, 1.0}, t));
}

void writeColor(struct vec3 pColor, int samplesPerPixel){
	double scale = 1.0 / samplesPerPixel;

	double red = pColor.x * scale;
	double green = pColor.y * scale;
	double blue = pColor.z * scale;
	
	printf("%d %d %d\n", (int)(256 * clamp(red, 0.0, 0.999)), (int)(256 * clamp(green, 0.0, 0.999)), (int)(256 * clamp(blue, 0.0, 0.999)));

}

int main(int argc, char *argv[]){
    
    const double aspect_ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int)(width / aspect_ratio);
    int samplesPerPixel = 100;


    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;
    
    struct camera cam = initCam(aspect_ratio, viewport_height, viewport_width, focal_length);
    struct scene sc;
    sc.numObjects = 2;
    sc.spheres = calloc(sizeof(struct sphere), 2);
    sc.spheres[0] = (struct sphere){.center = {0,0,-1}, .radius = 0.5};
    sc.spheres[1] = (struct sphere){.center = {0,-100.5,-1}, .radius = 100.5};
    
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

			p_col = vecAddition(p_col, ray_color(&tempRay, &sc));

		}
			writeColor(p_col, samplesPerPixel);
	}

    }
    free(sc.spheres);
}
