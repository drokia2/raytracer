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

STVector3 Sphere::CalcNormal(STVector3 surface_pt, Ray unused){
    STVector3 v = surface_pt - center;
    v.Normalize();
    return v;
}

RayIntersection *Sphere::IntersectsRay(Ray r, STTransform4 transMatrix) {
    r = r.TransformRay(transMatrix);
    float a, b, c;
    a = pow(r.direction.x,2) + pow(r.direction.y,2) + pow(r.direction.z,2);
    b = 2*((r.start.x - center.x)*r.direction.x + (r.start.y - center.y)*r.direction.y + (r.start.z - center.z)*r.direction.z);
    c = pow(r.start.x - center.x,2) + pow(r.start.y - center.y,2) + pow(r.start.z - center.z,2) - pow(radius,2);
    
    float discriminant = pow(b,2) - 4*a*c;

    if (discriminant < 0.0) {
        return NULL;
    } else if (discriminant == 0.0) {
        float t = -b / (2*a);
        if (r.invalidT(t)) {
            return NULL;
        }
        //TODO: transform back to world coordinates
        STVector3 normal = CalcNormal(*(r.InterpolatedRay(t)), r);
        RayIntersection *rt = new RayIntersection(t, *(r.InterpolatedRay(t)), normal);
        return rt;
    } else {
        float t1 = (-b - sqrt(discriminant)) / (2*a);
        float t2 = (-b + sqrt(discriminant)) / (2*a);
        
        if (r.invalidT(t1) && !r.invalidT(t2)) {
            //TODO: transform back to world coordinates

            STVector3 ray = transMatrix * (*(r.InterpolatedRay(t2)));
            STVector3 normal = transMatrix.Inverse().Transpose() *CalcNormal(ray, r);
            RayIntersection *rt = new RayIntersection(t2, ray, normal);
            return rt;
        }
        
        if (!r.invalidT(t1) && r.invalidT(t2)) {
            // transform back to world coordinates
            STVector3 ray = transMatrix * (*(r.InterpolatedRay(t1)));
            STVector3 normal = transMatrix.Inverse().Transpose() *CalcNormal(ray, r);
            RayIntersection *rt = new RayIntersection(t1, ray, normal);
            return rt;
        }
        
        if (r.invalidT(t1) && r.invalidT(t2)) {
            return NULL;
        }
        //transform back to world coordinates

        STVector3 ray = transMatrix * (*(r.InterpolatedRay(fmin(t1,t2))));
        STVector3 normal = transMatrix.Inverse().Transpose() * CalcNormal(ray, r);
        RayIntersection *rt = new RayIntersection(fmin(t1,t2), ray, normal);
        return rt;
    }
}