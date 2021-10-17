#ifndef SCENE_H
#define SCENE_H
#include "sphere.h"

struct scene{
    size_t numObjects;
    struct sphere* spheres;
};

#endif
