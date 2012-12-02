//
//  Sphere.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(float r, const STPoint3& c){
    radius = r;
    center = STVector3(c.x, c.y, c.z);
}

STVector3 *Sphere::IntersectsRay(Ray r) {
    printf("TODO: implement Sphere::IntersectsRay\n");
    return NULL;
}