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
    float l = direction.Length();
    direction.Normalize();
    minT = ep;
    maxT = l;
}
