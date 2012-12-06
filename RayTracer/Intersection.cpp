//
//  Intersection.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Intersection.h"

Intersection::Intersection(float time, STVector3 intersect_pt, STVector3 n, Ray vRay){
    t = time;
    pt = STVector3(intersect_pt);
    normal = n; //s.CalcNormal(intersect_pt);
    viewingRay = vRay;
    
}