//
//  Ray.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Ray.h"

Ray::Ray(STVector3 start, STVector3 end )
{
    startPt = start;
    endPt = end;
    printf("TODO: Ray::Ray calc min and max T");
    minT = 0;
    maxT = 100;
    
}

bool Ray::invalidT(float t) {
    return t < minT || t > maxT;
}

STVector3 Ray::InterpolatedRay(float t) {
    if (invalidT(t)) {
        printf("Ray.cpp: invalid t\n");
        exit(0);
    }
    return startPt + t * endPt;
}