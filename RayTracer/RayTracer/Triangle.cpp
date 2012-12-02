//
//  Triangle.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Triangle.h"

Triangle::Triangle(const STPoint3& one, const STPoint3& two, const STPoint3& three){
    v1 = STVector3(one.x, one.y, one.z);
    v2 = STVector3(two.x, two.y, two.z);
    v3 = STVector3(three.x, three.y, three.z);
    
}

STVector3 * Triangle::IntersectsRay(Ray r) {
    printf("TODO: implement Sphere::IntersectsRay\n");
    return false;
}