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
    float a, b, c;
    a = pow(r.direction.x,2) + pow(r.direction.y,2) + pow(r.direction.z,2);
    b = 2*((r.start.x - center.x)*r.direction.x + (r.start.y - center.y)*r.direction.y + (r.start.z - center.z)*r.direction.z);
    c = pow(r.start.x - center.x,2) + pow(r.start.y - center.y,2) + pow(r.start.z - center.z,2) - pow(radius,2);
    
    float discriminant = pow(b,2) - 4*a*c;

    if (discriminant < 0.0) {
        return NULL;
    } else if (discriminant == 0.0) {
        float t = -b / (2*a);
        return r.InterpolatedRay(t);
    } else {
        float t1 = (-b - sqrt(discriminant)) / (2*a);
        float t2 = (-b + sqrt(discriminant)) / (2*a);
        if (r.invalidT(t1) && !r.invalidT(t2)) return r.InterpolatedRay(t2);
        if (!r.invalidT(t1) && r.invalidT(t2)) return r.InterpolatedRay(t1);
        return r.InterpolatedRay(fmin(t1,t2));

    }
}