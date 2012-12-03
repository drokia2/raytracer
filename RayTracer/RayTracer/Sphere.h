//
//  Sphere.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__Sphere__
#define __RayTracer__Sphere__

#include <iostream>
#include "Shape.h"
#include "Ray.h"
#include "stgl.h"
#include "RayIntersection.h"

class Sphere: public Shape
{
public:
	Sphere(float r,const STPoint3& c);
    
    RayIntersection * IntersectsRay(Ray r);
    STVector3 CalcNormal(STVector3 surface_pt); // not normalized

    
    
	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    
    // gen viewing rays
private:
    float radius;
    STVector3 center;

    
    
};


#endif /* defined(__RayTracer__Sphere__) */
