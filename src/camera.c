#include "camera.h"


struct camera initCam(double aspectRatio, double vpHeight, double vpWidth, double focalDistance){
    struct camera newCam;
    newCam.origin = (struct vec3){0, 0, 0};
    newCam.horizontal = (struct vec3){vpWidth, 0, 0};
    newCam.vertical = (struct vec3){0, vpHeight, 0};
    newCam.llcorner = vecSubtraction(newCam.origin, scalarDivision(newCam.horizontal, 2));
    newCam.llcorner = vecSubtraction(newCam.llcorner, scalarDivision(newCam.vertical, 2));
    newCam.llcorner = vecSubtraction(newCam.llcorner, (struct vec3){0,0,focalDistance});
    return newCam;
}

struct ray newRay(struct camera cam, double u, double v){
    struct ray currRay;
    currRay.origin = cam.origin;
    currRay.direction = vecAddition(cam.llcorner, scalarMultiplication(cam.horizontal, v));
    currRay.direction = vecAddition(currRay.direction, scalarMultiplication(cam.vertical, u));
    currRay.direction = vecSubtraction(currRay.direction, currRay.origin);
    return currRay;
}
