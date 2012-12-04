//
//  Shape.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__Shape__
#define __RayTracer__Shape__

#include <iostream>
#include "stgl.h"
#include "Ray.h"
#include "RayIntersection.h"

class Shape
{
public:
	Shape();
    
    virtual RayIntersection * IntersectsRay(Ray r)=0;
    
    virtual STVector3 CalcNormal(STVector3 surface_pt, Ray r)=0;
    
    
	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    
    // gen viewing rays
private:
    
     
    
    
};


#endif /* defined(__RayTracer__Shape__) */
