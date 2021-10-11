#ifndef RTCAMERA_H
#define RTCAMERA_H
#include "rays.h"

struct camera{
	struct vec3 origin;
	struct vec3 llcorner;
	struct vec3 horizontal;
	struct vec3 vertical;
};

struct camera initCam(double aspectRatio, double vpHeight, double vpWidth, double focalDistance);

struct ray newRay(struct camera cam, double u, double v);

#endif
