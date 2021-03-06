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
#include "Intersection.h"

class Sphere: public Shape
{
public:
	Sphere(float r,const STPoint3& c);
    
    Intersection * IntersectsRay(Ray r, STTransform4 transMatrix);
    STVector3 CalcNormal(STVector3 surface_pt, Ray unused); // not normalized

    
    
	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    
    // gen viewing rays
private:
    float radius;
    STVector3 center;

    
    
};


#endif /* defined(__RayTracer__Sphere__) */
