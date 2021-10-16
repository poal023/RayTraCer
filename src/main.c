#include <stdio.h>
#include <stdlib.h>
#include "vec3.h"
#include "rays.h"
#include "sphere.h"
#include "utils.h"
#include "camera.h"

struct vec3 ray_color(struct ray *r) {
	struct sphere S;
   	S.center = (struct vec3){0,0,-1};
	S.radius = 0.5555;
	double t;
	if(intersectSphere(&S, r, EPSILON, INF)){
		struct vec3 normal = unitVec(vecSubtraction(pointAlongRay(r,t), S.center));
		return scalarMultiplication((struct vec3){normal.x + 1, normal.y + 1, normal.z + 1}, 0.5);
	} else if(intersectSphere(&(struct sphere){.center = {0,-100.5,-1}, .radius = 100.0}, r, EPSILON, INF)){
        struct vec3 normal = unitVec(vecSubtraction(pointAlongRay(r,t), (struct vec3){0,-100.5,-1}));
        return scalarMultiplication((struct vec3){normal.x + 1, normal.y + 1, normal.z + 1}, 0.5);
    }
	t = 0.5*(unitVec(r->direction).y + 1.0);
	return vecAddition(scalarMultiplication((struct vec3){1.0, 1.0, 1.0},(1.0-t)), scalarMultiplication((struct vec3){0.5, 0.7, 1.0}, t));
}

int main(int argc, char *argv[]){
    
    const double aspect_ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = (int)(width / aspect_ratio);
    
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;
    
    /*struct vec3 origin = {0, 0, 0};
    struct vec3 horizontal = {viewport_width, 0, 0};
    struct vec3 vertical = {0, viewport_height, 0};
    
    struct vec3 llcorner = vecSubtraction(origin, scalarDivision(horizontal, 2));
    llcorner = vecSubtraction(llcorner, scalarDivision(vertical, 2));
    llcorner = vecSubtraction(llcorner, (struct vec3){0,0,focal_length});*/
    
    struct camera cam = initCam(aspect_ratio, viewport_height, viewport_width, focal_length);
    
   
    
    printf("P3\n%d %d\n255\n", width, height);
    for(int i = height-1; i >= 0; i--){
        for(int j = 0; j < width; j++){
            double u = (double)(i) / (height - 1);
            double v = (double)(j) / (width - 1);
            
            struct ray tempRay = newRay(cam, u, v);
            /*tempRay.origin = origin;
            tempRay.direction = vecAddition(llcorner, scalarMultiplication(horizontal, v));
            tempRay.direction = vecAddition(tempRay.direction, scalarMultiplication(vertical, u));
            tempRay.direction = vecSubtraction(tempRay.direction, origin);*/
            
            struct vec3 p_col = ray_color(&tempRay);
            
            int red = (int)(p_col.x * 255.99);
            int green = (int)(p_col.y * 255.99);
            int blue = (int)(p_col.z * 255.99);
            
            printf("%d %d %d\n", red, green, blue);
        }
    }
}
