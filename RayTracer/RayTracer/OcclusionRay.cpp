//
//  OcclusionRay.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//


#define EPSILON .01

#include "OcclusionRay.h"
OcclusionRay::OcclusionRay(STVector3 s, STVector3 end ){
    printf("TODO: Set Shadow bias\n");
    start = s;
    direction = end - s;
    direction.Normalize();
    minT = EPSILON;
    maxT = 1.0;
}
