//
//  OcclusionRay.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//



#include "OcclusionRay.h"
OcclusionRay::OcclusionRay(STVector3 s, STVector3 end, float ep){
    start = s;
    direction = end - s;
//    float l = direction.Length();
//    direction.Normalize();
    minT = ep;
    maxT = 1.0;
}

OcclusionRay OcclusionRay::TransformRay(STTransform4 transMatrix) {
    STTransform4 invTransMatrix = transMatrix.Inverse();
    STVector3 startTransformed = STVector3(invTransMatrix * STPoint3(start));
    STVector3 dirTransformed = invTransMatrix * direction;
    OcclusionRay newRay = OcclusionRay(startTransformed,  startTransformed + dirTransformed, minT);
    return newRay;
}